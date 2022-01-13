reg_index getReg(){
	return ++reg_num;
}

int getLabel(){
	return ++label_num;
}

void freeReg(){
	--reg_num;
}

int getMemLoc(int amount){
	int start = memLoc + 1;
	memLoc += amount;
	return start;
}

