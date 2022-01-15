#define reg_index int


reg_index reg_num = 0; //we will start using registers from R1 onwards

int label_num = -1;

int memLoc = 4095; //memory location to store variables in



//function definition
int getReg();

void freeReg();

int getLabel();

int getMemLoc(int amount);
