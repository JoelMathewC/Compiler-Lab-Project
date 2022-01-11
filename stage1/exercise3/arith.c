

reg_index getReg(){
	return ++reg_num;
}

void freeReg(){
	--reg_num;
}

reg_index codeGen(struct tnode *t, FILE *fp){

	reg_index reg;
	
	if(t->op == NULL){ //leaf node
		reg = getReg();
		fprintf(fp,"MOV R%d, %d\n",reg,t->val);
	}
	else{ //internal node
		reg_index reg_l = codeGen(t->left,fp);
		reg_index reg_r = codeGen(t->right,fp);
		switch(*(t->op)){
		
			case '+': fprintf(fp,"ADD ");
				break;
			case '-': fprintf(fp,"SUB ");
				break;
			case '*': fprintf(fp,"MUL ");
				break;
			case '/': fprintf(fp,"DIV ");
				break;
		}
		
		freeReg(); //dropping the higher numbered register among right and left
		fprintf(fp,"R%d, R%d\n",reg_num,reg_num+1);
		
		reg = reg_l;
	}

	return reg;
	
}

