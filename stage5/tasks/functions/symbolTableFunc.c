
struct Gsymbol* GlobalLookup(struct GSymbolTable* gst, char* name){
	
	if(gst == NULL)
		return NULL;
	
	struct Gsymbol* temp_g = gst -> head;
	
	while(temp_g != NULL){
		if(strcmp(temp_g -> name,name) == 0){
			return temp_g;
		}
		temp_g = temp_g -> next;
	}
	
	return NULL;
}

struct Lsymbol* LocalLookup(struct LSymbolTable* lst, char* name){
	if(lst == NULL)
		return NULL;
		
	struct Lsymbol* temp = lst -> head;
	while(temp != NULL){
		if(strcmp(temp -> name,name) == 0){
			return temp;
		}
		temp = temp -> next;
	}
	
	return NULL;
	
}
void GlobalInstall(struct GSymbolTable* gst, char* name, datatype type, int dim, int shape[2], struct ParamStruct* params, int nodetype){
	struct Gsymbol* elem = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	
	switch(type){
		case intType:  if(dim == 2)
					elem -> dtype = intDoubleArrType;
				else if(dim == 1)
					elem -> dtype = intSingleArrType;
				else if(dim == 0)
					elem -> dtype = intType;
				else
					elem -> dtype = intPtrType;
				break;
				
		case stringType: if(dim == 2)
					elem -> dtype = strDoubleArrType;
				else if(dim == 1)
					elem -> dtype = strSingleArrType;
				else if(dim == 0)
					elem -> dtype = stringType;
				else
					elem -> dtype = strPtrType;
				break;
	}


	elem -> name = name;
	elem -> dim = dim;
	elem -> shape = shape;
	elem -> params = params;
	
	int mem;
	if(shape[0] <= 0) mem = 1;
	else if(shape[1] <= 0) mem = shape[0];
	else mem = shape[0] * shape[1];
	
	if(nodetype == func_node)
		elem -> binding = getFuncLabel();
	else
		elem -> binding = (dim == -1) ? -1 : getMemLoc(mem);
		
	elem -> next = NULL;
	
	struct Gsymbol* temp = gst -> head;
	if(gst -> head == NULL)
		gst -> head = elem;
	else{
		while(temp!= NULL){
			if(strcmp(temp -> name,name) == 0){ //if the identifier has already been used
				printf("Error: Repeated use of identifier %s",name);
				exit(0);
			}
			if(temp -> next == NULL)
				break;
			temp = temp -> next;
		}
		
		temp -> next = elem;
	}
	
}


void LocalInstall(struct LSymbolTable* lst, char* name, datatype type, int paramLoc){
	struct Lsymbol* elem = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));

	elem -> name = name;
	elem -> dtype = type;
	
	if(paramLoc == 0) //local var
		elem -> binding = getLocalMemLoc();
	else
		elem -> binding = paramLoc;
			
	elem -> next = NULL;
	
	struct Lsymbol* temp = lst -> head;
	if(temp == NULL)
		lst -> head = elem;
	else{
		while(temp -> next != NULL){
			if(strcmp(temp -> name,name) == 0){ //if the identifier has already been used
				printf("Error: Repeated use of identifier %s",name);
				exit(0);
			}
			temp = temp -> next;
		}
		
		temp -> next = elem;
	}
	
}

void generateGlobalSymbolTable(struct GSymbolTable* gst, struct dnode* root, datatype dtype){

	if(root == NULL)
		return;
	
	switch(root -> nodetype){
		case connector: generateGlobalSymbolTable(gst,root -> left,dtype);
				generateGlobalSymbolTable(gst,root -> right,dtype);
				break;
		case stringType:
		case intType: generateGlobalSymbolTable(gst, root -> left, root -> nodetype);
				break;
			
		case leaf_node: GlobalInstall(gst,root -> varname, dtype, root -> dim, root -> shape,NULL,leaf_node);
				break;
				
		case func_node: GlobalInstall(gst,root -> varname, dtype, root -> dim, root -> shape,root -> params,func_node);
				break;
	}
	
}


