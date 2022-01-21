void getVarMemLoc(struct tnode* t, FILE *fp, reg_index reg);

void oper_code_gen(struct tnode *t, FILE *fp, reg_index reg);

void lib_code_gen(int func, int loc_reg, FILE *fp);

void codeGen(struct tnode *t, FILE *fp, struct LoopStack *lp);


