/*Points to note

	1. In the case of read and write, the right subtree will be NULL

*/

/*Create a node tnode*/
struct tnode* createTree(union Data val, char* c, int dim, node_type nodetype, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype, struct ArrayDims* indices, struct Gsymbol* Gentry, struct Lsymbol* Lentry, struct ArgStruct* args,struct FieldList* fieldRef,struct AttrList* attrRef, struct MethodList* methodRef, struct tnode *l, struct tnode *r);

struct tnode* makeIdNode(char* c, struct GSymbolTable* gst, struct LSymbolTable* lst, struct ArrayDims* indices, struct TypeTable* typeTable, struct ClassTable* classTable);

struct tnode* extendTypeNode(struct tnode* parent,char* child_name, struct TypeTable* typeTable, struct ClassTable* classTable);

struct tnode* makeFuncNode(char* c, struct GSymbolTable* gst, struct ArgStruct* args);

struct tnode* makeMethodNode(struct tnode* parent, char* method_name, struct ArgStruct* args, struct TypeTable* typeTable);

struct tnode* makeNumNode(int n, int dim, struct TypeTable* table);

struct tnode* makeStringNode(char* str, struct TypeTable* table);

struct tnode* makeNullNode(struct TypeTable* table);

struct tnode* makeAddrNode(struct tnode* node, struct GSymbolTable* gst, struct LSymbolTable* lst, struct TypeTable* table);

struct tnode* makePtrNode(struct tnode* node, struct TypeTable* table);
	

struct tnode* makeOperatorNode(int op,struct tnode *l,struct tnode *r, struct TypeTable* typeTable);

struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r);


struct tnode* makeReadNode(struct tnode *l);

struct tnode* makeWriteNode(struct tnode *l);

struct tnode* makeAllocNode();

struct tnode* makeFreeNode(struct tnode *l,struct TypeTable* table);

struct tnode* makeMemInitNode(struct TypeTable* table);


struct tnode* makeIfElseBlock(struct tnode* cond, struct tnode* then_node, struct tnode* else_node);

struct tnode* makeWhileBlock(struct tnode* cond, struct tnode* body);

struct tnode* makeDoWhileBlock(struct tnode* cond, struct tnode* body);

struct tnode* makeJumpNode(node_type nodetype);

struct tnode* makeReturnNode(struct tnode* t);

/*--------------------------------- Helper functions ---------------------------------------------*/

struct ArrayDims* addArrayDim(struct ArrayDims* node, struct tnode* t);

int dimRes(int dim, struct ArrayDims* indices);

boolean isMemAssignable(struct tnode* node);

boolean isOperable(struct tnode* left, struct tnode* right, struct TypeTable* table);



