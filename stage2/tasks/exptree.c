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
	return createTree(0,noType, NULL, op, l, r);
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
	}
	
	preorder(t -> left);
	preorder(t -> right);
}




