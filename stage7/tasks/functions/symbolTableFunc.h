
struct Gsymbol* GlobalLookup(struct GSymbolTable* gst, char* name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

struct Lsymbol* LocalLookup(struct LSymbolTable* lst, char* name);

void GlobalInstall(struct GSymbolTable* gst, char* name, int dim, int nodetype, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct ArrayShape* shape, struct ParamStruct* params); // Creates a symbol table entry.

void LocalInstall(struct LSymbolTable* lst, char* name, int dim,int paramLoc, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype); 

void generateGlobalSymbolTable(struct GSymbolTable* gst, struct dnode* root, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct TypeTable* typeTable, struct ClassTable* classTable);

void addLocalVarToLST(struct LSymbolTable* lst, struct dnode* root, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct TypeTable* typeTable, struct ClassTable* classTable);

void printGlobalSymbolTable(struct GSymbolTable* gst);

void printLocalSymbolTable(struct LSymbolTable* lst);

int calculateMemory(struct ArrayShape* shape, int dim, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype);
