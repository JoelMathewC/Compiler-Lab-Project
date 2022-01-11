

struct tnode* makeLeafNode(int n){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	node -> val = n;
	node -> op = NULL;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	node -> op = (char*)malloc(sizeof(char));
	*(node -> op) = c;
	node -> left = l;
	node -> right = r;
	return node;
}

int evaluate(struct tnode *t){

	if(t == NULL)
		return 0;
	
	if(t->left == NULL && t-> right==NULL)
		return t->val;
	
	switch(*(t->op)){
		case '+': return evaluate(t->left) + evaluate(t->right);
		case '-': return evaluate(t->left) - evaluate(t->right);
		case '*': return evaluate(t->left) * evaluate(t->right);
		case '/': return evaluate(t->left) / evaluate(t->right);
	}
}

void prefix(struct tnode *t){

	if(t == NULL)
		return;
	
	if(t -> left == NULL && t -> right == NULL){
		printf("%d ",t->val);
		return;
	}
	
	printf("%c ",*(t->op));
	prefix(t->left);
	prefix(t->right);
}


void postfix(struct tnode *t){

	if(t == NULL)
		return;
	
	if(t -> left == NULL && t -> right == NULL){
		printf("%d ",t->val);
		return;
	}
	
	postfix(t->left);
	postfix(t->right);
	printf("%c ",*(t->op));
	
}
