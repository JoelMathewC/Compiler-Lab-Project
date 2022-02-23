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
	#include "functions/symbolTableFunc.h"
	
	#include "functions/dNodeFunc.c"
	#include "functions/tNodeFunc.c"
	#include "functions/paramStructFunc.c"
	#include "functions/labelAddrTableFunc.c"
	#include "functions/loopStackFunc.c"
	#include "functions/typeTableFunc.c"
	#include "functions/symbolTableFunc.c"
	#include "backend/globalVar.c"
	
	#include "backend/code_gen.h"
	#include "backend/code_gen.c"
	
	struct GSymbolTable* gst;
	struct LSymbolTable* lst;
	struct TypeTable* typeTable;
	FILE* startCodeGen(int memLoc, struct GSymbolTable* gst);
	void endCodeGen(FILE *fp);
	void setMemLocationValues(struct GSymbolTable* gst,FILE* fp);
	FILE *fp;
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
%type <dno> GdeclBlock GdeclList Gdecl GidList Gid LdeclBlock LdeclList Ldecl LidList Lid IdentifierDecl IdArrDecl GtypeDeclList GtypeDecl GtypeIdList
%type <no> Slist Stmt InputStmt OutputStmt AssgStmt expr LoopStmt IfStmt Identifier IdArr StructId
%type <string> Type

%token MAIN
%token ID NUM STRING
%token STR INT VOID NULL_TYPE
%token PLUS MINUS STAR DIV MOD ASSIGN GT GTE LT LTE EQ NEQ ADDR AND OR
%token START END ENDSTMT DECL ENDDECL TYPE ENDTYPE
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

program : GtypeBlock GdeclBlock FdefBlock MainBlock	{fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
	| GtypeBlock GdeclBlock MainBlock		{fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
	| GtypeBlock MainBlock				{fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
	| GdeclBlock FdefBlock MainBlock		{fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
	| GdeclBlock MainBlock				{fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
	| MainBlock					{fprintf(fp,"EXIT:\n"); endCodeGen(fp);}
	;
	
GtypeBlock : TYPE GtypeList ENDTYPE			{/*printTypeTable(typeTable);*/}
	| TYPE ENDTYPE					{}
	;

GtypeList : GtypeList Gtype				{}
	| Gtype					{}
	;

Gtype : ID '{' GtypeDeclList '}'			{addToTypeTable(typeTable,$3,$<string>1);}
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
						generateGlobalSymbolTable(gst,$2,NULL,typeTable);
						fp = startCodeGen(memLoc,gst);
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

FName : Type ID '(' ParamList ')'			{
								lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
								verifyFuncHead(gst,$<string>2,TLookup(typeTable,$<string>1),$4);
								addParamToLST(lst,$4);
								$<string>$ = $<string>2;
							}
	;

ParamList : ParamList ',' Param			{$$ = addParameter($1,$3);}
	| Param					{$$ = $1;}
	|						{$$ = NULL;}
	;
	
Param : Type ID					{$$ = makeParamStruct($<string>2,$<string>1,0,typeTable);}
	| Type STAR ID					{$$ = makeParamStruct($<string>3,$<string>1,1,typeTable);}
	;
	 
MainBlock :  MainHeader '{' LdeclBlock START Slist END'}'	{	
									if(gst == NULL){
										fp = startCodeGen(-1,gst);	
										fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
									}
									funcCodeGen($5, fp,-1);}
	| MainHeader '{' LdeclBlock START END '}'		{exit(0);}
	;
	
MainHeader : INT MAIN '(' ')'	{lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));}
	;
	

	
LdeclBlock : DECL LdeclList ENDDECL 	{localMemLoc = 0; addLocalVarToLST(lst,$2,NULL,typeTable);}
	| DECL ENDDECL			{$$ = NULL;}
	|				{$$ = NULL;}
	;

LdeclList : LdeclList Ldecl			{$$ = makeDConnectorNode($1,$2);}
	| Ldecl				{$$ = $1;}
	;
	
Ldecl : Type LidList ENDSTMT		{$$ = makeDatatypeNode($1,$2);}
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
	 ;
	 
ArgList : ArgList ',' expr		{$$ = addArguments($1,makeArgStruct($3));}
	| expr				{$$ = makeArgStruct($1);}
	;
	
Identifier : IdArr			{$$ = $1;}
	| STAR '(' expr ')'		{$$ = makePtrNode($3,typeTable);}
	| STAR Identifier		{$$ = makePtrNode($2,typeTable);}
	| StructId			{$$ = $1;}
	;

StructId : StructId '.' ID			{$$ = extendTypeNode($1,$<string>3,typeTable);}
	| IdArr '.' ID				{$$ = extendTypeNode($1,$<string>3,typeTable);}
	;

IdArr : IdArr '[' expr ']'			{$$ = makeIdNode($1 -> varname,gst,lst,addArrayDim($1 -> indices,$3),typeTable);}
	| ID					{$$ = makeIdNode($<string>1,gst,lst,NULL,typeTable);}	
	;

%%

void yyerror(char const *s)
{
    printf("yyerror: %s",s);
    exit(0);
}

FILE* startCodeGen(int memLoc, struct GSymbolTable* gst){
	FILE *fp = fopen("output/output.out","w");
	fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
	if(memLoc > 0)
		fprintf(fp,"MOV SP, %d\n",memLoc); //statically allocates global variable space
	fprintf(fp,"ADD SP, 1\n"); //allocate space for return from main
	
	if(gst != NULL)
		setMemLocationValues(gst,fp);
	fprintf(fp, "CALL MAIN\n");
	fprintf(fp,"CALL EXIT\n");
	return fp;
}

void endCodeGen(FILE *fp){
	lib_code_gen(end,0,fp);
	fclose(fp);
}

void setMemLocationValues(struct GSymbolTable* gst,FILE* fp){
	reg_index reg1;
	struct Gsymbol* temp = gst -> head;
	
	while(temp != NULL){
		if(temp -> shape != NULL){ //array
			reg1 = getReg();
			fprintf(fp,"MOV R%d, %d\n",reg1, temp -> binding);
			fprintf(fp,"MOV [R%d], %d\n",reg1,(temp -> binding) - calculateMemory(temp -> shape,temp -> dim));
			freeReg();
		}
		temp = temp -> next;
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
	yyparse();
	
	if(input_fp)
		fclose(input_fp);
	return 0;
}
