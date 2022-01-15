
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
void Install(struct SymbolTable* st,char* name, int type, int dim, int shape[2]){
	struct Gsymbol* elem = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	
	switch(type){
		case intType:  if(shape[0] > 0)
					elem -> type = intArrType;
				else
					elem -> type = type;
				break;
		case stringType: if(shape[0] > 0)
					elem -> type = strArrType;
				  else
				  	elem -> type = type;
				break;
	}


	elem -> name = name;
	elem -> dim = dim;
	elem -> shape = shape;
	
	int mem;
	if(shape[0] <= 0){
		mem = 1;
	}else if(shape[1] <= 0){
		mem = shape[0];
	}else{
		mem = shape[0] * shape[1];
	}
	
	elem -> binding = getMemLoc(mem);
	elem -> next = NULL;
	
	struct Gsymbol* temp = st -> head;
	if(st -> head == NULL){
		st -> head = elem;
	}
	else{
		while(temp -> next != NULL)
			temp = temp -> next;
		
		temp -> next = elem;
	}
	
}

void generateSymbolTable(struct SymbolTable* st, struct dnode* root, int dtype){

	if(root == NULL)
		return;
	
	switch(root -> nodetype){
		case connector: generateSymbolTable(st,root -> left,dtype);
				generateSymbolTable(st,root -> right,dtype);
				break;
		
		case intArrType:
		case strArrType:	
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
	
		switch(temp -> type){
	
			case intType: strcpy(ch,"int");
				break;
			case stringType: strcpy(ch,"string");
				break;
			case intArrType: if(temp -> dim == 1)
						strcpy(ch,"int[]");
					 else
					 	strcpy(ch,"int[][]");
				break;
			case strArrType: if(temp -> dim == 1)
						strcpy(ch,"string[]");
					 else
					 	strcpy(ch,"string[][]");
				break;
		}
		printf("Varname: %s, Datatype: %s, Size: %d\n",temp -> name, ch,temp -> shape[0] * (temp -> shape[1] == 0 ? 1 : temp -> shape[1]));
		temp = temp -> next;
	}
}
