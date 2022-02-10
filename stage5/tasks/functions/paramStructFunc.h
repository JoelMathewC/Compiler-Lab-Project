struct ParamStruct* addParameter(struct ParamStruct* pt,struct ParamStruct* node);

struct ParamStruct* makeParamStruct(char* name, datatype dtype);

struct ArgStruct* addArgument(struct ArgStruct* args, struct ArgStruct* node);

struct ArgStruct* makeArgStruct(struct tnode* expr);
