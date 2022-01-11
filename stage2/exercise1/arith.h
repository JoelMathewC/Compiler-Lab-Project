

#define reg_index int
reg_index reg_num = 0; //we will start using registers from R1 onwards

int getReg();

void freeReg();

int getVarLoc(char* varname);

reg_index oper_code_gen(struct tnode *t, FILE *fp);

void lib_code_gen(char func, int loc_reg, FILE *fp);

void codeGen(struct tnode *t, FILE *fp);
