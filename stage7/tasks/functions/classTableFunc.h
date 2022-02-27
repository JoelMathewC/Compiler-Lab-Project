struct ClassTable* ClassTableCreate();

struct ClassTableEntry* CInstall(char* name, struct AttrList* attrList, struct MethodList* methodList, struct ClassTableEntry* parent);

struct ClassTableEntry* CLookup(struct ClassTable* table, char* name);


void addToClassTable(struct ClassTable* classTable, struct TypeTable* typeTable, struct dnode* root, char* class_name);

void generateClassAttrList(struct ClassTableEntry* class_entry, struct dnode* root, struct TypeTableEntry* field_dtype, struct ClassTableEntry* field_ctype, struct TypeTable* typeTable, struct ClassTable* classTable);


void printClassTable(struct ClassTable* table);

void verifyMethodHead(char* name, struct ParamStruct* params, struct TypeTableEntry* return_type, struct ClassTableEntry* ctype);


//--------------------------------------- ATTR FUNC ----------------------------------------------

struct AttrList* AInstall(char* varname, int dim, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype);

void addToClassAttrList(struct ClassTableEntry* entry, struct AttrList* new_node);

struct AttrList* ALookup(struct AttrList* attr, char* name);

//--------------------------------------------------- METHOD FUNC -----------------------------------


struct MethodList* MInstall(char* method_name, struct TypeTableEntry* dtype, struct ParamStruct* params);

void addToClassMethodList(struct ClassTableEntry* entry, struct MethodList* new_node);

struct MethodList* MLookup(struct MethodList* attr, char* name);