void addLocalVarToLST(struct LSymbolTable* lst, struct dnode* root, datatype dtype){
	if(root == NULL)
		return;
	
	switch(root -> nodetype){
		case connector: addLocalVarToLST(lst,root -> left,dtype);
				addLocalVarToLST(lst,root -> right,dtype);
				break;
		case stringType:
		case intType: 	addLocalVarToLST(lst, root -> left, root -> nodetype);
				break;
			
		case leaf_node: LocalInstall(lst,root -> varname, dtype,0);
				break;
				
		case func_node: LocalInstall(lst,root -> varname, dtype,0);
				break;
	}
	
}

void addParamToLST(struct LSymbolTable* lst, struct ParamStruct* pt){
	struct ParamStruct* temp_p = pt;
	int len = -3;
	while(temp_p != NULL){
		LocalInstall(lst,temp_p -> name, temp_p -> dtype,len);
		temp_p = temp_p -> next;
		--len;
	}
	
}

void verifyFuncHead(struct GSymbolTable* gst, char* name, datatype dtype, struct ParamStruct* params){
	struct Gsymbol* Gentry = GlobalLookup(gst,name);
	
	if(Gentry == NULL){
		printf("Function not declared: %s",name);
		exit(0);
	}
	
	if(Gentry -> dtype != dtype){
		printf("Function declared with different return types: %s",name);
		exit(0);
	}
	
	struct ParamStruct* gst_p = Gentry -> params;
	struct ParamStruct* p = params;
	while(gst_p != NULL && p != NULL){
		if(gst_p -> dtype != p -> dtype){
			printf("%d : %d\n",gst_p -> dtype,p -> dtype);
			printf("Parameters inconsistent with declaration: %s", name);
			exit(0);
		}
		gst_p = gst_p -> next;
		p = p -> next;
	}
	if(gst_p != NULL || p != NULL){
		printf("Parameters inconsistent with declaration: %s", name);
		exit(0);
	}
}

void printGlobalSymbolTable(struct GSymbolTable* gst){

	struct Gsymbol *temp = gst -> head;
	
	char ch[20];
	
	printf("Global Symbol Table:\n");
	while(temp != NULL){
	
		switch(temp -> dtype){
	
			case intType: strcpy(ch,"int");
				break;
			case stringType: strcpy(ch,"string");
				break;
			case intSingleArrType: strcpy(ch,"int[]");
				break;
			case strSingleArrType: strcpy(ch,"string[]");	 	
				break;
			case intDoubleArrType: strcpy(ch,"int[][]");
				break;
			case strDoubleArrType: strcpy(ch,"string[][]");	 	
				break;
			case intPtrType: strcpy(ch,"int*");
				break;
			case strPtrType: strcpy(ch,"string*");	 	
				break;
		}
		printf("Varname: %s, Datatype: %s\n",temp -> name, ch);
		temp = temp -> next;
	}
	printf("\n");
}



void printLocalSymbolTable(struct LSymbolTable* lst){

	struct Lsymbol *temp = lst -> head;
	
	char ch[20];
	printf("Local Symbol Table:\n");
	while(temp != NULL){
	
		switch(temp -> dtype){
	
			case intType: strcpy(ch,"int");
				break;
			case stringType: strcpy(ch,"string");
				break;
			case intSingleArrType: strcpy(ch,"int[]");
				break;
			case strSingleArrType: strcpy(ch,"string[]");	 	
				break;
			case intDoubleArrType: strcpy(ch,"int[][]");
				break;
			case strDoubleArrType: strcpy(ch,"string[][]");	 	
				break;
			case intPtrType: strcpy(ch,"int*");
				break;
			case strPtrType: strcpy(ch,"string*");	 	
				break;
		}
		printf("Varname: %s, Datatype: %s\n",temp -> name, ch);
		temp = temp -> next;
	}
	printf("\n");
}
