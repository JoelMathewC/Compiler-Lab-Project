struct GSymbolTable{
	struct Gsymbol* head;
};

struct Gsymbol {
	char* name; //varname
	datatype dtype; //datatype
	int dim;
	int binding;
	int flabel; //label for identifying functions code
	
	struct ArrayShape* shape;
	struct ParamStruct *params; //points to parameter list for functions
	struct Gsymbol *next;
};

struct LSymbolTable{
	struct Lsymbol* head;
};

struct Lsymbol {
	char* name; //varname
	datatype dtype; //datatype
	int dim; // will be 0 or 1
	int binding;
	struct Lsymbol *next;
};






