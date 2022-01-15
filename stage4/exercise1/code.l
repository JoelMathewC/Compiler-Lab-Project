%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"



	void yyerror(char*);
	char* error;
	
	#define intType 1
	#define stringType 2

%}

identifier ([a-zA-Z]|_[a-zA-Z])[a-zA-Z0-9_]*
strings \"((\\\")|[^"])*\"
numbers [0-9]+

%%
begin		{return START;}
end		{return END;}
decl		{return DECL;}
enddecl	{return ENDDECL;}
int		{yylval.number = intType; return INT;}
string		{yylval.number = stringType; return STR;}
if		{return IF;}
then		{return THEN;}
else		{return ELSE;}
endif		{return ENDIF;}
while		{return WHILE;}
do		{return DO;}
endwhile	{return ENDWHILE;}
read		{return READ;}
write		{return WRITE;}
break		{return BREAK;}
continue	{return CONTINUE;}
repeat		{return REPEAT;}
until		{return UNTIL;}
{identifier}	{yylval.string = strdup(yytext); return ID;}
{numbers}	{yylval.number = atoi(yytext); return NUM;}
{strings}	{yylval.string = strdup(yytext); return STRING;}
[,()\[\]]	{return *yytext;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"%"		{return MOD;}
"="		{return ASSIGN;}
">"		{return GT;}
"<"		{return LT;}
">="		{return GTE;}
"<="		{return LTE;}
"=="		{return EQ;}
"!="		{return NEQ;}
";"		{return ENDSTMT;}
[ \t\n]	{}
.		{error = strdup("unknown character: "); yyerror(strcat(error,yytext));}

%%

int yywrap(void) {
	return 1;
}
