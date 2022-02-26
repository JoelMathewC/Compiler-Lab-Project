%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	
	void yyerror(char const *s);
	int yylex(void);
	extern FILE* yyin;
	
	#include "data_structures/defn.h"
	#include "data_structures/labelAddrTable.h"
	#include "data_structures/loopStack.h"
	#include "data_structures/typeTable.h"
	#include "data_structures/classTable.h"
	#include "data_structures/symbolTable.h"
	#include "data_structures/tNode.h"
	#include "data_structures/dNode.h"
	#include "data_structures/paramStruct.h"
	#include "backend/globalVar.h"
	
	#include "functions/dNodeFunc.h"
	#include "functions/tNodeFunc.h"
	#include "functions/paramStructFunc.h"
	#include "functions/labelAddrTableFunc.h"
	#include "functions/loopStackFunc.h"
	#include "functions/typeTableFunc.h"
	#include "functions/classTableFunc.h"
	#include "functions/symbolTableFunc.h"
	
	#include "functions/dNodeFunc.c"
	#include "functions/tNodeFunc.c"
	#include "functions/paramStructFunc.c"
	#include "functions/labelAddrTableFunc.c"
	#include "functions/loopStackFunc.c"
	#include "functions/typeTableFunc.c"
	#include "functions/classTableFunc.c"
	#include "functions/symbolTableFunc.c"
	#include "backend/globalVar.c"
	
	#include "backend/code_gen.h"
	#include "backend/code_gen.c"
	
	struct GSymbolTable* gst;
	struct LSymbolTable* lst;
	struct TypeTable* typeTable;
	struct ClassTable* classTable;
	
	
	void startCodeGen(FILE* fp, int memLoc, struct GSymbolTable* gst, struct ClassTable* classTable);
	FILE* openFile();
	FILE *fp;
	
	char* currentClass;
	void endCodeGen(FILE *fp);
	void setMemLocationValues(struct GSymbolTable* gst,struct ClassTable* classTable, FILE* fp);
%}

%union{
	struct tnode *no;
	struct dnode *dno;
	struct ParamStruct *pt;
	struct ArgStruct *at;
	int number;
	char* string;
	int* seq;
	
}

%type <at> ArgList
%type <pt> Param ParamList
%type <no> program MainBlock FdefBlock Fdef 
%type <dno> GdeclBlock GdeclList Gdecl GidList Gid LdeclBlock LdeclList Ldecl LidList Lid IdentifierDecl IdArrDecl GtypeDeclList GtypeDecl GtypeIdList GclassDeclBlock GclassAttrDeclList GclassAttrDecl GclassIdList GclassFuncDeclList GclassFuncDecl GclassFuncName
%type <no> Slist Stmt InputStmt OutputStmt AssgStmt expr LoopStmt IfStmt Identifier IdArr StructId
%type <string> Type TupleType FuncRetType LocalType

%token MAIN
%token ID NUM STRING
%token STR INT VOID NULL_TYPE TUPLE
%token PLUS MINUS STAR DIV MOD ASSIGN GT GTE LT LTE EQ NEQ ADDR AND OR
%token START END ENDSTMT DECL ENDDECL TYPE ENDTYPE CLASS ENDCLASS
%token READ WRITE ALLOC INITIALIZE FREE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL
%token BREAK CONTINUE RETURN

%nonassoc AND OR
%nonassoc GT GTE LT LTE EQ NEQ
%left PLUS MINUS
%left STAR DIV MOD
%right ADDR


%%

program : GtypeBlock GclassBlock GdeclBlock FdefBlock MainBlock	{}
	| GtypeBlock GclassBlock GdeclBlock MainBlock			{}
	| GclassBlock GdeclBlock FdefBlock MainBlock			{}
	| GclassBlock GdeclBlock MainBlock				{}
	| GtypeBlock GdeclBlock FdefBlock MainBlock			{}
	| GtypeBlock GdeclBlock MainBlock				{}
	| GtypeBlock MainBlock						{}
	| GdeclBlock FdefBlock MainBlock				{}
	| GdeclBlock MainBlock						{}
	| MainBlock							{}
	;
	
GclassBlock : CLASS GclassList ENDCLASS			{/*printClassTable(classTable);*/printf("CLASS DONE\n");}
	| CLASS ENDCLASS					{}
	;

GclassList : GclassList Gclass				{}
	| Gclass						{}
	;

