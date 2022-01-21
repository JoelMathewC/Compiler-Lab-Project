struct SymbolTable{
	struct Gsymbol* head;
};

struct Gsymbol {
	char* name; //varname
	datatype dtype; //datatype
	int dim;
	int* shape;
	int binding;
	struct Gsymbol *next;
};
