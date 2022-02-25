struct ParamStruct* addParameter(struct ParamStruct* pt,struct ParamStruct* node){
	struct ParamStruct* temp = pt;
	if(temp == NULL){
		pt = node;
	}else{
		while(temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = node;
	}
	return pt;
}



struct ParamStruct* makeParamStruct(char* name, char* type, int dim, struct TypeTable* typeTable, struct ClassTable* classTable){
	struct ParamStruct* node = (struct ParamStruct*)malloc(sizeof(struct ParamStruct));
	node -> name = name;
	node -> dtype = TLookup(typeTable, type);
	node -> ctype = CLookup(classTable,type);
	node -> dim = dim;
	node -> next = NULL;
	return node;
}


//For Tuples
struct FieldList* makeFieldListFromParam(struct ParamStruct* pt){
	struct FieldList *fl, *tail, *head;
	tail = NULL;
	head = NULL;
	
	struct ParamStruct* temp = pt;
	int i = 0;
	while(temp != NULL){
		fl = FInstall(temp -> name,temp -> dim, i, temp -> dtype);
		
		if(head == NULL){
			head = fl;
			tail = fl;
		}else{
			tail -> next = fl;
			tail = fl;
		}
		i = i + 1;
		temp = temp -> next;
	}
	return head;
}


struct ArgStruct* addArguments(struct ArgStruct* args,struct ArgStruct* node){
	struct ArgStruct* temp = args;
	if(temp == NULL){
		args = node;
	}else{
		while(temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = node;
	}
	return args;
}



struct ArgStruct* makeArgStruct(struct tnode* expr){
	struct ArgStruct* node = (struct ArgStruct*)malloc(sizeof(struct ArgStruct));
	node -> arg = expr;
	node -> next = NULL;
	return node;
}

struct tnode* popArgStack(struct ArgStack* st){
	struct tnode* temp = st -> head -> arg;
	if(temp == NULL){
		printf("Error: Nothing to pop\n");
		exit(0);
	}
	st -> head = st -> head -> next;
	return temp;
}

void pushArgStack(struct ArgStack* st, struct tnode* node){
		struct ArgStruct* new_node = (struct ArgStruct*)malloc(sizeof(struct ArgStruct));
		new_node -> arg = node;
		new_node -> next = st -> head;
		st -> head = new_node;
}
