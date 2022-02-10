struct GSymbolTable{
	struct Gsymbol* head;
};

struct Gsymbol {
	char* name; //varname
	datatype dtype; //datatype
	int dim;
	int* shape;
	int binding;
	int flabel; //label for identifying functions code
	struct ParamStruct *params; //points to parameter list for functions
	struct Gsymbol *next;
};

struct LSymbolTable{
	struct Lsymbol* head;
};

struct Lsymbol {
	char* name; //varname
	datatype dtype; //datatype
	int binding;
	struct Lsymbol *next;
};






