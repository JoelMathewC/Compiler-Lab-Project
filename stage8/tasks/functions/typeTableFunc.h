struct TypeTable* TypeTableCreate();

struct TypeTableEntry* TInstall(char* name,int size, int nodetype, struct FieldList* fl);

int GetSize(struct TypeTable* table, char* name);

struct TypeTableEntry* TLookup(struct TypeTable* table, char* name);

void addTupleToTypeTable(struct TypeTable* table, struct ParamStruct* pt, char* type_name);

void createTypeEntry(struct TypeTable* table, char* type_name);

void addUserDefToTypeTable(struct TypeTable* table, struct dnode* root, char* type_name);

int calculateDtypeSize(struct FieldList* fl, struct TypeTable* table);

void generateFieldList(struct TypeTableEntry* type_entry, struct dnode* root, struct TypeTableEntry* field_dtype, struct TypeTable* table);

void printTypeTable(struct TypeTable* table);

//--------------------------------------- FIELD FUNC ----------------------------------------------

struct FieldList* FInstall(char* varname, int dim, struct TypeTableEntry* dtype);

void addToFieldList(struct TypeTableEntry* entry, struct FieldList* new_node);

struct FieldList* FLookup(struct FieldList* fl, char* name);
