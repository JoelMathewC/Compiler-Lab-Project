union Data{
	int num;
	char* str;
};

struct tnode { 
	union Data val;		//data value stored in node
	char* varname;			//name of a variable for ID nodes 
	int index; 			//index position in the array
	int type;			//datatype of variable (int,bool,string,intArrType,strArrType) 
	int nodetype;  		// information about non-leaf nodes - read/write/connector/+/* etc. 
	struct Gsymbol *Gentry; 	//pointer to entry in global symbol table
	struct tnode *left,*right;	//left and right branches   
};



