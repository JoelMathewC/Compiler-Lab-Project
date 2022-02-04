/*Points to note

	1. In the case of read and write, the right subtree will be NULL

*/

/*Create a node tnode*/
struct tnode* createTree(union Data val, char* c, struct tnode* index1, struct tnode* index2, datatype type, node_type nodetype, struct Gsymbol* Gentry, struct Lsymbol* Lentry, struct tnode *l, struct tnode *r);




struct tnode* makeIdNode(char* c, struct GSymbolTable* gst, struct LSymbolTable* lst, struct tnode* index1, struct tnode* index2);

struct tnode* makeNumNode(int n);

struct tnode* makeStringNode(char* str);

struct tnode* makePtrIdNode(struct tnode* ptr, struct GSymbolTable* gst, struct tnode* addr);
	

struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r);

struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r);


struct tnode* makeReadNode(struct tnode *l);

struct tnode* makeWriteNode(struct tnode *l);


struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node);

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body);

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body);

struct tnode* makeJumpNode(node_type nodetype);

boolean isSymbolPtr(struct Gsymbol* g);

boolean isValPtr(struct tnode* g);

/*boolean validateArr(struct tnode* node);*/

/*boolean validateOper(struct tnode* node);*/




