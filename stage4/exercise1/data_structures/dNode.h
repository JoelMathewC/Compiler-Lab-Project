struct dnode{
	char* varname;			//identifier name
	int* shape;			//shape of array (only 0th indice is used if 1D)
	int dim;			// dimension in case of array
	int nodetype;			//type of node (connector,intType,stringType,intArrType, stringArrType)
	struct dnode *left, *right;	
};




