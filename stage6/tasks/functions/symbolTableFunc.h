
struct Gsymbol* GlobalLookup(struct GSymbolTable* gst, char* name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

struct Lsymbol* LocalLookup(struct LSymbolTable* lst, char* name);

void GlobalInstall(struct GSymbolTable* gst, char* name, struct TypeTableEntry* dtype, int dim, struct ArrayShape* shape, struct ParamStruct* params, int nodetype); // Creates a symbol table entry.

void LocalInstall(struct LSymbolTable* lst, char* name, struct TypeTableEntry* dtype, int dim,int paramLoc); 

void generateGlobalSymbolTable(struct GSymbolTable* gst, struct dnode* root, struct TypeTableEntry* dtype, struct TypeTable* table);

void addLocalVarToLST(struct LSymbolTable* lst, struct dnode* root, struct TypeTableEntry* dtype, struct TypeTable* table);

void printGlobalSymbolTable(struct GSymbolTable* gst);

void printLocalSymbolTable(struct LSymbolTable* lst);

int calculateMemory(struct ArrayShape* shape, int dim);
