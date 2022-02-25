struct tnode* createTree(union Data val, char* c, int dim, node_type nodetype, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct ArrayDims* indices, struct Gsymbol* Gentry, struct Lsymbol* Lentry, struct ArgStruct* args,struct FieldList* fieldRef,struct AttrList* attrRef, struct tnode *l, struct tnode *r){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	
	if(c != NULL){
		node -> varname = strdup(c);
	}
	
	node -> val = val;
	node -> indices = indices;
	node -> dim = dim;
	node -> dtype = dtype;
	node -> ctype = ctype;
	node -> Gentry = Gentry;
	node -> Lentry = Lentry;
	node -> nodetype = nodetype;
	node -> fieldRef = fieldRef;
	node -> attrRef = attrRef;
	node -> left = l;
	node -> right = r;
	node -> args = args;
	return node;
}



struct tnode* makeIdNode(char* c, struct GSymbolTable* gst, struct LSymbolTable* lst, struct ArrayDims* indices, struct TypeTable* typeTable, struct ClassTable* classTable){

	struct Gsymbol* temp_g = GlobalLookup(gst,c);
	struct Lsymbol* temp_l = LocalLookup(lst,c);
	union Data emp_data;
	int dim;
	struct TypeTableEntry* dtype;
	struct ClassTableEntry* ctype;
	
	if(temp_g == NULL && temp_l == NULL){ //if entry does not exist in symbol table
		yyerror("Undefined Variable Referenced\n");
		exit(0);
	}else if(temp_l != NULL){
		temp_g = NULL;
		dim = dimRes(temp_l -> dim,indices);
		dtype = temp_l -> dtype;
		ctype = temp_l -> ctype;
	}else{
		temp_l = NULL;
		dim = dimRes(temp_g -> dim,indices);
		dtype = temp_g -> dtype;
		ctype = temp_g -> ctype;
	}
	
		
	if(dim < 0){
		printf("%s is not accessible to given dimension\n",c);
		exit(0);
	}
	
	return createTree(emp_data, c, dim, leaf_node, dtype, ctype, indices, temp_g, temp_l, NULL, NULL, NULL, NULL, NULL);
}

struct tnode* extendTypeNode(struct tnode* parent,char* child_name, struct TypeTable* typeTable, struct ClassTable* classTable){
	union Data emp_data;
	struct FieldList* fl = NULL;
	struct AttrList* attr = NULL;
	
	if(parent -> dtype != NULL){
		fl = FLookup(parent -> dtype -> fieldList,child_name);
		if(fl == NULL){
			printf("Error: %s field does not exist",child_name);
			exit(0);
		}
	}
	else if(parent -> ctype != NULL){
		attr = ALookup(parent -> ctype -> attrList,child_name);
		if(attr == NULL){
			printf("Error: %s field does not exist",child_name);
			exit(0);
		}
	}
	
	
	struct tnode* temp = parent;
	while(temp -> left != NULL){
		temp -> dtype = (fl == NULL) ? attr -> dtype : fl -> dtype;
		temp -> ctype = (attr == NULL) ? NULL : attr -> ctype;
		temp = temp -> left;
	}
	
	temp -> dtype = (fl == NULL) ? attr -> dtype : fl -> dtype;
	temp -> ctype = (attr == NULL) ? NULL : attr -> ctype;
	
	temp -> left = createTree(emp_data, child_name, fl -> dim, leaf_node, (fl == NULL) ? attr -> dtype : fl -> dtype, (attr == NULL) ? NULL : attr -> ctype, NULL, NULL, NULL, NULL, fl, attr, NULL, NULL);
	return parent;
}


struct tnode* makeFuncNode(char* c, struct GSymbolTable* gst, struct ArgStruct* args){

	struct Gsymbol* temp_g = GlobalLookup(gst,c);
	union Data emp_data;
	
	
	if(temp_g == NULL){//if entry does not exist in symbol table
		yyerror("Undefined Variable Referenced (Func)\n");
		exit(0);
	}
	
	struct ArgStruct* temp_arg = args;
	struct ParamStruct* temp_p = temp_g -> params;
	
