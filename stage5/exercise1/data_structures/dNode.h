struct dnode{
	char* varname;			//identifier name
	int dim;			// dimension in case of array (ranges from 0 to n)
	node_type nodetype;			//type of node (connector,intType,stringType,intArrType, stringArrType)
	
	struct ArrayShape* shape;	//shape of array, will have (dim + 1) elements
	struct ParamStruct *params;	//params in the case of functions
	struct dnode *left, *right;	
};


struct ArrayShape{
	int index;
	struct ArrayShape* next;
};




