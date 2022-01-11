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
"if"		{return IF;}
"then"		{return THEN;}
"else"		{return ELSE;}
"endif"	{return ENDIF;}
"while"	{return WHILE;}
"do"		{return DO;}
"endwhile"	{return ENDWHILE;}
"read"		{return READ;}
"write" 	{return WRITE;}
"break"	{return BREAK;}
"continue"	{return CONTINUE;}
"repeat"	{return REPEAT;}
"until"	{return UNTIL;}
[a-z]		{yylval.no = makeIdNode(yytext); return ID;}
[0-9]+		{number = atoi(yytext); yylval.no = makeNumNode(number); return NUM;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"="		{return ASSIGN;}
">"		{return GT;}
"<"		{return LT;}
">="		{return GTE;}
"<="		{return LTE;}
"=="		{return EQ;}
"!="		{return NEQ;}
";"		{return ENDSTMT;}
[ \t\n]	{}
[()]		{return *yytext;}
.		{yyerror("unknown character");}

%%

int yywrap(void) {
	return 1;
}
