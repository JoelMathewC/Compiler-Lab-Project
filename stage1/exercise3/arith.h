

#define reg_index int
reg_index reg_num = -1;

int getReg();

void freeReg();

reg_index codeGen(struct tnode *t, FILE *fp);
