#define reg_index int


reg_index reg_num = 0; //we will start using registers from R1 onwards

int label_num = -1;

int func_label_num = -1;

int classIndex = -1;

int memLoc = 4095; //memory location to store variables in

int localMemLoc  = 0;



//function definition
int getReg();

void freeReg();

int getLabel();

int getClassIndex();

int getFuncLabel();

int getMemLoc(int amount);

int getLocalMemLoc();
