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
main		{return MAIN;}
begin		{return START;}
end		{return END;}
decl		{return DECL;}
enddecl	{return ENDDECL;}
type		{return TYPE;}
endtype	{return ENDTYPE;}
class 		{return CLASS;}
extends	{return EXTENDS;}
endclass	{return ENDCLASS;}
int		{yylval.string = strdup(yytext); return INT;}
string		{yylval.string = strdup(yytext); return STR;}
void 		{yylval.string = strdup(yytext); return VOID;}
null		{yylval.string = strdup(yytext); return NULL_TYPE;}
tuple		{yylval.string = strdup(yytext); return TUPLE;}
if		{return IF;}
then		{return THEN;}
else		{return ELSE;}
endif		{return ENDIF;}
while		{return WHILE;}
do		{return DO;}
endwhile	{return ENDWHILE;}
read		{return READ;}
write		{return WRITE;}
alloc		{return ALLOC;}
new 		{return NEW;}
initialize	{return INITIALIZE;}
free		{return FREE;}
delete		{return DELETE;}
break		{return BREAK;}
continue	{return CONTINUE;}
return		{return RETURN;}
repeat		{return REPEAT;}
until		{return UNTIL;}
AND		{return AND;}
OR		{return OR;}
self		{yylval.string = strdup(yytext); return SELF;}
{identifier}	{yylval.string = strdup(yytext); return ID;}
{numbers}	{yylval.number = atoi(yytext); return NUM;}
{strings}	{yylval.string = strdup(yytext); return STRING;}
[,()\[\]{}.]	{return *yytext;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return STAR;}
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
"&"		{return ADDR;}
[ \t\n]	{}
.		{error = strdup("unknown character: "); yyerror(strcat(error,yytext));}

%%

int yywrap(void) {
	return 1;
}
