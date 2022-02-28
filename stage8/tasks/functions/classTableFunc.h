struct ClassTable* ClassTableCreate();

struct ClassTableEntry* CInstall(char* name, struct ClassTableEntry* parent);

struct ClassTableEntry* CLookup(struct ClassTable* table, char* name);


void addToClassTable(struct ClassTable* classTable, char* class_name, char* parent_name);

void addDeclToClassEntry(struct ClassTable* classTable, struct TypeTable* typeTable, struct dnode* root, char* class_name);

void generateClassAttrList(struct ClassTableEntry* class_entry, struct dnode* root, struct TypeTableEntry* field_dtype, struct ClassTableEntry* field_ctype, struct TypeTable* typeTable, struct ClassTable* classTable);


void printClassTable(struct ClassTable* table);

void verifyMethodHead(char* name, struct ParamStruct* params, struct TypeTableEntry* return_type, struct ClassTableEntry* ctype);


//--------------------------------------- ATTR FUNC ----------------------------------------------

struct AttrList* AInstall(char* varname, int dim, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype);

void addToClassAttrList(struct ClassTableEntry* entry, struct AttrList* new_node);

struct AttrList* ALookup(struct AttrList* attr, char* name);

//--------------------------------------------------- METHOD FUNC -----------------------------------


struct MethodList* MInstall(char* method_name, int flabel, boolean isInherited, struct TypeTableEntry* dtype, struct ParamStruct* params);

void addToClassMethodList(struct ClassTableEntry* entry, struct MethodList* new_node);

struct MethodList* MLookupWithArgs(struct MethodList* method, struct ArgStruct* args, char* name);

struct MethodList* MLookupWithParams(struct MethodList* method, struct ParamStruct* params, char* name);

boolean isSameFuncCall(struct MethodList* method,struct ArgStruct* args, char* name);

boolean isSameFuncDecl(struct MethodList* method_old, struct ParamStruct* new_params, char* new_method_name);
