struct dnode* createDTree(char* c, int dim, int shape[2], node_type nodetype, struct ParamStruct* params, struct dnode *l, struct dnode *r);

struct dnode* declIdNode(char* c, int shape_0, int shape_1, int dim);

struct dnode* declFuncNode(char*c, struct ParamStruct* params);

struct dnode* makeDConnectorNode(struct dnode *l,struct dnode *r);

struct dnode* makeDatatypeNode(int type,struct dnode *l);
