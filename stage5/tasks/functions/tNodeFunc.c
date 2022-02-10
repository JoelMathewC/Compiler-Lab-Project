struct tnode* createTree(union Data val, char* c, struct tnode* index1, struct tnode* index2, datatype dtype, node_type nodetype, struct Gsymbol* Gentry, struct Lsymbol* Lentry, struct ArgStruct* args,struct tnode *l, struct tnode *r){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	
	if(c != NULL){
		node -> varname = (char*)malloc(sizeof(char));
		strcpy(node -> varname,c);
	}
	
	node -> val = val;
	node -> index1 = index1;
	node -> index2 = index2;
	
	if(index1 == NULL && index2 == NULL) //no indexes
		node -> dtype = dtype;
	else if(index2 == NULL){  // one index (pointers have default first index as 0)
		switch(dtype){
			case intSingleArrType: 
			case intPtrType: node -> dtype = intType;
				break;
			case intDoubleArrType: node -> dtype = intSingleArrType;
				break;
				
			case strSingleArrType: 
			case strPtrType: node -> dtype = stringType;
				break;
			case strDoubleArrType: node -> dtype = strSingleArrType;
				break;
		}
	}
	else{ //two indexex
		switch(dtype){
			case intDoubleArrType: node -> dtype = intType;
				break;
			case strDoubleArrType: node -> dtype = stringType;
				break;
		}
	}
	
	node -> Gentry = Gentry;
	node -> Lentry = Lentry;
	node -> nodetype = nodetype;
	node -> left = l;
	node -> right = r;
	node -> args = args;
	return node;
}

struct tnode* makeIdNode(char* c, struct GSymbolTable* gst, struct LSymbolTable* lst, struct tnode* index1, struct tnode* index2){

	struct Gsymbol* temp_g = GlobalLookup(gst,c);
	struct Lsymbol* temp_l = LocalLookup(lst,c);
	union Data emp_data;
	
	//if entry does not exist in symbol table
	if(temp_g == NULL && temp_l == NULL){
		printf("Heree: %s",c);
		yyerror("Undefined Variable Referenced\n");
		exit(0);
	}
	else if(temp_l != NULL)
		temp_g = NULL;
	else
		temp_l = NULL;
	

	//invalid []
	if(temp_g != NULL && temp_g -> dim == 0 && index1 != NULL && isSymbolPtr(temp_g) == False){ // 0D trying to access first dimension
		printf("%s is not accessible to a first dimension\n",c);
		exit(0);
	}
	else if(temp_g != NULL && temp_g -> dim == 1 && index2 != NULL){ // 1D array trying to access second dimension
		printf("%s is not accessible to a second dimension\n",c);
		exit(0);
	}
	
	return createTree(emp_data, c, index1, index2, temp_g == NULL ? temp_l -> dtype: temp_g -> dtype, leaf_node, temp_g, temp_l, NULL, NULL, NULL);
}


struct tnode* makeFuncNode(char* c, struct GSymbolTable* gst, struct ArgStruct* args){

	struct Gsymbol* temp_g = GlobalLookup(gst,c);
	union Data emp_data;
	
	//if entry does not exist in symbol table
	if(temp_g == NULL){
		yyerror("Undefined Variable Referenced\n");
		exit(0);
	}
	
	struct ArgStruct* temp_arg = args;
	struct ParamStruct* temp_p = temp_g -> params;
	
	while(temp_arg != NULL && temp_p != NULL){
		if(temp_arg -> arg -> dtype != temp_p -> dtype){
			printf("Operands dont match definition: %s",c);
			exit(0);
		}
		temp_arg = temp_arg -> next;
		temp_p = temp_p -> next;
	}

	if(temp_arg != NULL || temp_p != NULL){
		printf("Operands dont match definition: %s",c);
		exit(0);
	}
	
	return createTree(emp_data, c, NULL, NULL, temp_g -> dtype, leaf_node, temp_g, NULL, args, NULL, NULL);
}


struct tnode* makeNumNode(int n){
	union Data data;
	data.num = n;
	

	return createTree(data,NULL, NULL, NULL,intType, leaf_node, NULL, NULL, NULL, NULL, NULL);
}

struct tnode* makePtrIdNode(struct tnode* ptr, struct GSymbolTable* gst, struct tnode* addr){
	struct Gsymbol* ptr_entry = GlobalLookup(gst,ptr -> varname);
	struct Gsymbol* addr_entry = GlobalLookup(gst,addr -> varname);
	union Data emp_data;
	
	//if entry does not exist in symbol table
	if(ptr_entry == NULL || addr_entry == NULL){
		yyerror("Undefined Variable Referenced\n");
		exit(0);
	}
	
	if(isSymbolPtr(ptr_entry) == False || (addr_entry -> dtype != intType && addr_entry -> dtype != stringType)){
		yyerror("Type Mismatch\n");
		exit(0);
	}
	
