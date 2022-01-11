struct labelElem{
	char* label_name;
	int addr;
	struct labelElem *next;
};

struct labelAddrTable{
	struct labelElem *head;
};

void addLabelToTable(struct labelAddrTable *lat, char* label_name, int addr);

int searchLabel(struct labelAddrTable *lat,char* label);