Gclass : ClassName '{' GclassDeclBlockSeg GclassFuncDefBlock '}'		{}
	| ClassName '{' GclassDeclBlockSeg '}'				{}
	;
	
ClassName : ID									{
											currentClass = strdup($<string>1);
											$<string>$ = $<string>1;
										}
	;

GclassDeclBlockSeg : GclassDeclBlock						{	
											getMemLoc(8);
											addToClassTable(classTable, typeTable, $1, currentClass);

										}
			;

GclassDeclBlock : DECL GclassAttrDeclList GclassFuncDeclList ENDDECL		{$$ = makeDConnectorNode($2,$3);}
		| DECL GclassFuncDeclList ENDDECL				{$$ = makeDConnectorNode(NULL,$2);}
		| DECL GclassAttrDeclList ENDDECL				{$$ = makeDConnectorNode($2,NULL);}
		;

GclassAttrDeclList : GclassAttrDeclList GclassAttrDecl		{$$ = makeDConnectorNode($1,$2);}
	| GclassAttrDecl						{$$ = $1;}
	;

GclassAttrDecl : Type GclassIdList ENDSTMT			{$$ = makeDatatypeNode($1,$2);}
	;

GclassIdList : GclassIdList ',' ID			{$$ = makeDConnectorNode($1,declIdNode($<string>1,0,NULL));}	
	| ID						{$$ = declIdNode($<string>1,0,NULL);}
	;
	
GclassFuncDeclList : GclassFuncDeclList GclassFuncDecl		{$$ = makeDConnectorNode($1,$2);}
	| GclassFuncDecl						{$$ = $1;}
	;

GclassFuncDecl : Type GclassFuncName ENDSTMT			{$$ = makeDatatypeNode($1,$2);}
	;

GclassFuncName : ID '(' ParamList ')'				{$$ = declFuncNode($<string>1,$3);}
	;
	
GclassFuncDefBlock : GclassFuncDefBlock GclassFuncDef		{}
	| GclassFuncDef						{}
	;

GclassFuncDef : MName '{' LdeclBlock START Slist END '}'		{	
										
										struct ClassTableEntry* entry = CLookup(classTable,currentClass);
										struct MethodList* method = MLookup(entry -> methodList,$<string>1);
										funcCodeGen($5, fp,method -> flabel);
										lst = NULL;
									}
	;

MName : Type ID '(' ParamList ')'			{	
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyMethodHead($<string>2,$4,TLookup(typeTable,$<string>1),CLookup(classTable,currentClass));
								addMethodParamToLST(lst,$4,CLookup(classTable,currentClass));
								$<string>$ = $<string>2;
							}
	;
	
GtypeBlock : TYPE GtypeList ENDTYPE			{printf("TYPE DONE\n");}
	| TYPE ENDTYPE					{}
	;

GtypeList : GtypeList Gtype				{}
	| Gtype					{}
	;

Gtype : ID '{' GtypeDeclList '}'			{addUserDefToTypeTable(typeTable,$3,$<string>1);}
	;

GtypeDeclList : GtypeDeclList GtypeDecl		{$$ = makeDConnectorNode($1,$2);}
	| GtypeDecl					{$$ = $1;}
	;

GtypeDecl : Type GtypeIdList ENDSTMT			{$$ = makeDatatypeNode($1,$2);}
	;

GtypeIdList : GtypeIdList ',' ID			{$$ = makeDConnectorNode($1,declIdNode($<string>1,0,NULL));}	
	| ID						{$$ = declIdNode($<string>1,0,NULL);}
	;

	
GdeclBlock : DECL GdeclList ENDDECL 	{	
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,$2,NULL,NULL,typeTable,classTable);
						startCodeGen(fp,memLoc,gst,classTable);
						//printGlobalSymbolTable(gst);
					}
	| DECL ENDDECL			{gst = NULL;}
	;
	
GdeclList : GdeclList Gdecl		{$$ = makeDConnectorNode($1,$2);}
	| Gdecl			{$$ = $1;}
	;
	
Type : INT				{$$ = $<string>1;}
	| STR				{$$ = $<string>1;}
	| VOID				{$$ = $<string>1;}
	| ID				{$$ = $<string>1;}
	| TupleType			{$$ = $<string>1;}
	;
	
TupleType : TUPLE ID '(' ParamList ')'	{addTupleToTypeTable(typeTable,$4,$<string>2);$$ = $<string>2;}
	;

Gdecl : Type GidList ENDSTMT			{$$ = makeDatatypeNode($1,$2);}
	;

