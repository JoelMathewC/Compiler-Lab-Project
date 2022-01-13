int getVarLoc(struct tnode* t){
	if(t -> type == intType || t -> type == stringType)
		return t -> Gentry -> binding;
	else
		return t -> Gentry -> binding + t -> index;
}


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
void Install(struct SymbolTable* st,char* name, int type, int size){
	struct Gsymbol* elem = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	
	
	switch(type){
		case intType: if(size > 1)
				elem -> type = intArrType;
				break;
		case stringType: if(size > 1)
				elem -> type = strArrType;
				break;
	}

	elem -> name = name;
	elem -> size = size;
	elem -> binding = getMemLoc(size);
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
				Install(st,root -> varname, dtype, root -> size);
				break;
	}
	
}


void printSymbolTable(struct SymbolTable* st){

	struct Gsymbol *temp = st -> head;
	
	char ch[10];
	
	while(temp != NULL){
		switch(temp -> type){
	
		case intType: strcpy(ch,"int");
			break;
		case stringType: strcpy(ch,"string");
			break;
		case intArrType: strcpy(ch,"int[]");
			break;
		case strArrType: strcpy(ch,"string[]");
			break;
	}
		printf("Varname: %s, Datatype: %s\n",temp -> name, ch);
		temp = temp -> next;
	}
}
