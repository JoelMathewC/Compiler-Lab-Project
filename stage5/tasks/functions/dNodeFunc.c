struct dnode* createDTree(char* c, int dim, int shape[2], node_type nodetype, struct dnode *l, struct dnode *r){
	struct dnode* node;
	node = (struct dnode*)malloc(sizeof(struct dnode));
	
	if(c != NULL)
		node -> varname = strdup(c);
	else
		node -> varname = NULL;
	
	node -> shape = shape;
	node -> dim = dim;
	node -> nodetype = nodetype;
	node -> left = l;
	node -> right = r;
	return node;
}

struct dnode* declIdNode(char* c,int dim, int shape[2]){
	return createDTree(c,dim,shape,leaf_node,NULL,NULL);
}

struct dnode* makeDConnectorNode(struct dnode *l,struct dnode *r){
	int emp_arr[2];
	return createDTree(NULL, 0,emp_arr,connector, l, r);
}

struct dnode* makeDatatypeNode(int type,struct dnode *l){ //datatype nodes have only a left child
	int emp_arr[2];
	return createDTree(NULL,0,emp_arr,type,l,NULL);
}
