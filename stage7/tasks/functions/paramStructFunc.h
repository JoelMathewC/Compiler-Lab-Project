struct ParamStruct* addParameter(struct ParamStruct* pt,struct ParamStruct* node);

struct ParamStruct* makeParamStruct(char* name, char* type, int dim, struct TypeTable* typeTable, struct ClassTable* classTable);

struct FieldList* makeFieldListFromParam(struct ParamStruct* pt);

struct ArgStruct* addArgument(struct ArgStruct* args, struct ArgStruct* node);

struct ArgStruct* makeArgStruct(struct tnode* expr);

struct tnode* popArgStack(struct ArgStack* st);

void pushArgStack(struct ArgStack* st, struct tnode* node);


