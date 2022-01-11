struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r){
	struct tnode* node;
	node = (struct tnode*)malloc(sizeof(struct tnode));
	
	node -> val = val;
	node ->type = type;
	node -> varname = c;
	node -> left = l;
	node -> right = r;
	return node;
}

struct tnode* makeIdNode(char* c){ //ignore 0
	return createTree(0,-1, c, NULL, NULL);
}

struct tnode* makeNumNode(int n){
	return createTree(n,-1, NULL, NULL, NULL);
}



struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
	int num;
	switch(c){
		case '=': num = 3;
			break;
		case '+': num = 4;
			break;
		case '-': num = 5;
			break;
		case '*': num = 6;
			break;
		case '/': num = 7;
			break;
	}
	return createTree(0,num, NULL, l, r);
}


struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r){
	return createTree(0,0, NULL, l, r);
}

struct tnode* makeReadNode(struct tnode *l){
	return createTree(0,1,NULL,l,NULL);
}

struct tnode* makeWriteNode(struct tnode *l){
	return createTree(0,2,NULL,l,NULL);
}

void preorder(struct tnode *t){
	
	if(t == NULL)
		return;
	
	switch(t -> type){
		case -1: printf("ID ");
			break;
		case 0: printf("CON ");
			break;
		case 1: printf("READ ");
			break;
		case 2: printf("WRITE ");
			break;
		case 3: printf("= ");
			break;
		case 4: printf("+ ");
			break;
		case 5: printf("- ");
			break;
		case 6: printf("* ");
			break;
		case 7: printf("/ ");
			break;
	}
	
	preorder(t -> left);
	preorder(t -> right);
}


int evaluate(struct tnode *t, int var[]){

	if(t == NULL)
		return 0;
	
	switch(t -> type){
		case -1: 
				if(t -> varname == NULL)
					return t -> val;
				else
					return var[*(t->varname) - 'a'];
				break;
			
		case 0:	evaluate(t -> left,var);
				evaluate(t -> right,var);
				break;
		
		case 1: 	scanf("%d",&var[*(t->left->varname) - 'a']);
				break;
			
		case 2: 	printf("%d\n",evaluate(t -> left,var));
				break;
			
		case 3: 	var[*(t->left->varname) - 'a'] = evaluate(t -> right,var);
				break;
				
		case 4: 	return evaluate(t -> left,var) + evaluate(t -> right,var);

		case 5: 	return evaluate(t -> left,var) - evaluate(t -> right,var);

		case 6: 	return evaluate(t -> left,var) * evaluate(t -> right,var);

		case 7: 	return evaluate(t -> left,var) / evaluate(t -> right,var);

	}
	
	return 0;
}



