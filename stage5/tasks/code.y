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
	#include "data_structures/symbolTable.h"
	#include "data_structures/tNode.h"
	#include "data_structures/dNode.h"
	#include "backend/globalVar.h"
	
	#include "functions/dNodeFunc.h"
	#include "functions/tNodeFunc.h"
	#include "functions/labelAddrTableFunc.h"
	#include "functions/loopStackFunc.h"
	#include "functions/symbolTableFunc.h"
	
	#include "functions/dNodeFunc.c"
	#include "functions/tNodeFunc.c"
	#include "functions/labelAddrTableFunc.c"
	#include "functions/loopStackFunc.c"
	#include "functions/symbolTableFunc.c"
	#include "backend/globalVar.c"
	
	#include "backend/code_gen.h"
	#include "backend/code_gen.c"
	
	struct GSymbolTable* gst;
	struct LSymbolTable* lst;
	void MainFunc(struct tnode* t);
%}

%union{
	struct tnode *no;
	struct dnode *dno;
	int number;
	char* string;
	
}

%type <no> program MainBlock FdefBlock Fdef 
%type <dno> GdeclBlock GdeclList Gdecl GidList Gid ParamList Param LdeclBlock LdeclList Ldecl LidList Lid
%type <no> Slist Stmt InputStmt OutputStmt AssgStmt expr LoopStmt IfStmt Identifier
%type <number> Type

%token MAIN
%token ID NUM STRING
%token STR INT
%token PLUS MINUS STAR DIV MOD ASSIGN GT GTE LT LTE EQ NEQ ADDR
%token START END ENDSTMT DECL ENDDECL
%token READ WRITE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL
%token BREAK CONTINUE

%nonassoc GT GTE LT LTE EQ NEQ
%left PLUS MINUS
%left STAR DIV MOD
%left ADDR


%%

program : GdeclBlock FdefBlock MainBlock	{MainFunc($3);}
	| GdeclBlock MainBlock			{MainFunc($2);}
	| MainBlock				{MainFunc($1);}
	;
	
GdeclBlock : DECL GdeclList ENDDECL 	{
						gst = (struct GSymbolTable*)malloc(sizeof(struct GSymbolTable));
						generateGlobalSymbolTable(gst,$2,noType);	
						printGlobalSymbolTable(gst);		
					}
	| DECL ENDDECL			{}
	;
	
GdeclList : GdeclList Gdecl		{$$ = makeDConnectorNode($1,$2);}
	| Gdecl			{$$ = $1;}
	;
	
Type : INT				{$$ = $<number>1;}
	| STR				{$$ = $<number>1;}
	;

Gdecl : Type GidList ENDSTMT		{$$ = makeDatatypeNode($1,$2);}
	;

GidList : GidList ',' Gid		{$$ = makeDConnectorNode($1,$3);}	
	| Gid				{$$ = $1;}
	;
	
Gid : ID						{$$ = declIdNode($<string>1,0,0,0);}
		| ID '[' NUM ']'			{$$ = declIdNode($<string>1,$<number>3,0,1);}
		| ID '[' NUM ']' '[' NUM ']'		{$$ = declIdNode($<string>1,$<number>3,$<number>6,2);}
		| STAR ID				{$$ = declIdNode($<string>2,0,0,-1);}
		| ID '(' ParamList ')'			{$$ = declFuncNode($<string>1);}
		;

FdefBlock : FdefBlock Fdef				{}
	| Fdef						{}
	;

Fdef : Type ID '(' ParamList ')' '{' LdeclBlock START Slist END '}'	{lst = NULL;}
	;

ParamList : ParamList ',' Param			{$$ = makeDConnectorNode($1,$3);}
	| Param					{$$ = $1;}
	|						{$$ = NULL;}
	;
	
Param : Type ID					{$$ = makeDatatypeNode($1,declIdNode($<string>2,0,0,0));}
	;
	 
