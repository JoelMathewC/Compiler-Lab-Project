struct dnode* createDTree(char* c, int dim, int shape[2], node_type nodetype, struct dnode *l, struct dnode *r);

struct dnode* declIdNode(char* c, int dim, int shape[2]);

struct dnode* makeDConnectorNode(struct dnode *l,struct dnode *r);

struct dnode* makeDatatypeNode(int type,struct dnode *l);
