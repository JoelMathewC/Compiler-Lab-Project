struct tnode* createTree(union Data val, char* c, int dim, datatype dtype, node_type nodetype, struct ArrayDims* indices, struct Gsymbol* Gentry, struct Lsymbol* Lentry, struct ArgStruct* args,struct tnode *l, struct tnode *r){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	
	if(c != NULL){
		node -> varname = strdup(c);
	}
	
	node -> val = val;
	node -> indices = indices;
	node -> dim = dim;
	node -> dtype = dtype;
	node -> Gentry = Gentry;
	node -> Lentry = Lentry;
	node -> nodetype = nodetype;
	node -> left = l;
	node -> right = r;
	node -> args = args;
	return node;
}



struct tnode* makeIdNode(char* c, struct GSymbolTable* gst, struct LSymbolTable* lst, struct ArrayDims* indices){

	struct Gsymbol* temp_g = GlobalLookup(gst,c);
	struct Lsymbol* temp_l = LocalLookup(lst,c);
	union Data emp_data;
	int dim;
	int dtype;
	
	if(temp_g == NULL && temp_l == NULL){ //if entry does not exist in symbol table
		yyerror("Undefined Variable Referenced\n");
		exit(0);
	}else if(temp_l != NULL){
		temp_g = NULL;
		dim = dimRes(temp_l -> dim,indices);
		dtype = temp_l -> dtype;
	}else{
		temp_l = NULL;
		dim = dimRes(temp_g -> dim,indices);
		dtype = temp_g -> dtype;
	}
	
		
	if(dim < 0){
		printf("%s is not accessible to given dimension\n",c);
		exit(0);
	}
	
	return createTree(emp_data, c, dim,dtype, leaf_node, indices, temp_g, temp_l, NULL, NULL, NULL);
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
	
	return createTree(emp_data, c, -1,temp_g -> dtype, func_node, NULL, temp_g, NULL, args, NULL, NULL);
}



struct tnode* makeNumNode(int n, int dim){
	union Data data;
	data.num = n;
	return createTree(data,NULL, dim,intType, leaf_node, NULL, NULL, NULL, NULL, NULL, NULL);
}

struct tnode* makeStringNode(char* str){
	union Data data;
	data.str = str;
	return createTree(data, NULL, 0,stringType,leaf_node, NULL, NULL, NULL, NULL, NULL, NULL);
}


struct tnode* makeAddrNode(struct tnode* node, struct GSymbolTable* gst, struct LSymbolTable* lst){
	struct Gsymbol* temp_g = GlobalLookup(gst,node -> varname);
	struct Lsymbol* temp_l = LocalLookup(lst,node -> varname);
	union Data emp_data;
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
		
	return makeNumNode(binding, dim);
}

struct tnode* makePtrNode(struct tnode* node){
	union Data emp_data;
	if(node -> dim == 0 || (node -> dtype != intType && node -> dtype != stringType)){
		printf("Invalid derefencing (*)");
		exit(0);
	}
	return createTree(emp_data, NULL, node -> dim-1,node -> dtype,ptr_node, NULL, NULL, NULL, NULL, node, NULL);	
}


struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r){

	int type,dim = -1;

	switch(op){
		case add:
		case sub:
		case mul:
		case div:
		case mod:	
				if((l -> dtype == intType && r -> dtype == intType) && (l -> dim == 0 || r -> dim == 0)){
					type = intType;
					dim = l -> dim > r -> dim ? l -> dim : r -> dim;
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				
				break;
				
		case assign:	if(l -> dim > 0 && l -> Gentry != NULL && l -> Gentry -> shape != NULL){
					printf("Error: Assignment to expression with array type");
					exit(0);
				}
				else if((l -> dtype == r -> dtype) && ((l -> dim > 0 && r -> dim > 0)||(l -> dim == 0 && r -> dim == 0)))
					type = noType;
				else{
/*					printf("%s\n",l -> varname);*/
/*					printf("DIM %d : %d\n",l -> Gentry -> dim, r -> dim);*/
/*					printf("DTYPE %d : %d\n", l -> dtype, r -> dtype);*/
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
		
		case and:
		case or:
				if(l -> dtype == boolType && r -> dtype == boolType){
					type = boolType;
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				break;
	}
	
	union Data emp_data;
	return createTree(emp_data,NULL,dim,type , op, NULL, NULL, NULL, NULL, l, r);
}


struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r){
	union Data emp_data;
	return createTree(emp_data, NULL,-1,noType, connector, NULL, NULL, NULL, NULL, l, r);
}

struct tnode* makeReadNode(struct tnode *l){ // if a memory location is not passed in it will cause a runtime error
	union Data emp_data;
	if(l -> dim != 0){
		printf("Error: Reading of variable not possible");
		exit(0);
	}
	return createTree(emp_data,NULL,l -> dim,noType,read,NULL,NULL, NULL, NULL,l,NULL);
}

struct tnode* makeWriteNode(struct tnode *l){ // write node has only left child
	union Data emp_data;
	return createTree(emp_data,NULL,l -> dim,noType,write,NULL,NULL, NULL, NULL,l,NULL);
}

struct tnode* makeJumpNode(node_type nodetype){
	union Data emp_data;
	return createTree(emp_data, NULL,-1,noType, nodetype, NULL, NULL, NULL,NULL, NULL,NULL);
}

struct tnode* makeReturnNode(struct tnode* t){
	union Data emp_data;
	return createTree(emp_data, NULL,t -> dim,noType,return_node,NULL, NULL, NULL,NULL, t,NULL);
}

struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node){// left child is condition, right child is connector (left: if, right: else)
	union Data emp_data;
	struct tnode* node1 = createTree(emp_data, NULL,-1,noType, then_else_node, NULL, NULL, NULL, NULL, then_node,else_node);
	struct tnode* node2 = createTree(emp_data, NULL,-1,noType, if_node, NULL, NULL, NULL, NULL, cond,node1);
	return node2;
}

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,-1,noType, while_node, NULL, NULL, NULL, NULL, cond, body);
}

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,-1,noType, do_while, NULL, NULL, NULL, NULL, cond, body);
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