MainBlock : INT MAIN '(' ')' '{' LdeclBlock START Slist END'}'	{ 	$$ = $8; 
										lst = NULL;
									}
	| INT MAIN '(' ')' '{' LdeclBlock START END '}'		{ 
							  			lst = NULL;
							  			exit(0);
							  		}
	| INT MAIN '(' ')' '{' START END '}'				{ 
					  					lst = NULL;
					  					exit(0);
					  				}
	;
	

	
LdeclBlock : DECL LdeclList ENDDECL 	{
						lst = (struct LSymbolTable*)malloc(sizeof(struct LSymbolTable));
						generateLocalSymbolTable(lst,$2,noType);
						printLocalSymbolTable(lst);			
					}
	| DECL ENDDECL			{}
	;

LdeclList : LdeclList Ldecl			{$$ = makeDConnectorNode($1,$2);}
	| Ldecl				{$$ = $1;}
	;
	
Ldecl : Type LidList ENDSTMT		{$$ = makeDatatypeNode($1,$2);}
	;
	
LidList : LidList ',' Lid		{$$ = makeDConnectorNode($1,$3);}
	| Lid				{$$ = $1;}
	;


Lid : ID						{$$ = declIdNode($<string>1,0,0,0);}
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

AssgStmt: Identifier ASSIGN expr ENDSTMT				{$$ = makeOperatorNode(assign,$1,$3);}
	| Identifier ASSIGN ADDR Identifier ENDSTMT			{$$ = makePtrIdNode($1, gst, $4);}
	;

expr : expr PLUS expr		{$$ = makeOperatorNode(add,$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode(sub,$1,$3);}
	 | expr STAR expr	{$$ = makeOperatorNode(mul,$1,$3);}
	 | expr DIV expr	{$$ = makeOperatorNode(div,$1,$3);}
	 | expr MOD expr	{$$ = makeOperatorNode(mod,$1,$3);}
	 | expr GT expr	{$$ = makeOperatorNode(gt,$1,$3);}
	 | expr GTE expr	{$$ = makeOperatorNode(gte,$1,$3);}
	 | expr LT expr	{$$ = makeOperatorNode(lt,$1,$3);}
	 | expr LTE expr	{$$ = makeOperatorNode(lte,$1,$3);}
	 | expr EQ expr	{$$ = makeOperatorNode(eq,$1,$3);}
	 | expr NEQ expr	{$$ = makeOperatorNode(neq,$1,$3);}
	 | '(' expr ')'	{$$ = $2;}
	 | NUM			{$$ = makeNumNode($<number>1);}
	 | STRING		{$$ = makeStringNode($<string>1);}
	 | Identifier		{$$ = $1;}
	 | ID '(' ')'		{}
	 | ID '(' ArgList ')'	{}
	 ;
	 
ArgList : ArgList ',' expr		{}
	| expr				{}
	;

Identifier : ID				{$$ = makeIdNode($<string>1,gst,lst,NULL,NULL);}
	| ID '[' expr ']'			{$$ = makeIdNode($<string>1,gst,lst,$3,NULL);}
	| ID '[' expr ']' '[' expr ']'	{$$ = makeIdNode($<string>1,gst,lst,$3,$6);}
	| STAR ID				{$$ = makeIdNode($<string>2,gst,lst,makeNumNode(0),NULL);}
	;

%%

void yyerror(char const *s)
{
    printf("yyerror: %s",s);
    exit(0);
}

void MainFunc(struct tnode* t){ 	
//  	FILE *fp = fopen("output/output.out","w");
//  	fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
//	fprintf(fp,"MOV SP, %d\n",memLoc);
//	
//	struct LoopStack* lp = (struct LoopStack*)malloc(sizeof(struct LoopStack));
//	lp -> top = NULL;
//	
//	codeGen(t,fp,lp);
//	
//	lib_code_gen(end,0,fp);
//	fclose(fp);	
	exit(0);
}


int main(int argc, char* argv[]) {
	
	FILE *input_fp;

	if(argc > 1){
		input_fp = fopen(argv[1],"r");
		fflush(input_fp);
	
		if(input_fp)
			yyin = input_fp;
	}
	yyparse();
	
	if(input_fp)
		fclose(input_fp);
	return 0;
}
