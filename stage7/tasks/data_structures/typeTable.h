struct TypeTableEntry{
	char* type_name;
	int size;
	int nodetype; 
	struct FieldList* fieldList;
	struct TypeTableEntry* next;
};

struct TypeTable{
	struct TypeTableEntry* head;
};

struct FieldList{
	char* varname;
	int dim;
	int fieldIndex;
	
	struct TypeTableEntry* dtype;
	struct FieldList* next;
};


