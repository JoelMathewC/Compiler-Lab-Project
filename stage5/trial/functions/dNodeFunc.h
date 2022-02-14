struct dnode* createDTree(char* c, int dim, node_type nodetype, struct ArrayShape* shape, struct ParamStruct* params, struct dnode *l, struct dnode *r);

struct dnode* declIdNode(char* c, int dim, struct ArrayShape* shape);

struct dnode* declFuncNode(char*c, struct ParamStruct* params);

struct dnode* makeDConnectorNode(struct dnode *l,struct dnode *r);

struct dnode* makeDatatypeNode(int type,struct dnode *l);

struct ArrayShape* addArrayShape(struct ArrayShape* shape, int dim_val);
