
struct Gsymbol* Lookup(struct SymbolTable* st,char* name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(struct SymbolTable* st,char* name, datatype type, int dim, int shape[2]); // Creates a symbol table entry.

void generateSymbolTable(struct SymbolTable* st, struct dnode* root, datatype dtype);

void printSymbolTable(struct SymbolTable* st);
