reg_index getReg(){
	if(reg_num >= 19){
		printf("Error: Out of registers\n");
		exit(0);
	}
	return ++reg_num;
}

int getLabel(){
	return ++label_num;
}

int getFuncLabel(){
	return ++func_label_num;
}

void freeReg(){
	if(reg_num == 0){
		printf("Error: Freeing unacquired register\n");
		exit(0);
	}
	--reg_num;
}

int getMemLoc(int amount){
	int a = memLoc;
	memLoc += amount;
	return a + 1; //first of memory allocated
}

int getLocalMemLoc(){
	return ++localMemLoc;
}
