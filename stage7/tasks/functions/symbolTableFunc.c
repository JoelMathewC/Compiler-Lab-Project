
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
void GlobalInstall(struct GSymbolTable* gst, char* name, int dim, int nodetype, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct ArrayShape* shape, struct ParamStruct* params){
	struct Gsymbol* elem = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	
	if(dtype -> nodetype == tupleType && shape != NULL){ //to not permit arrays of tuples
		printf("Error: Arrays of Tuples not permitted");
		exit(0);
	}
	
	elem -> dtype = dtype;
	elem -> ctype = ctype;
	elem -> name = name;
	elem -> dim = dim;
	elem -> shape = shape;
	elem -> params = params;
	elem -> next = NULL;

	if(nodetype == func_node){
		elem -> binding = -1;
		elem -> flabel = getFuncLabel();
	}
	else{
		elem -> binding = getMemLoc(calculateMemory(shape,dim, dtype,ctype)); 
		elem -> flabel = -1;
	}
	
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


void LocalInstall(struct LSymbolTable* lst, char* name, int dim,int paramLoc, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype){
	struct Lsymbol* elem = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	

	elem -> name = name;
	elem -> dtype = dtype;
	elem -> ctype = ctype;
	elem -> dim = dim;
	elem -> next = NULL;
	
	if(paramLoc == 0) //local var
		elem -> binding = getLocalMemLoc();
	else
		elem -> binding = paramLoc;

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

void generateGlobalSymbolTable(struct GSymbolTable* gst, struct dnode* root, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct TypeTable* typeTable, struct ClassTable* classTable){
	
	if(root == NULL)
		return;
	
	switch(root -> nodetype){
		case connector: generateGlobalSymbolTable(gst,root -> left,dtype,ctype,typeTable,classTable);
				generateGlobalSymbolTable(gst,root -> right,dtype,ctype,typeTable,classTable);
				break;
		case type_node: generateGlobalSymbolTable(gst, root -> left, TLookup(typeTable,root -> type_name), CLookup(classTable,root -> type_name),typeTable, classTable);
				break;

		case leaf_node: GlobalInstall(gst,root -> varname, root -> dim, leaf_node, dtype, ctype, root -> shape, NULL);
				break;
				
		case func_node: GlobalInstall(gst,root -> varname, root -> dim, func_node, dtype, ctype, root -> shape, root -> params);
				break;
	}
	
}


void addLocalVarToLST(struct LSymbolTable* lst, struct dnode* root, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct TypeTable* typeTable, struct ClassTable* classTable){
	
	if(root == NULL)
		return;
	
	switch(root -> nodetype){
		case connector: addLocalVarToLST(lst,root -> left,dtype,ctype,typeTable,classTable);
				addLocalVarToLST(lst,root -> right,dtype,ctype,typeTable,classTable);
				break;
		case type_node: addLocalVarToLST(lst, root -> left, TLookup(typeTable,root -> type_name),CLookup(classTable,root -> type_name),typeTable, classTable);
				break;
			
		case leaf_node: LocalInstall(lst,root -> varname, root -> dim,0, dtype, ctype);
				break;
				
		case func_node:LocalInstall(lst,root -> varname,root -> dim,0,dtype,ctype);
				break;
	}
	
}

void addParamToLST(struct LSymbolTable* lst, struct ParamStruct* pt){
	struct ParamStruct* temp_p = pt;
	int len = -3;
	
	while(temp_p != NULL){
		LocalInstall(lst,temp_p -> name, temp_p -> dim,len, temp_p -> dtype, temp_p -> ctype);
		temp_p = temp_p -> next;
		--len;
	}
	
}

void verifyFuncHead(struct GSymbolTable* gst, char* name, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct ParamStruct* params){
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
		if(gst_p -> dtype != p -> dtype || gst_p -> ctype != p -> ctype){
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
		printf("Varname: %s",temp -> name);
		temp = temp -> next;
	}
	printf("\n");
}



void printLocalSymbolTable(struct LSymbolTable* lst){

	struct Lsymbol *temp = lst -> head;
	
	char ch[20];
	printf("Local Symbol Table:\n");
	while(temp != NULL){
		printf("Varname: %s",temp -> name);
		temp = temp -> next;
	}
	printf("\n");
}


int calculateMemory(struct ArrayShape* shape, int dim, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype){
	if(dtype != NULL && dtype -> nodetype == tupleType){ //because tuple is a special type we are making it as a seperate type
		
		if(dim == 0) return dtype -> size + 1; //actual value
		else return 1; //pointer
	
	}
	else{
	
		if(dim == 0) return 1;
		if(shape == NULL) return 1;//pointers
		
		//arrays
		int mem = 0, prev_mem;
		struct ArrayShape* node = shape;
		while(node != NULL){
			if(mem == 0){
				mem = node -> index;
				prev_mem = mem;
			}else{
				mem += prev_mem * node -> index;
				prev_mem = prev_mem * node -> index;
			}
			node = node -> next;
		}
		
		mem = mem+1; //location for the real base of an n-dimensional array
		return mem;
	}
		
}
