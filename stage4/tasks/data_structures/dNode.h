struct dnode{
	char* varname;			//identifier name
	int size;			//size in the case of arrays
	int nodetype;			//type of node (connector,intType,stringType,intArrType, stringArrType)
	struct dnode *left, *right;	
};




