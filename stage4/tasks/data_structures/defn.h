//nodetype
#define leaf_node -1
#define connector 0
#define read 1
#define write 2
#define assign 3
#define add 4
#define sub 5
#define mul 6
#define div 7
#define gt 8
#define gte 9
#define lt 10
#define lte 11
#define eq 12
#define neq 13
#define if_node 20
#define then_else_node 21
#define while_node 22
#define do_while 23
#define break_node 24
#define continue_node 25
#define end 100

//type
#define boolType 0
#define intType 1 //this has been hardcoded in lex
#define stringType 2 //this has been hard coded in lex
#define intArrType 3
#define strArrType 4
#define noType 5

// Declaration of enum
typedef enum { False, True } boolean;
