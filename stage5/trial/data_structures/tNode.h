union Data{
	int num;
	char* str;
};

struct tnode { 
	union Data val;		//data value stored in node
	char* varname;			//name of a variable for ID nodes 
	int dim;
	datatype dtype;		//datatype of variable (int,bool,string,intArrType,strArrType) 
	node_type nodetype;  		// information about non-leaf nodes - read/write/connector/+/* etc. 
	
	struct ArrayDims* indices;
	struct Gsymbol *Gentry; 	//pointer to entry in global symbol table
	struct Lsymbol *Lentry;	//pointer to entry in local symbol table
	struct ArgStruct *args;	//arguments for functions
	struct tnode *left,*right;	//left and right branches   
};


struct ArrayDims{
	struct tnode* node;
	struct ArrayDims* next;
};



