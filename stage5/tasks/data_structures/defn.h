//nodetype
typedef  int node_type;
#define func_node -2
#define leaf_node -1
#define connector 0
#define read 1
#define write 2
#define assign 3
#define add 4
#define sub 5
#define mul 6
#define div 7
#define mod 8
#define gt 9
#define gte 10
#define lt 11
#define lte 12
#define eq 13
#define neq 14
#define and 15
#define or 16
#define if_node 20
#define then_else_node 21
#define while_node 22
#define do_while 23
#define break_node 24
#define continue_node 25
#define return_node 26
#define end 100

//datatype
typedef int datatype;
#define boolType 0
#define intType 1 //this has been hardcoded in lex
#define stringType 2 //this has been hard coded in lex
#define intSingleArrType 3 //One  dimensional array
#define strSingleArrType 4 //One  dimensional array
#define intDoubleArrType 5 //Two  dimensional array
#define strDoubleArrType 6 //Two  dimensional array
#define intPtrType 7
#define strPtrType 8
#define noType 9

//SymbolTable Type
#define global 1
#define local 2

// Declaration of enum
typedef enum { False, True } boolean;
