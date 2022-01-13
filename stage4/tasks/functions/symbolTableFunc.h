int getVarLoc(struct tnode* t);

struct Gsymbol* Lookup(struct SymbolTable* st,char* name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(struct SymbolTable* st,char* name, int type, int size); // Creates a symbol table entry.

void generateSymbolTable(struct SymbolTable* st, struct dnode* root, int dtype);

void printSymbolTable(struct SymbolTable* st);
