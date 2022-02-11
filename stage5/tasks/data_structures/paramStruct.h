struct ParamStruct{
	datatype dtype;
	char* name;
	struct ParamStruct *next;
};

struct ArgStruct{
	struct tnode* arg;
	struct ArgStruct* next;
};

struct ArgStack{
	struct ArgStruct* head;
};
