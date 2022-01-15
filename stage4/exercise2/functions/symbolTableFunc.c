
struct Gsymbol* Lookup(struct SymbolTable* st,char* name){
	
	if(st == NULL)
		return NULL;

	struct Gsymbol* temp = st -> head;
	
	while(temp != NULL){
		if(strcmp(temp -> name,name) == 0){
			return temp;
		}
		temp = temp -> next;
	}
	
	return NULL;
}
void Install(struct SymbolTable* st,char* name, datatype type, int dim, int shape[2]){
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
	
	int mem;
	if(shape[0] <= 0) mem = 1;
	else if(shape[1] <= 0) mem = shape[0];
	else mem = shape[0] * shape[1];
	
	
	elem -> binding = (dim == -1) ? -1 : getMemLoc(mem);
	elem -> next = NULL;
	
	struct Gsymbol* temp = st -> head;
	if(st -> head == NULL)
		st -> head = elem;
	else{
		while(temp -> next != NULL)
			temp = temp -> next;
		
		temp -> next = elem;
	}
	
}

void generateSymbolTable(struct SymbolTable* st, struct dnode* root, datatype dtype){

	if(root == NULL)
		return;
	
	switch(root -> nodetype){
		case connector: generateSymbolTable(st,root -> left,dtype);
				generateSymbolTable(st,root -> right,dtype);
				break;
		
/*		case intSingleArrType:*/
/*		case strSingleArrType:	*/
		case stringType:
		case intType: generateSymbolTable(st, root -> left, root -> nodetype);
				break;
			
		case leaf_node: 
				Install(st,root -> varname, dtype, root -> dim, root -> shape);
				break;
	}
	
}


void printSymbolTable(struct SymbolTable* st){

	struct Gsymbol *temp = st -> head;
	
	char ch[20];
	
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
		printf("Varname: %s, Datatype: %s, Size: %d\n",temp -> name, ch,temp -> shape[0] * (temp -> shape[1] == 0 ? 1 : temp -> shape[1]));
		temp = temp -> next;
	}
}
