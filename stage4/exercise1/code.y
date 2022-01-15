%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	
	void yyerror(char const *s);
	int yylex(void);
	extern FILE* yyin;
	void validateShape(int shape[2]);
	
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
	
	struct SymbolTable* st;
	int* shape;
	struct tnode* index1;
	struct tnode* index2;
%}

%union{
	struct tnode *no;
	struct dnode *dno;
	int number;
	char* string;
	
}

%type <no> program
%type <dno> VarList Dstmt Dlist Declarations IdentifierDecl
%type <no> Slist Stmt InputStmt OutputStmt AssgStmt expr LoopStmt IfStmt Identifier
%type <number> Type

%token ID NUM STRING
%token STR INT
%token PLUS MINUS MUL DIV MOD ASSIGN GT GTE LT LTE EQ NEQ
%token START END ENDSTMT DECL ENDDECL
%token READ WRITE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE REPEAT UNTIL
%token BREAK CONTINUE

%nonassoc GT GTE LT LTE EQ NEQ
%left PLUS MINUS
%left MUL DIV MOD


%%


	 
program : START Declarations Slist END ENDSTMT	{ 	
							  	FILE *fp = fopen("output/output.out","w");
							  	fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
								fprintf(fp,"MOV SP, %d\n",memLoc);
								
								struct LoopStack* lp = (struct LoopStack*)malloc(sizeof(struct LoopStack));
								lp -> top = NULL;
								
								codeGen($3,fp,lp);
								
								lib_code_gen(end,0,fp);
								fclose(fp);	
								exit(0);
					  		}
	| START Declarations END ENDSTMT		{ 
					  			exit(0);
					  		}
	| START END ENDSTMT				{ 
					  			exit(0);
					  		}
	;
	

	
Declarations : DECL Dlist ENDDECL 	{
						st = (struct SymbolTable*)malloc(sizeof(struct SymbolTable));
						generateSymbolTable(st,$2,noType);	
						//printSymbolTable(st);		
					}
	| DECL ENDDECL			{}
	;

Dlist : Dlist Dstmt			{$$ = makeDConnectorNode($1,$2);}
	| Dstmt			{$$ = $1;}
	;
	
Dstmt : Type VarList ENDSTMT		{$$ = makeDatatypeNode($1,$2);}
	;
	
Type : INT				{$$ = $<number>1;}
	| STR				{$$ = $<number>1;}
	;
	
VarList : VarList ',' IdentifierDecl	{$$ = makeDConnectorNode($1,$3);}
	| IdentifierDecl		{$$ = $1;}
	;


IdentifierDecl: ID					{
								shape = (int*)malloc(2*sizeof(int));
								shape[0] = 0;
								shape[1] = 0; 
								validateShape(shape);
								$$ = declIdNode($<string>1,0,shape);
							}
		| ID '[' NUM ']'			{
								shape = (int*)malloc(2*sizeof(int));
								shape[0] = $<number>3;
								shape[1] = 0;  
								validateShape(shape);
								$$ = declIdNode($<string>1,1,shape);
							}
		| ID '[' NUM ']' '[' NUM ']'		{
								shape = (int*)malloc(2*sizeof(int));
								shape[0] = $<number>3;
								shape[1] = $<number>6; 
								validateShape(shape); 
								$$ = declIdNode($<string>1,2,shape);
							}
		;
	



Slist : Slist Stmt	{$$ = makeConnectorNode($1,$2);}
	| Stmt		{$$ = $1;}
	;
	
Stmt:	InputStmt	{$$ = $1;}
	| OutputStmt	{$$ = $1;}
	| AssgStmt	{$$ = $1;}
	| IfStmt			{$$ = $1;}
	| LoopStmt			{$$ = $1;}
	| BREAK ENDSTMT		{$$ = makeJumpNode(break_node);}
	| CONTINUE ENDSTMT		{$$ = makeJumpNode(continue_node);}
	;
	
IfStmt : IF '(' expr ')' THEN Slist ELSE Slist ENDIF	ENDSTMT	{$$ = makeIfElseBlock($3,$6,$8);}
	| IF '(' expr ')' THEN Slist ENDIF ENDSTMT			{$$ = makeIfElseBlock($3,$6,NULL);}
	;
	
LoopStmt : WHILE '(' expr ')' DO Slist ENDWHILE ENDSTMT		{$$ = makeWhileBlock($3,$6);}
	| DO Slist WHILE '(' expr ')' ENDSTMT				{$$ = makeDoWhileBlock($5,$2);}
	| REPEAT Slist UNTIL '(' expr ')' ENDSTMT			{$$ = makeDoWhileBlock($5,$2);}
	;

InputStmt : READ '(' Identifier ')' ENDSTMT		{$$ = makeReadNode($3);}
	;

OutputStmt: WRITE '(' expr ')' ENDSTMT	{$$ = makeWriteNode($3);}
	;

AssgStmt: Identifier ASSIGN expr ENDSTMT		{$$ = makeOperatorNode(assign,$1,$3);}
	;

expr : expr PLUS expr		{$$ = makeOperatorNode(add,$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode(sub,$1,$3);}
	 | expr MUL expr	{$$ = makeOperatorNode(mul,$1,$3);}
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
	 ;

Identifier : ID				{
							index1 = NULL;
							index2 = NULL; 
							$$ = makeIdNode($<string>1,st,index1,index2);
						}
	| ID '[' expr ']'			{	
							index1 = $3;
							index2 = NULL; 
							$$ = makeIdNode($<string>1,st,index1,index2);
						}
	| ID '[' expr ']' '[' expr ']'	{	
							index1 = $3;
							index2 = $6; 
							$$ = makeIdNode($<string>1,st,index1,index2);
						} //fill
	;

%%

void yyerror(char const *s)
{
    printf("yyerror: %s",s);
    exit(0);
}

void validateShape(int shape[2]){
	if(shape[0] < 0 || shape[1] < 0){
		printf("Error: Invalid Index\n");
    		exit(0);
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
	yyparse();
	
	if(input_fp)
		fclose(input_fp);
	return 0;
}
