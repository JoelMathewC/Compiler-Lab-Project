struct tnode* createTree(union Data val, char* c, int index, int type, int nodetype, struct Gsymbol* Gentry, struct tnode *l, struct tnode *r){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	
	node -> val = val;
	node -> type = type;
	
	if(c != NULL){
		node -> varname = (char*)malloc(sizeof(char));
		strcpy(node -> varname,c);
	}
	
	node -> index = index;
	node -> Gentry = Gentry;
	node -> nodetype = nodetype;
	node -> left = l;
	node -> right = r;
	return node;
}

struct tnode* makeIdNode(char* c, struct SymbolTable* st, int index){

	struct Gsymbol* temp = Lookup(st,c);
	union Data emp_data;
	
	if(temp == NULL){
		yyerror("Undefined Variable Referenced\n");
		exit(0);
	}
	return createTree(emp_data, c, index, temp -> type, leaf_node, temp, NULL, NULL);
}


struct tnode* makeNumNode(int n){
	union Data data;
	data.num = n;
	return createTree(data,NULL,0,intType, leaf_node, NULL, NULL, NULL);
}

struct tnode* makeStringNode(char* str){
	union Data data;
	data.str = str;
	return createTree(data, NULL,0,stringType,leaf_node, NULL, NULL, NULL);
}



struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r){

	int type;

	switch(op){
		case add:
		case sub:
		case mul:
		case div:	
				if((l -> type == intType && r -> type == intType) || (l -> type == intArrType && validateArr(l) == True && r -> type == strArrType && validateArr(r) == True)){
					type = intType;
				}else{
					printf("Error: Type Mismatch\n");
					exit(1);
				}
				
				break;
				
		case assign:	
				if((l -> type == intType && r -> type == intType) || (l -> type == intArrType && validateArr(l) == True && r -> type == strArrType && validateArr(r) == True)){
					type = noType;
				}else{
					printf("Error: Type Mismatch\n");
					exit(1);
				}
				break;
				
		case gt:
		case gte:
		case lt:
		case lte:
		case eq:
		case neq:	
				if((l -> type == intType && r -> type == intType) || (l -> type == intArrType && validateArr(l) == True && r -> type == strArrType && validateArr(r) == True)){
					type = boolType;
				}else{
					printf("Error: Type Mismatch\n");
					exit(1);
				}
				break;
	}
	
	union Data emp_data;
	return createTree(emp_data,NULL,0,type , op, NULL, l, r);
}


struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r){
	union Data emp_data;
	return createTree(emp_data, NULL,0,noType, connector, NULL, l, r);
}

struct tnode* makeReadNode(struct tnode *l){ // read node has only a left child
	union Data emp_data;
	if(validateArr(l) == True)
		return createTree(emp_data,NULL,0,noType,read,NULL,l,NULL);
	else{
		printf("Error: Cannot Read into array\n");
		exit(1);
	}
}

struct tnode* makeWriteNode(struct tnode *l){ // write node has only left child
	union Data emp_data;
	if(validateArr(l) == True)
		return createTree(emp_data,NULL,0,noType,write,NULL,l,NULL);
	else{
		printf("Error: Cannot Write array\n");
		exit(1);
	}
}

struct tnode* makeJumpNode(int nodetype){
	union Data emp_data;
	return createTree(emp_data, NULL,0,noType, nodetype,NULL,NULL,NULL);
}

struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node){// left child is condition, right child is connector (left: if, right: else)
	union Data emp_data;
	struct tnode* node1 = createTree(emp_data, NULL,0,noType, then_else_node, NULL, then_node,else_node);
	struct tnode* node2 = createTree(emp_data, NULL,0,noType, if_node, NULL, cond,node1);
	return node2;
}

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,0,noType, while_node, NULL, cond, body);
}

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,0,noType, do_while, NULL, cond, body);
}


boolean validateArr(struct tnode* node){

	if(node -> index == -1){
		printf("Error: Array index missing\n");
		exit(1);
	}
	else if(node -> index >= node -> Gentry -> size){
		printf("Error: Index out of bounds\n");
		exit(1);
	}
	
	return True;
}







