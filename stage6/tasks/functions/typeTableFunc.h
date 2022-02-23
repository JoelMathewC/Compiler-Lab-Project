struct TypeTable* TypeTableCreate();

struct TypeTableEntry* TInstall(char* name,int size, struct FieldList* fl);

int GetSize(struct TypeTable* table, char* name);

struct TypeTableEntry* TLookup(struct TypeTable* table, char* name);

struct FieldList* FLookup(struct FieldList* fl, char* name);


void addToTypeTable(struct TypeTable* table, struct dnode* root, char* type_name);

int calculateDtypeSize(struct FieldList* fl, struct TypeTable* table);

struct FieldList* FInstall(char* varname, int dim, int fieldIndex, struct TypeTableEntry* dtype);

void addToFieldList(struct TypeTableEntry* entry, struct FieldList* new_node);

void generateFieldList(struct TypeTableEntry* type_entry, struct dnode* root, struct TypeTableEntry* field_dtype, struct TypeTable* table);

void printTypeTable(struct TypeTable* table);
