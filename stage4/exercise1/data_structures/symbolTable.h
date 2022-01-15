struct SymbolTable{
	struct Gsymbol* head;
};

struct Gsymbol {
	char* name; //varname
	int type; //datatype
	int dim;
	int* shape;
	int binding;
	struct Gsymbol *next;
};
