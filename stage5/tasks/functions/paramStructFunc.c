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



struct ParamStruct* makeParamStruct(char* name, datatype dtype){
	struct ParamStruct* node = (struct ParamStruct*)malloc(sizeof(struct ParamStruct));
	node -> name = name;
	node -> dtype = dtype;
	node -> next = NULL;
	return node;
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
