void dimResCodeGen(FILE* fp, reg_index reg, int dim_cur, int dim_abs, struct ArrayDims* indices);

int getVarMemLoc(struct tnode* t, FILE *fp, reg_index reg, boolean findParentOfClass);

void oper_code_gen(struct tnode *t, FILE *fp, reg_index reg);

void lib_code_gen(int func, int loc_reg, FILE *fp);

void codeGen(struct tnode *t, FILE *fp, struct LoopStack *lp);

void funcCodeGen(struct tnode *t, FILE *fp, int label);

void functionCallerCode(FILE *fp, int label, struct ArgStruct *args, boolean isMethod, int method_addr_reg);

void functionCalledStartCode(FILE *fp);

void functionCalledEndCode(FILE *fp,int label);
