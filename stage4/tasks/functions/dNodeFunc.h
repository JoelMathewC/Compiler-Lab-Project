struct dnode* createDTree(char* c, int size, int nodetype, struct dnode *l, struct dnode *r);

struct dnode* declIdNode(char* c, int size);

struct dnode* makeDConnectorNode(struct dnode *l,struct dnode *r);

struct dnode* makeDatatypeNode(int type,struct dnode *l);
