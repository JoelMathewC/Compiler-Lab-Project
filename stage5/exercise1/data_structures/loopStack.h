struct LoopStack{
	struct LoopStackElem *top;
};

struct LoopStackElem{
	int open_label;
	int close_label;
	struct LoopStackElem *next;
};

