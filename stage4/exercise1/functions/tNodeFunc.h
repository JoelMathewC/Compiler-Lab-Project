/*Points to note

	1. In the case of read and write, the right subtree will be NULL

*/

/*Create a node tnode*/
struct tnode* createTree(union Data val, char* c, struct tnode* index1, struct tnode* index2, int type, int nodetype, struct Gsymbol* Gentry, struct tnode *l, struct tnode *r);




struct tnode* makeIdNode(char* c, struct SymbolTable* st, struct tnode* index1, struct tnode* index2);

struct tnode* makeNumNode(int n);

struct tnode* makeStringNode(char* str);
	

struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r);

struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r);


struct tnode* makeReadNode(struct tnode *l);

struct tnode* makeWriteNode(struct tnode *l);


struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node);

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body);

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body);

struct tnode* makeJumpNode(int nodetype);

boolean validateArr(struct tnode* node);

boolean validateOper(struct tnode* node);




