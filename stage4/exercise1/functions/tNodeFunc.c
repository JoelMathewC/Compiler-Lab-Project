struct tnode* createTree(union Data val, char* c, struct tnode* index1, struct tnode* index2, int type, int nodetype, struct Gsymbol* Gentry, struct tnode *l, struct tnode *r){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	
	node -> val = val;
	node -> type = type;
	
	if(c != NULL){
		node -> varname = (char*)malloc(sizeof(char));
		strcpy(node -> varname,c);
	}
	
	node -> index1 = index1;
	node -> index2 = index2;
	
	node -> Gentry = Gentry;
	node -> nodetype = nodetype;
	node -> left = l;
	node -> right = r;
	return node;
}

struct tnode* makeIdNode(char* c, struct SymbolTable* st, struct tnode* index1, struct tnode* index2){

	struct Gsymbol* temp = Lookup(st,c);
	union Data emp_data;
	
	if(temp == NULL){
		yyerror("Undefined Variable Referenced\n");
		exit(0);
	}
	return createTree(emp_data, c, index1, index2, temp -> type, leaf_node, temp, NULL, NULL);
}


struct tnode* makeNumNode(int n){
	union Data data;
	data.num = n;
	

	return createTree(data,NULL, NULL, NULL,intType, leaf_node, NULL, NULL, NULL);
}

struct tnode* makeStringNode(char* str){
	union Data data;
	data.str = str;
	
	struct tNode* index[2];
	return createTree(data, NULL, NULL, NULL, stringType,leaf_node, NULL, NULL, NULL);
}



struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r){

	int type;

	switch(op){
		case add:
		case sub:
		case mul:
		case div:
		case mod:	
				if(validateOper(l) == True && validateOper(r) == True){
					type = intType;
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				
				break;
				
		case assign:	
				if(validateOper(l) == True && validateOper(r) == True){
					type = noType;
				}else{
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
				if(validateOper(l) == True && validateOper(r) == True){
					type = boolType;
				}else{
					printf("Error: Type Mismatch(op: %d)\n",op);
					exit(1);
				}
				break;
	}
	
	union Data emp_data;
	return createTree(emp_data,NULL,NULL, NULL,type , op, NULL, l, r);
}


struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r){
	union Data emp_data;
	return createTree(emp_data, NULL,NULL,NULL,noType, connector, NULL, l, r);
}

struct tnode* makeReadNode(struct tnode *l){ // read node has only a left child
	union Data emp_data;
	if(l -> type == intType || l -> type == stringType || validateArr(l) == True)
		return createTree(emp_data,NULL,NULL,NULL,noType,read,NULL,l,NULL);
	else{
		printf("Error: Cannot Read into array\n");
		exit(1);
	}
}

struct tnode* makeWriteNode(struct tnode *l){ // write node has only left child
	union Data emp_data;
	if(l -> type == intType || l -> type == stringType || validateArr(l) == True)
		return createTree(emp_data,NULL,NULL,NULL,noType,write,NULL,l,NULL);
	else{
		printf("Error: Cannot Write array\n");
		exit(1);
	}
}

struct tnode* makeJumpNode(int nodetype){
	union Data emp_data;
	return createTree(emp_data, NULL,NULL,NULL,noType, nodetype,NULL,NULL,NULL);
}

struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node){// left child is condition, right child is connector (left: if, right: else)
	union Data emp_data;
	struct tnode* node1 = createTree(emp_data, NULL,NULL,NULL,noType, then_else_node, NULL, then_node,else_node);
	struct tnode* node2 = createTree(emp_data, NULL,NULL,NULL,noType, if_node, NULL, cond,node1);
	return node2;
}

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,NULL,NULL,noType, while_node, NULL, cond, body);
}

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body){ // left child condition, right condition is body
	union Data emp_data;
	return createTree(emp_data, NULL,NULL,NULL,noType, do_while, NULL, cond, body);
}


boolean validateArr(struct tnode* node){
	
	if(node -> type == intArrType || node -> type == strArrType){
		if(node -> Gentry -> dim == 1){ //1D
			if(node -> index1 == NULL){
				
				printf("Error: Array(%s) index missing. Dim: %d\n",node -> varname, node -> Gentry -> dim);
				exit(1);
			}
/*			else if(node -> index[0] >= node -> Gentry -> shape[0]){*/
/*				printf("Error: Index out of bounds\n");*/
/*				exit(1);*/
/*			}*/
		}
		else if(node -> Gentry -> dim == 2){ //2D
			if(node -> index2 == NULL){
				printf("Error: Array(%s) index missing. Dim: %d\n",node -> varname, node -> Gentry -> dim);
				exit(1);
			}
/*			else if(node -> index[0] >= node -> Gentry -> shape[0] || node -> index[1] >= node -> Gentry -> shape[1]){*/
/*				printf("Error: Index out of bounds\n");*/
/*				exit(1);*/
/*			}*/
		}
		return True;
	}
	return False;
}


boolean validateOper(struct tnode* node){
	if(node -> type == intType)
		return True;
	if(node -> type == intArrType && validateArr(node) == True)
		return True;
	return False;
}








