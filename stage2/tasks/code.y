%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exptree.h"
	#include "exptree.c"
	#include "arith.h"
	#include "arith.c"
	int yylex(void);
	void yyerror(char const *s);
	extern FILE* yyin;
%}

%union{
	struct tnode *no;
	
}

%type <no> program END
%type <no> Slist Stmt InputStmt OutputStmt AssgStmt expr
%type <no> ID NUM 

%token ID NUM
%token PLUS MINUS MUL DIV EQUALS
%token START END ENDSTMT
%token READ WRITE

%left PLUS MINUS
%left MUL DIV

%%


	 
program : START Slist END ENDSTMT	{ 	$$ = $3;
					  	
					  	FILE *fp = fopen("output.xsm","w");
					  	fprintf(fp,"0\n2056\n0\n0\n0\n0\n0\n0\n");
						fprintf(fp,"MOV SP, 4121\n");
						
						codeGen($2,fp);
						
						lib_code_gen(end,0,fp);
						fclose(fp);	
						exit(0);
					  }
	| START END ENDSTMT		{ $$ = $2;
					  exit(0);}
	;

Slist : Slist Stmt	{$$ = makeConnectorNode($1,$2);}
	| Stmt		{$$ = $1;}
	;

Stmt:	InputStmt	{$$ = $1;}
	| OutputStmt	{$$ = $1;}
	| AssgStmt	{$$ = $1;}
	;

InputStmt : READ '(' ID ')' ENDSTMT	{$$ = makeReadNode($3);}
	;

OutputStmt: WRITE '(' expr ')' ENDSTMT	{$$ = makeWriteNode($3);}
	;

AssgStmt: ID EQUALS expr ENDSTMT	{$$ = makeOperatorNode(assign,$1,$3);}
	;

expr : expr PLUS expr		{$$ = makeOperatorNode(add,$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode(sub,$1,$3);}
	 | expr MUL expr	{$$ = makeOperatorNode(mul,$1,$3);}
	 | expr DIV expr	{$$ = makeOperatorNode(div,$1,$3);}
	 | '(' expr ')'	{$$ = $2;}
	 | NUM			{$$ = $1;}
	 | ID			{$$ = $1;}
	 ;

%%

void yyerror(char const *s)
{
    printf("yyerror: %s",s);
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