GidList : GidList ',' Gid				{$$ = makeDConnectorNode($1,$3);}	
	| Gid						{$$ = $1;}
	;
	
Gid : IdentifierDecl					{$$ = $1;}
	| ID '(' ParamList ')'				{$$ = declFuncNode($<string>1,$3);}
	;
	
IdentifierDecl: STAR IdentifierDecl		{$$ = declIdNode($2 -> varname,$2 -> dim + 1,$2 -> shape);}
	| IdArrDecl				{$$ = $1;}
	;
	
IdArrDecl : IdArrDecl '[' NUM ']'		{$$ = declIdNode($1 -> varname,$1 -> dim + 1,addArrayShape($1 -> shape,$<number>3));}
	| ID					{$$ = declIdNode($<string>1,0,NULL);}	
	;

FdefBlock : FdefBlock Fdef				{}
	| Fdef						{}
	;

Fdef : FName '{' LdeclBlock START Slist END '}'		{	
									struct Gsymbol* g = GlobalLookup(gst,$<string>1);
									funcCodeGen($5, fp,g -> flabel);
									lst = NULL;
								}
	;

FName : FuncRetType ID '(' ParamList ')'			{
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,$<string>2,TLookup(typeTable,$<string>1),CLookup(classTable,$<string>1),$4);
								addParamToLST(lst,$4);
								$<string>$ = $<string>2;
							}
	;

FuncRetType : INT				{$$ = $<string>1;}
	| STR				{$$ = $<string>1;}
	| VOID				{$$ = $<string>1;}
	| ID				{$$ = $<string>1;}
	;

ParamList : ParamList ',' Param			{$$ = addParameter($1,$3);}
	| Param					{$$ = $1;}
	|						{$$ = NULL;}
	;
	
Param : Type ID					{$$ = makeParamStruct($<string>2,$<string>1,0,typeTable,classTable);}
	| Type STAR ID					{$$ = makeParamStruct($<string>3,$<string>1,1,typeTable,classTable);}
	;
	 
