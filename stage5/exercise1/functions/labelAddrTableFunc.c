void addLabelToTable(struct labelAddrTable *lat, char* label_name, int addr){


	*(label_name + strlen(label_name) - 2) = '\0';
	
	struct labelElem* elem = (struct labelElem*)malloc(sizeof(struct labelElem));
	
	elem -> label_name = (char*)malloc(sizeof(char));
	strcpy(elem -> label_name,label_name);
	elem -> addr = addr;
	elem -> next = NULL;
	

	
	struct labelElem *temp = lat -> head;
	if(temp == NULL){
		lat -> head = elem;
		return;
	}
	
	
	while(temp -> next != NULL)
		temp = temp -> next;
	
	temp -> next = elem;
}

int searchLabel(struct labelAddrTable *lat,char* label){
	
	char* label_name = (char*)malloc(sizeof(char));
	strcpy(label_name,label);
	*(label_name + strlen(label_name) - 1) = '\0';
	
	struct labelElem *temp = lat -> head;
	while(temp != NULL){
		if(strcmp(temp -> label_name,label_name) == 0){
			return temp -> addr;
		}
		temp = temp -> next;
	}
	return -1;
}
