%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "y.tab.h"
	#include "label_ll.h"
	#include "label_ll.c"

	int pass_num = 1;
	int addr_num = -7;
	char* in_filename;
	char* out_filename = "output.xsm";
	FILE* out_fp;
	struct labelAddrTable *lat;

%}

label_decl [A-Z][A-Z0-9]+:\n
label_ref [A-Z][A-Z0-9]+\n

%%
{label_decl}			{if(pass_num == 1) addLabelToTable(lat, yytext, 2056 + 2*(addr_num-1));}
{label_ref}			{
						
						if(pass_num == 2) {
							int res = searchLabel(lat,yytext);
							res == -1 ? fprintf(out_fp,"%s",yytext) : fprintf(out_fp,"%d\n",res);
						}
						else
							++addr_num;
					}
\n					{	
						if(pass_num == 1) ++addr_num;
						else fprintf(out_fp,"\n");
					}
.					{if(pass_num == 2) fprintf(out_fp,"%s",yytext);}

%%

int yywrap(void) {
	if(pass_num == 1){
		FILE* fp = fopen(in_filename,"r");
		if(fp) yyin = fp;
		++pass_num;
		return 0;
	}
	else
		return 1;
}

int main(int argc, char* argv[]){

	lat = (struct labelAddrTable*)malloc(sizeof(struct labelAddrTable));
	
	FILE *fp;
	if(argc > 1){
		in_filename = argv[1];
		if(argc > 2) out_filename = argv[2];
		fp = fopen(in_filename,"r");
		if(fp) yyin = fp;
	}
	
	out_fp = fopen(out_filename,"w");
	
	yylex();
	
	fclose(fp);
	fclose(out_fp);
	return 0;
	
}