MainBlock :  MainHeader '{' LdeclBlock START Slist END'}'	{	
									if(gst == NULL){
										startCodeGen(fp,-1,gst,classTable);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen($5, fp,-1);}
	| MainHeader '{' LdeclBlock START END '}'		{exit(0);}
	;
	
MainHeader : INT MAIN '(' ')'	{lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
	;
	

	
LdeclBlock : DECL LdeclList ENDDECL 	{localMemLoc = 0; addLocalVarToLST(lst,$2,NULL,NULL,typeTable,classTable);}
	| DECL ENDDECL			{$$ = NULL;}
	|				{$$ = NULL;}
	;

LdeclList : LdeclList Ldecl			{$$ = makeDConnectorNode($1,$2);}
	| Ldecl				{$$ = $1;}
	;
	
Ldecl : LocalType LidList ENDSTMT		{$$ = makeDatatypeNode($1,$2);}
	;
	
LocalType : INT				{$$ = $<string>1;}
	| STR					{$$ = $<string>1;}
	| ID					{$$ = $<string>1;}
	;

LidList : LidList ',' Lid		{$$ = makeDConnectorNode($1,$3);}
	| Lid				{$$ = $1;}
	;


Lid : ID						{$$ = declIdNode($<string>1,0,NULL);}
	| STAR ID					{$$ = declIdNode($<string>2,1,NULL);}
	;
	



Slist : Slist Stmt							{$$ = makeConnectorNode($1,$2);}
	| Stmt								{$$ = $1;}
	;
	
Stmt:	InputStmt							{$$ = $1;}
	| OutputStmt							{$$ = $1;}
	| AssgStmt							{$$ = $1;}
	| IfStmt							{$$ = $1;}
	| LoopStmt							{$$ = $1;}
	| BREAK ENDSTMT						{$$ = makeJumpNode(break_node);}
	| CONTINUE ENDSTMT						{$$ = makeJumpNode(continue_node);}
	| ID '(' ')' ENDSTMT						{$$ = makeFuncNode($<string>1,gst,NULL);}
	| ID '(' ArgList ')' ENDSTMT					{$$ = makeFuncNode($<string>1,gst,$3);}
	| StructId '.' ID '(' ')'					{$$ = makeMethodNode($1,$<string>3,NULL,typeTable);}
	| StructId '.' ID '(' ArgList ')'				{$$ = makeMethodNode($1,$<string>3,$5,typeTable);}
	| RETURN expr ENDSTMT						{$$ = makeReturnNode($2);}
	;
	
IfStmt : IF '(' expr ')' THEN Slist ELSE Slist ENDIF	ENDSTMT	{$$ = makeIfElseBlock($3,$6,$8);}
	| IF '(' expr ')' THEN Slist ENDIF ENDSTMT			{$$ = makeIfElseBlock($3,$6,NULL);}
	;
	
LoopStmt : WHILE '(' expr ')' DO Slist ENDWHILE ENDSTMT		{$$ = makeWhileBlock($3,$6);}
	| DO Slist WHILE '(' expr ')' ENDSTMT				{$$ = makeDoWhileBlock($5,$2);}
	| REPEAT Slist UNTIL '(' expr ')' ENDSTMT			{$$ = makeDoWhileBlock($5,$2);}
	;

InputStmt : READ '(' Identifier ')' ENDSTMT				{$$ = makeReadNode($3);}
	;

OutputStmt: WRITE '(' expr ')' ENDSTMT				{$$ = makeWriteNode($3);}
	;

AssgStmt: Identifier ASSIGN expr ENDSTMT				{$$ = makeOperatorNode(assign,$1,$3,typeTable);}
	;

expr : expr PLUS expr							{$$ = makeOperatorNode(add,$1,$3,typeTable);}
	 | expr MINUS expr  						{$$ = makeOperatorNode(sub,$1,$3,typeTable);}
	 | expr STAR expr						{$$ = makeOperatorNode(mul,$1,$3,typeTable);}
	 | expr DIV expr						{$$ = makeOperatorNode(div,$1,$3,typeTable);}
	 | expr MOD expr						{$$ = makeOperatorNode(mod,$1,$3,typeTable);}
	 | expr GT expr						{$$ = makeOperatorNode(gt,$1,$3,typeTable);}
	 | expr GTE expr						{$$ = makeOperatorNode(gte,$1,$3,typeTable);}
	 | expr LT expr						{$$ = makeOperatorNode(lt,$1,$3,typeTable);}
	 | expr LTE expr						{$$ = makeOperatorNode(lte,$1,$3,typeTable);}
	 | expr EQ expr						{$$ = makeOperatorNode(eq,$1,$3,typeTable);}
	 | expr NEQ expr						{$$ = makeOperatorNode(neq,$1,$3,typeTable);}
	 | expr AND expr						{$$ = makeOperatorNode(and,$1,$3,typeTable);}
	 | expr OR expr						{$$ = makeOperatorNode(or,$1,$3,typeTable);}
	 | '(' expr ')'						{$$ = $2;}
	 | NUM								{$$ = makeNumNode($<number>1,0,typeTable);}
	 | MINUS NUM 							{$$ = makeNumNode(-1 * $<number>2,0,typeTable);}
	 | STRING							{$$ = makeStringNode($<string>1,typeTable);}
	 | NULL_TYPE							{$$ = makeNullNode(typeTable);}
	 | ID '(' ')'							{$$ = makeFuncNode($<string>1,gst,NULL);}
	 | ID '(' ArgList ')'						{$$ = makeFuncNode($<string>1,gst,$3);}
	 | Identifier							{$$ = $1;}
	 | ADDR Identifier						{$$ = makeAddrNode($2,gst,lst,typeTable);}
	 | ALLOC '(' ')'						{$$ = makeAllocNode();}
	 | INITIALIZE '(' ')'						{$$ = makeMemInitNode(typeTable);}
	 | FREE '(' Identifier ')'					{$$ = makeFreeNode($3,typeTable);}
	 | StructId '.' ID '(' ')'					{$$ = makeMethodNode($1,$<string>3,NULL,typeTable);}
	 | StructId '.' ID '(' ArgList ')'				{$$ = makeMethodNode($1,$<string>3,$5,typeTable);}
	 ;
	 
ArgList : ArgList ',' expr		{$$ = addArguments($1,makeArgStruct($3),typeTable);}
	| expr				{$$ = makeArgStruct($1);}
	;
	
Identifier : STAR '(' expr ')'		{$$ = makePtrNode($3,typeTable);}
	| STAR Identifier		{$$ = makePtrNode($2,typeTable);}
	| StructId			{$$ = $1;}
	;

StructId : StructId '.' ID			{$$ = extendTypeNode($1,$<string>3,typeTable,classTable);}
	| IdArr				{$$ = $1;}
	;

IdArr : IdArr '[' expr ']'			{$$ = makeIdNode($1 -> varname,gst,lst,addArrayDim($1 -> indices,$3),typeTable,classTable);}
	| ID					{$$ = makeIdNode($<string>1,gst,lst,NULL,typeTable,classTable);}	
	;

%%

void yyerror(char const *s)
{
    printf("yyerror: %s",s);
    exit(0);
}

FILE* openFile(){
	FILE *fp = fopen("output/output.out","w");
	fprintf(fp,"0\nGEN\n0\n0\n0\n0\n0\n0\n");
	return fp;
}

void startCodeGen(FILE* fp, int memLoc, struct GSymbolTable* gst, struct ClassTable* classTable){
	int label1 = getLabel();
	
	fprintf(fp,"GEN:\n");
	//to shift the SP and fill it with 0
	fprintf(fp,"MOV R2, SP\n");
	if(memLoc > 0){
		fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
		fprintf(fp,"L%d:\n",label1);
		fprintf(fp,"ADD R2, 1\n");
		fprintf(fp,"MOV R1, R2\n");
		fprintf(fp,"MOV [R1], 0\n");
		fprintf(fp,"EQ R1, SP\n");
		fprintf(fp,"JZ R1, L%d\n",label1);
	}
	
	fprintf(fp,"ADD SP, 1\n"); //allocate space for return from main
	
	if(gst != NULL)
		setMemLocationValues(gst,classTable,fp);
	fprintf(fp, "CALL MAIN\n");
	fprintf(fp,"CALL EXIT\n");

}

void endCodeGen(FILE *fp){
	fprintf(fp,"EXIT:\n");
	lib_code_gen(end,0,fp);
	fclose(fp);
}

void setMemLocationValues(struct GSymbolTable* gst,struct ClassTable* classTable, FILE* fp){
	reg_index reg1;
	int curr_mem = 0;
	struct Gsymbol* node = gst -> head;
	struct ArrayShape *shape;
	int index1,index2,temp,endFrame;
	
	struct ClassTableEntry* classEntry;
	struct MethodList* method;
	int func_num = 0;
	
	if(classTable != NULL){
		classEntry = classTable -> head;
		while(classEntry != NULL){
			method = classEntry -> methodList;
			func_num = 0;
			
			while(method != NULL){
				fprintf(fp,"MOV R1, %d\n",4096+func_num);
				fprintf(fp,"MOV [R1], F%d\n",method -> flabel);
				method = method -> next;
				++func_num;
			}
			while(func_num == 0 || func_num % 8 != 0){
				fprintf(fp,"MOV R1, %d\n",4096+func_num);
				fprintf(fp,"MOV [R1], -1\n");
				++func_num;
			}
			
			classEntry = classEntry -> next;
		}
	}
	
	while(node != NULL){ // loop through global symbol table
		shape = node -> shape;
		
		if(node -> dtype != NULL && node -> dtype -> nodetype == tupleType){
			fprintf(fp,"MOV R1, %d\n",node -> binding);
			fprintf(fp,"MOV [R1], %d\n", node -> binding + 1);
		}
		else if(node -> dtype != NULL && shape != NULL){
			
			curr_mem = node -> binding;
			index1 = 1;
			
			while(shape != NULL){
			
				index2 = shape -> index;
				endFrame = curr_mem + index1;
				for(int i = 0; i<index1; ++i){
					temp = endFrame + (i * index2);
					fprintf(fp,"MOV R1, %d\n",curr_mem);
					fprintf(fp,"MOV [R1], %d\n", temp);
					curr_mem += 1;
				}
				
				index1 = index1 * index2;
				curr_mem = endFrame;
				shape = shape -> next;

			}
		}else if(node -> ctype != NULL){
			fprintf(fp,"MOV R1, %d\n",node -> binding + 1); //address of func ptr
			fprintf(fp,"MOV [R1], %d\n", 4096 + (node -> ctype -> classIndex * 8));
		}
		node = node -> next;
	}
}

int main(int argc, char* argv[]) {
	
	FILE *input_fp;

	if(argc > 1){
		input_fp = fopen(argv[1],"r");
		fflush(input_fp);
	
		if(input_fp)
			yyin = input_fp;
	}
	
	typeTable = TypeTableCreate();
	classTable = ClassTableCreate();
	fp = openFile();
	yyparse();
	endCodeGen(fp);
	
	if(input_fp)
		fclose(input_fp);
	return 0;
}
