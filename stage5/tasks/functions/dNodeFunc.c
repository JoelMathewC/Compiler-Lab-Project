struct dnode* createDTree(char* c, int dim, node_type nodetype, struct ArrayShape* shape, struct ParamStruct* params, struct dnode *l, struct dnode *r){
	struct dnode* node = (struct dnode*)malloc(sizeof(struct dnode));
	
	if(c != NULL)
		node -> varname = strdup(c);
	else
		node -> varname = NULL;
	
	node -> shape = shape;
	node -> dim = dim;
	node -> nodetype = nodetype;
	node -> params = params;
	node -> left = l;
	node -> right = r;
	return node;
}

struct dnode* declIdNode(char* c, int dim, struct ArrayShape* shape){
	return createDTree(c,dim,leaf_node,shape,NULL,NULL,NULL);
}

struct dnode* declFuncNode(char*c, struct ParamStruct* params){ //dimension of functions is by default 0
	return createDTree(c,0,func_node,NULL,params,NULL,NULL);
}

struct dnode* makeDConnectorNode(struct dnode *l,struct dnode *r){
	return createDTree(NULL, 0,connector, NULL, NULL, l, r);
}

struct dnode* makeDatatypeNode(int type,struct dnode *l){ //datatype nodes have only a left child
	return createDTree(NULL,0,type, NULL,NULL, l,NULL);
}



struct ArrayShape* addArrayShape(struct ArrayShape* shape, int dim_val){

	if(dim_val <= 0){
		printf("Error: Invalid Index\n");
    		exit(0);
	}

	struct ArrayShape* node = (struct ArrayShape*)malloc(sizeof(struct ArrayShape));
	node -> index = dim_val;
	node -> next = NULL;

	struct ArrayShape* temp = shape;
	if(temp == NULL)
		shape = node;
	else{
		while(temp -> next != NULL)
			temp = temp -> next;
		temp -> next = node;
	}
	return shape;
}


