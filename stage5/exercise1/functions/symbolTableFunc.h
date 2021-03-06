
struct Gsymbol* GlobalLookup(struct GSymbolTable* gst, char* name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

struct Lsymbol* LocalLookup(struct LSymbolTable* lst, char* name);

void GlobalInstall(struct GSymbolTable* gst, char* name, datatype type, int dim, struct ArrayShape* shape, struct ParamStruct* params, int nodetype); // Creates a symbol table entry.

void LocalInstall(struct LSymbolTable* lst, char* name, datatype dtype, int dim,int paramLoc); 

void generateGlobalSymbolTable(struct GSymbolTable* gst, struct dnode* root, datatype dtype);

void addLocalVarToLST(struct LSymbolTable* lst, struct dnode* root, datatype dtype);

void printGlobalSymbolTable(struct GSymbolTable* gst);

void printLocalSymbolTable(struct LSymbolTable* lst);

int calculateMemory(struct ArrayShape* shape, int dim);
