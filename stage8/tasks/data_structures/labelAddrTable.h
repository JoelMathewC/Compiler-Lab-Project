struct labelElem{
	char* label_name;
	int addr;
	struct labelElem *next;
};

struct labelAddrTable{
	struct labelElem *head;
};