	while(temp_arg != NULL && temp_p != NULL){
		if(temp_arg -> arg -> dtype != temp_p -> dtype || temp_arg -> arg -> ctype != temp_p -> ctype){
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
	
	return createTree(emp_data, c, 0, func_node, temp_g -> dtype, temp_g -> ctype, NULL, temp_g, NULL, args, NULL, NULL, NULL, NULL);
}



struct tnode* makeNumNode(int n, int dim, struct TypeTable* table){
	union Data data;
	data.num = n;
	return createTree(data,NULL, dim, leaf_node, TLookup(table,"int"), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

struct tnode* makeStringNode(char* str, struct TypeTable* table){
	union Data data;
	data.str = str;
	return createTree(data, NULL, 0, leaf_node, TLookup(table,"string"), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

struct tnode* makeNullNode(struct TypeTable* table){
	union Data emp_data;
	return createTree(emp_data,NULL, 0, leaf_node, TLookup(table,"null"), NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}


struct tnode* makeAddrNode(struct tnode* node, struct GSymbolTable* gst, struct LSymbolTable* lst, struct TypeTable* table){
	struct Gsymbol* temp_g = GlobalLookup(gst,node -> varname);
	struct Lsymbol* temp_l = LocalLookup(lst,node -> varname);
	union Data data;
	int binding;
	int dim;
	
	if(temp_g == NULL && temp_l == NULL){ //if entry does not exist in symbol table
		yyerror("Undefined Variable Referenced\n");
		exit(0);
	}else if(temp_l != NULL){
		dim = temp_l -> dim + 1;
		binding = temp_l -> binding;
	}else{
		dim = temp_g -> dim + 1;
		binding = temp_g -> binding;
	}
		
	data.num = binding;
	return createTree(data, NULL, dim, leaf_node, node -> dtype, node -> ctype, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);	
}

struct tnode* makePtrNode(struct tnode* node, struct TypeTable* table){
	union Data emp_data;
	if(node -> dim == 0){
		printf("Invalid derefencing (*)");
		exit(0);
	}
	struct TypeTableEntry* dtype = node -> dim - 1 == 0 ? node -> dtype : TLookup(table,"int");
	struct ClassTableEntry* ctype = (dtype == NULL) ? node -> ctype : NULL;
	return createTree(emp_data, NULL, node -> dim-1,ptr_node, dtype, ctype, NULL, NULL, NULL, NULL, NULL, NULL, node, NULL);	
}


struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r, struct TypeTable* typeTable){

	int dim = -1;
	struct TypeTableEntry* dtype = NULL;
	struct ClassTableEntry* ctype = NULL;

	switch(op){
		case add:
		case sub:
		case mul:
		case div:
		case mod:	
				if(isOperable(l,r,typeTable) == True){
					dtype = l -> dtype;
					ctype = l -> ctype;
					dim = l -> dim > r -> dim ? l -> dim : r -> dim;
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				
				break;
				
		case assign:	
				switch(r -> nodetype){
				
					case alloc_node : if(isMemAssignable(l) == True)
								dtype = TLookup(typeTable,"void");
							else{
								printf("Error: Memory cannot be assigned");
								exit(0);
							}
							break;
						
					default:
							if(l -> dim > 0 && l -> Gentry != NULL && l -> Gentry -> shape != NULL){
								printf("Error: Assignment to expression with array type");
								exit(0);
							}
							else if((l -> dtype == r -> dtype) && (l -> ctype == r -> ctype) && ((l -> dim > 0 && r -> dim > 0)||(l -> dim == 0 && r -> dim == 0))){
								dtype = TLookup(typeTable,"void");
							}
							else if(isMemAssignable(l) == True && (r -> dtype != NULL && strcmp(r -> dtype -> type_name,"null") == 0)){ // assigning to null
								dtype = TLookup(typeTable,"void");
							}
							else{
								printf("Error: Type Mismatch(op: %d)\n",op);
								exit(1);
							}	
							
				}	
				break;
				
		case gt:
		case gte:
		case lt:
		case lte:	if((l -> dtype != NULL && r -> dtype != NULL && strcmp(l -> dtype -> type_name, "int") == 0 && strcmp(r -> dtype -> type_name, "int") == 0)){
					dtype = TLookup(typeTable,"bool");
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				break;
		
		case eq:
		case neq:	
				if((r -> dtype == l -> dtype && r -> ctype == l -> ctype && r -> dim == l -> dim) || (isMemAssignable(l) == True && r -> dtype != NULL && strcmp(r -> dtype -> type_name,"null") == 0)){
					dtype = TLookup(typeTable,"bool");
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				break;
		
		case and:
		case or:
				if((l -> dtype != NULL && r -> dtype != NULL && strcmp(l -> dtype -> type_name, "bool") == 0 && strcmp(r -> dtype -> type_name, "bool") == 0)){
					dtype = l -> dtype;
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				break;
	}
	
	union Data emp_data;
	return createTree(emp_data,NULL,dim, op, dtype, ctype, NULL, NULL, NULL, NULL, NULL, NULL, l, r);
}


struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r){
	union Data emp_data;
	return createTree(emp_data, NULL,-1, connector, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, l, r);
}

struct tnode* makeReadNode(struct tnode *l){ // if a memory location is not passed in it will cause a runtime error
	union Data emp_data;
	if(l -> dim != 0){
		printf("Error: Reading of variable not possible");
		exit(0);
	}
	return createTree(emp_data,NULL,l -> dim, read, NULL, NULL, NULL,NULL, NULL, NULL,NULL, NULL, l,NULL);
}

struct tnode* makeWriteNode(struct tnode *l){ // write node has only left child
	union Data emp_data;
	return createTree(emp_data,NULL,l -> dim, write,NULL, NULL, NULL,NULL, NULL, NULL,NULL, NULL, l,NULL);
}

struct tnode* makeAllocNode(){ 
	union Data emp_data;
	return createTree(emp_data,NULL,0,alloc_node,NULL,NULL,NULL,NULL, NULL, NULL,NULL, NULL,NULL,NULL);
}

struct tnode* makeFreeNode(struct tnode *l,struct TypeTable* table){ 
	union Data emp_data;
	return createTree(emp_data,NULL,l -> dim,free_node,TLookup(table,"int"),NULL,NULL,NULL, NULL, NULL,NULL,NULL,l,NULL);
}

struct tnode* makeMemInitNode(struct TypeTable* table){ 
	union Data emp_data;
	return createTree(emp_data,NULL,0,mem_init_node,TLookup(table,"int"),NULL,NULL,NULL, NULL, NULL,NULL, NULL,NULL,NULL);
}

struct tnode* makeJumpNode(node_type nodetype){
	union Data emp_data;
	return createTree(emp_data, NULL,-1, nodetype, NULL, NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL);
}

struct tnode* makeReturnNode(struct tnode* t){
	union Data emp_data;
	return createTree(emp_data, NULL,t -> dim,return_node,NULL,NULL,NULL, NULL, NULL,NULL, NULL,NULL,t,NULL);
}

struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node){// left child is condition, right child is connector (left: if, right: else)
	union Data emp_data;
	struct tnode* node1 = createTree(emp_data, NULL,-1,then_else_node, NULL,NULL,NULL, NULL, NULL, NULL, NULL,NULL,then_node,else_node);
	struct tnode* node2 = createTree(emp_data, NULL,-1,if_node,NULL,NULL,NULL, NULL, NULL, NULL, NULL,NULL,cond,node1);
	return node2;
}

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,-1,while_node,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, cond, body);
}

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,-1, do_while, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, cond, body);
}



/*--------------------------------- Helper functions ---------------------------------------------*/

struct ArrayDims* addArrayDim(struct ArrayDims* node, struct tnode* t){
	struct ArrayDims* new_node = (struct ArrayDims*)malloc(sizeof(struct ArrayDims));
	new_node -> node = t;
	new_node -> next = NULL;
	
	struct ArrayDims* temp = node;
	if(temp == NULL)
		node = new_node;
	else{
		while(temp -> next != NULL)	
			temp = temp -> next;
		temp -> next = new_node;
	}
	
	return node;
}

int dimRes(int dim, struct ArrayDims* indices){
	struct ArrayDims* temp = indices;
	while(temp != NULL){
		dim -= 1;
		temp = temp -> next;
	}
	return dim;
}


boolean isMemAssignable(struct tnode* node){
	struct TypeTableEntry* dtype = node -> dtype;
	if(dtype != NULL && (strcmp(dtype -> type_name, "null") == 0 || strcmp(dtype -> type_name, "void") == 0))
		return False;
	
	if((dtype != NULL && strcmp(dtype -> type_name, "int") == 0 || strcmp(dtype -> type_name, "string") == 0) && (node -> dim <= 0 || node -> indices != NULL)) //tuple to be added
		return False;
	
	return True;
}


boolean isOperable(struct tnode* left, struct tnode* right, struct TypeTable* table){
	
	struct TypeTableEntry *dtype_l, *dtype_r;
	
	if(left -> dim > 0)
		dtype_l = TLookup(table,"int");
	else
		dtype_l = left -> dtype;
	
	if(right -> dim > 0)
		dtype_r = TLookup(table,"int");
	else
		dtype_r = right -> dtype;
	
	if((dtype_l != NULL && dtype_r != NULL && strcmp(dtype_l -> type_name, "int") == 0 && strcmp(dtype_r -> type_name, "int") == 0) && (right -> dim == 0 || left -> dim == 0))
		return True;
	
	return False;
	
	
}