	if((ptr_entry -> dtype == intPtrType && addr_entry -> dtype != intType) || (ptr_entry -> dtype == strPtrType && addr_entry -> dtype != stringType)){
		yyerror("Type Mismatch\n");
		exit(0);
	}
	
	ptr_entry -> binding = addr_entry -> binding;
	ptr_entry -> dim = addr_entry -> dim;
	ptr_entry -> shape = addr_entry -> shape;
	
	return createTree(emp_data,NULL, NULL, NULL,ptr_entry -> dtype, leaf_node, ptr_entry, NULL, NULL, NULL, NULL);
}

struct tnode* makeStringNode(char* str){
	union Data data;
	data.str = str;
	
	struct tNode* index[2];
	return createTree(data, NULL, NULL, NULL, stringType,leaf_node, NULL, NULL, NULL, NULL, NULL);
}



struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r){

	int type;

	switch(op){
		case add:
		case sub:
		case mul:
		case div:
		case mod:	
				if(l -> dtype == intType && r -> dtype == intType){
					type = intType;
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				
				break;
				
		case assign:	if(isValPtr(l) == False && isValPtr(r) == False && (l -> dtype == r -> dtype))
					type = noType;
				else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				break;
				
		case gt:
		case gte:
		case lt:
		case lte:
		case eq:
		case neq:	
				if(l -> dtype == intType && r -> dtype == intType){
					type = boolType;
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				break;
	}
	
	union Data emp_data;
	return createTree(emp_data,NULL,NULL, NULL,type , op, NULL, NULL, NULL, l, r);
}


struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r){
	union Data emp_data;
	return createTree(emp_data, NULL,NULL,NULL,noType, connector, NULL, NULL, NULL, l, r);
}

struct tnode* makeReadNode(struct tnode *l){ // read node has only a left child
	union Data emp_data;
	if(l -> dtype == intType || l -> dtype == stringType)
		return createTree(emp_data,NULL,NULL,NULL,noType,read,NULL, NULL, NULL,l,NULL);
	else{
		printf("Error: Cannot Read into array\n");
		exit(1);
	}
}

struct tnode* makeWriteNode(struct tnode *l){ // write node has only left child
	union Data emp_data;
	if(l -> dtype == intType || l -> dtype == stringType)
		return createTree(emp_data,NULL,NULL,NULL,noType,write,NULL, NULL, NULL,l,NULL);
	else{
		printf("Error: Cannot Write array\n");
		exit(1);
	}
}

struct tnode* makeJumpNode(node_type nodetype){
	union Data emp_data;
	return createTree(emp_data, NULL,NULL,NULL,noType, nodetype,NULL, NULL,NULL, NULL,NULL);
}

struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node){// left child is condition, right child is connector (left: if, right: else)
	union Data emp_data;
	struct tnode* node1 = createTree(emp_data, NULL,NULL,NULL,noType, then_else_node, NULL, NULL, NULL, then_node,else_node);
	struct tnode* node2 = createTree(emp_data, NULL,NULL,NULL,noType, if_node, NULL, NULL, NULL, cond,node1);
	return node2;
}

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,NULL,NULL,noType, while_node, NULL, NULL, NULL, cond, body);
}

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,NULL,NULL,noType, do_while, NULL, NULL, NULL, cond, body);
}


boolean isSymbolPtr(struct Gsymbol* g){ //if the symbol is a pointer (will classify *ptr as a pointer)
	if(g -> dtype == intPtrType || g -> dtype == strPtrType)
		return True;
	return False;
}

boolean isValPtr(struct tnode* g){ //if the value is a pointer (will classify *ptr as an int/str)
	if(g -> dtype == intPtrType || g -> dtype == strPtrType)
		return True;
	return False;
}

/*boolean validateArr(struct tnode* node){*/
/*	*/
/*	if(node -> type == intArrType || node -> type == strArrType){*/
/*		if(node -> Gentry -> dim == 1){ //1D*/
/*			if(node -> index1 == NULL){*/
/*				*/
/*				printf("Error: Array(%s) index missing. Dim: %d\n",node -> varname, node -> Gentry -> dim);*/
/*				exit(1);*/
/*			}*/
/*		}*/
/*		else if(node -> Gentry -> dim == 2){ //2D*/
/*			if(node -> index2 == NULL){*/
/*				printf("Error: Array(%s) index missing. Dim: %d\n",node -> varname, node -> Gentry -> dim);*/
/*				exit(1);*/
/*			}*/
/*		}*/
/*		return True;*/
/*	}*/
/*	return False;*/
/*}*/


/*boolean validateOper(struct tnode* node){*/
/*	if(node -> type == intType)*/
/*		return True;*/
/*	if(node -> type == intArrType && validateArr(node) == True)*/
/*		return True;*/
/*	return False;*/
/*}*/












