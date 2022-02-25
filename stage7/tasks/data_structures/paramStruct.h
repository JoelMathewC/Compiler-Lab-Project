struct ParamStruct{
	int dim;
	char* name;
	
	struct ClassTableEntry* ctype;
	struct TypeTableEntry* dtype;
	struct ParamStruct *next;
};

struct ArgStruct{
	struct tnode* arg;
	struct ArgStruct* next;
};

struct ArgStack{
	struct ArgStruct* head;
};
