void loopStackPush(struct LoopStack *lp,int open_label, int close_label){
	struct LoopStackElem* elem = (struct LoopStackElem*)malloc(sizeof(struct LoopStackElem));
	elem -> open_label = open_label;
	elem -> close_label = close_label;
	elem -> next = NULL;
	
	if(lp -> top == NULL)
		lp -> top = elem;
	else{
		elem -> next = lp -> top;
		lp -> top = elem;
	}
}

struct LoopStackElem* loopStackPop(struct LoopStack *lp){
	if(lp == NULL)
		return NULL;
	
	struct LoopStackElem* elem = lp -> top;
	lp -> top = lp -> top -> next;
	return elem;
}
