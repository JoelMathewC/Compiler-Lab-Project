struct dnode* createDTree(char* c, int dim, int shape[2], int nodetype, struct dnode *l, struct dnode *r);

struct dnode* declIdNode(char* c, int dim, int shape[2]);

struct dnode* makeDConnectorNode(struct dnode *l,struct dnode *r);

struct dnode* makeDatatypeNode(int type,struct dnode *l);
