union Data{
	int num;
	char* str;
};

struct tnode { 
	union Data val;		//data value stored in node
	char* varname;			//name of a variable for ID nodes 
	int dim;
	node_type nodetype;  		// information about non-leaf nodes - read/write/connector/+/* etc. 
	
	struct ClassTableEntry* classRef; // refer to class entry when attribute is being accessed
	struct TypeTableEntry* typeRef; // refer to type entry when attribute is being accessed
	
	struct FieldList* fieldRef;
	struct AttrList* attrRef;
	struct MethodList* methodRef;
	
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



