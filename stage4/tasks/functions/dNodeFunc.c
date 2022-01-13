struct dnode* createDTree(char* c, int size, int nodetype, struct dnode *l, struct dnode *r){
	struct dnode* node;
	node = (struct dnode*)malloc(sizeof(struct dnode));
	
	if(c != NULL)
		node -> varname = strdup(c);
	else
		node -> varname = NULL;
	
	node -> size = size;
	node -> nodetype = nodetype;
	node -> left = l;
	node -> right = r;
	return node;
}

struct dnode* declIdNode(char* c, int size){
	return createDTree(c,size,leaf_node,NULL,NULL);
}

struct dnode* makeDConnectorNode(struct dnode *l,struct dnode *r){
	return createDTree(NULL,0, connector, l, r);
}

struct dnode* makeDatatypeNode(int type,struct dnode *l){ //datatype nodes have only a left child
	return createDTree(NULL,0,type,l,NULL);
}
