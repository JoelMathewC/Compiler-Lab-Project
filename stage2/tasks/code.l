%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"

	int number;
	struct tnode* makeIdNode(char*);
	struct tnode* makeNumNode(int);
	void yyerror(char*);

%}

%%
"begin"	{return START;}
"end"		{return END;}
"read"		{return READ;}
"write" 	{return WRITE;}
[a-z]		{yylval.no = makeIdNode(yytext); return ID;}
[0-9]+		{number = atoi(yytext); yylval.no = makeNumNode(number); return NUM;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"="		{return EQUALS;}
";"		{return ENDSTMT;}
[ \t\n]	{}
[()]		{return *yytext;}
.		{yyerror("unknown character");}

%%

int yywrap(void) {
	return 1;
}
