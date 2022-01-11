struct tnode* createTree(int val, int type, char* c, int nodetype, struct tnode *l, struct tnode *r){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	
	node -> val = val;
	node -> type = type;
	node -> varname = c;
	node -> nodetype = nodetype;
	node -> left = l;
	node -> right = r;
	return node;
}

struct tnode* makeIdNode(char* c){ //ignore 0
	return createTree(0,intType, c,leaf_node, NULL, NULL);
}

struct tnode* makeNumNode(int n){
	return createTree(n,intType, NULL,leaf_node, NULL, NULL);
}



struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r){

	int type;
	
	if(l -> type != intType || r -> type != intType){
		printf("Error: Type Mismatch");
		exit(1);
	}

	switch(op){
		case add:
		case sub:
		case mul:
		case div:	type = intType;
				break;
		case assign:	type = noType;
				break;
		case gt:
		case gte:
		case lt:
		case lte:
		case eq:
		case neq:	type = boolType;
				break;
	}
	
	return createTree(0,type, NULL, op, l, r);
}


struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r){
	return createTree(0,noType, NULL, connector, l, r);
}

struct tnode* makeReadNode(struct tnode *l){
	return createTree(0,noType,NULL,read,l,NULL);
}

struct tnode* makeWriteNode(struct tnode *l){
	return createTree(0,noType,NULL,write,l,NULL);
}

struct tnode* makeJumpNode(int nodetype){
	return createTree(0,noType, NULL, nodetype, NULL, NULL);
}

struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node){
	struct tnode* node1 = createTree(0,noType, NULL, then_else_node, then_node,else_node);
	struct tnode* node2 = createTree(0,noType, NULL, if_node, cond,node1);
	return node2;
}

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body){
	return createTree(0,noType, NULL, while_node, cond, body);
}

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body){
	return createTree(0,noType, NULL, do_while, cond, body);
}



void preorder(struct tnode *t){
	
	if(t == NULL)
		return;
	
	switch(t -> nodetype){
		case leaf_node: printf("ID ");
			break;
		case connector: printf("CON ");
			break;
		case read: printf("READ ");
			break;
		case write: printf("WRITE ");
			break;
		case assign: printf("= ");
			break;
		case add: printf("+ ");
			break;
		case sub: printf("- ");
			break;
		case mul: printf("* ");
			break;
		case div: printf("/ ");
			break;
		case gt: printf("> ");
			break;
		case gte: printf(">= ");
			break;
		case lt: printf("< ");
			break;
		case lte: printf("<= ");
			break;
		case eq: printf("== ");
			break;
		case neq: printf("!= ");
			break;
		case if_node: printf("IF ");
			break;
		case then_else_node: printf("THEN ");
			preorder(t -> left);
			printf("ELSE ");
			preorder(t -> right);
			return;
		case while_node: printf("WHILE ");
			preorder(t -> left);
			printf("DO ");
			preorder(t -> right);
			return;
		case do_while: printf("DO ");
			preorder(t -> right);
			printf("WHILE ");
			preorder(t -> left);
			return;
		
		case break_node: printf("BREAK ");
			return;
		
		case continue_node: printf("CONTINUE ");
			return;
	}
	
	preorder(t -> left);
	preorder(t -> right);
}


int evaluate(struct tnode *t, int var[]){

	if(t == NULL)
		return 0;
	
	switch(t -> nodetype){
		case leaf_node: 
					if(t -> varname == NULL)
						return t -> val;
					else
						return var[*(t->varname) - 'a'];
					break;
			
		case connector:	evaluate(t -> left,var);
					evaluate(t -> right,var);
					break;
		
		case read: 		scanf("%d",&var[*(t->left->varname) - 'a']);
					break;
			
		case write: 		printf("%d\n",evaluate(t -> left,var));
					break;
			
		case assign: 		var[*(t->left->varname) - 'a'] = evaluate(t -> right,var);
					break;
				
		case add: 		return evaluate(t -> left,var) + evaluate(t -> right,var);

		case sub: 		return evaluate(t -> left,var) - evaluate(t -> right,var);

		case mul: 		return evaluate(t -> left,var) * evaluate(t -> right,var);

		case div: 		return evaluate(t -> left,var) / evaluate(t -> right,var);
		
		case gt:		return evaluate(t -> left,var) > evaluate(t -> right,var);
		
		case gte:		return evaluate(t -> left,var) >= evaluate(t -> right,var);
		
		case lt:		return evaluate(t -> left,var) < evaluate(t -> right,var);
		
		case lte:		return evaluate(t -> left,var) <= evaluate(t -> right,var);
		
		case eq:		return evaluate(t -> left,var) == evaluate(t -> right,var);
		
		case neq:		return evaluate(t -> left,var) != evaluate(t -> right,var);
		
		case if_node:	if(evaluate(t -> left,var)){
					evaluate(t -> right -> left,var);
				}else{
					if(t -> right -> right != NULL)
						evaluate(t -> right -> right,var);
				}
				break;
				
		case while_node:	while(evaluate(t -> left,var)){
						evaluate(t -> right,var);
					}
				break;
		
		case do_while:		do{
						evaluate(t -> right,var);
					}while(evaluate(t -> left,var));
					break;

	}
	
	return 0;
}






