void getVarMemLoc(struct tnode* t, FILE *fp, reg_index reg);

void oper_code_gen(struct tnode *t, FILE *fp, reg_index reg);

void lib_code_gen(int func, int loc_reg, FILE *fp);

void codeGen(struct tnode *t, FILE *fp, struct LoopStack *lp);

void funcCodeGen(struct tnode *t, FILE *fp, int label);

void functionCallerCode(FILE *fp, int label, struct ArgStruct *args);

void functionCalledStartCode(FILE *fp);

void functionCalledEndCode(FILE *fp,int label);
