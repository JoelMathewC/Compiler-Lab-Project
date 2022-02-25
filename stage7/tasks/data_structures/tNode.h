union Data{
	int num;
	char* str;
};

struct tnode { 
	union Data val;		//data value stored in node
	char* varname;			//name of a variable for ID nodes 
	int dim;
	node_type nodetype;  		// information about non-leaf nodes - read/write/connector/+/* etc. 
	
	struct FieldList* fieldRef;	//reference to field in case of user defined types
	struct AttrList* attrRef; //reference to attribute in case of classes
	
	struct ClassTableEntry* ctype;
	struct TypeTableEntry* dtype;
	
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



