struct SymbolTable{
	struct Gsymbol* head;
};

struct Gsymbol {
	char* name; //varname
	int type; //datatype
	int size;
	int binding;
	struct Gsymbol *next;
};
