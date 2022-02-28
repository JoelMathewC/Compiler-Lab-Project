struct ClassTableEntry{
	char* class_name;
	int classIndex;  // binding of virtual function table location will be 4096 + (classIndex + 8)
	int attrCount;
	int methodCount;
	struct ClassTableEntry* parent;
	struct AttrList* attrList;
	struct MethodList* methodList;
	struct ClassTableEntry* next;
};

struct ClassTable{
	struct ClassTableEntry* head;
};

struct MethodList{
	char* method_name;
	int methodIndex;
	int flabel;
	
	struct ParamStruct* params;
	struct TypeTableEntry* dtype; //return can only be from type Table
	struct MethodList* next;
};

struct AttrList{
	char* varname;
	int dim;
	int fieldIndex;
	
	struct ClassTableEntry* ctype;
	struct TypeTableEntry* dtype;
	struct AttrList* next;
};




