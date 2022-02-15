/*Points to note

	1. In the case of read and write, the right subtree will be NULL

*/

/*Create a node tnode*/
struct tnode* createTree(union Data val, char* c, int dim, datatype dtype, node_type nodetype, struct ArrayDims* indices, struct Gsymbol* Gentry, struct Lsymbol* Lentry, struct ArgStruct* args,struct tnode *l, struct tnode *r);

struct tnode* makeIdNode(char* c, struct GSymbolTable* gst, struct LSymbolTable* lst, struct ArrayDims* indices);

struct tnode* makeFuncNode(char* c, struct GSymbolTable* gst, struct ArgStruct* args);

struct tnode* makeNumNode(int n, int dim);

struct tnode* makeStringNode(char* str);

struct tnode* makeAddrNode(struct tnode* node, struct GSymbolTable* gst, struct LSymbolTable* lst);

struct tnode* makePtrNode(struct tnode* node);
	

struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r);

struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r);


struct tnode* makeReadNode(struct tnode *l);

struct tnode* makeWriteNode(struct tnode *l);


struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node);

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body);

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body);

struct tnode* makeJumpNode(node_type nodetype);

struct tnode* makeReturnNode(struct tnode* t);

struct ArrayDims* addArrayDim(struct ArrayDims* node, struct tnode* t);

int dimRes(int dim, struct ArrayDims* indices);




