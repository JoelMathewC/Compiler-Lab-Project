/*Points to note

1. In the case of read and write, the right subtree will be NULL
2. type
	leaf node - (-1)
	connector - 0
	read - 1
	write - 2
	'=' - 3
	'+' - 4
	'-' - 5
	'*' - 6
	'/' - 7
*/

typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable 
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;

/*Create a node tnode*/
struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);


struct tnode* makeIdNode(char* c);
	

struct tnode* makeNumNode(int n);
	

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);


struct tnode* makeConnectorNode(struct tnode *l,struct tnode *r);


struct tnode* makeReadNode(struct tnode *l);

struct tnode* makeWriteNode(struct tnode *l);

void preorder(struct tnode *t);

/*To evaluate an expression tree*/
int evaluate(struct tnode *t, int var[]);
