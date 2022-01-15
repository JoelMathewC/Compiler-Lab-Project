union Data{
	int num;
	char* str;
};

struct tnode { 
	union Data val;		//data value stored in node
	char* varname;			//name of a variable for ID nodes 
	
	struct tnode* index1; 		//index 1 position in the array
	struct tnode* index2;		//index 2
	
	datatype dtype;			//datatype of variable (int,bool,string,intArrType,strArrType) 
	node_type nodetype;  		// information about non-leaf nodes - read/write/connector/+/* etc. 
	struct Gsymbol *Gentry; 	//pointer to entry in global symbol table
	struct tnode *left,*right;	//left and right branches   
};



