

reg_index getReg(){
	return ++reg_num;
}

void freeReg(){
	--reg_num;
}

int getVarLoc(char* varname){
	return 4096 + *varname - 'a';
}

reg_index oper_code_gen(struct tnode *t, FILE *fp){

	//printf("op code start\n");
	//fflush(stdout);

	reg_index reg;
	reg_index reg_l;
	reg_index reg_r;
	
	if(t->type == -1){ //leaf node
		reg = getReg();
		if(t -> varname != NULL)
			fprintf(fp,"MOV R%d, [%d]\n",reg, getVarLoc(t -> varname));
		else
			fprintf(fp,"MOV R%d, %d\n",reg,t->val);
		
	}
	else{ //internal node
	

		reg_l = oper_code_gen(t->left,fp);
		reg_r = oper_code_gen(t->right,fp);
		switch(t -> type){
			
			//add
			case 4: fprintf(fp,"ADD ");
				break;
			
			//subtract
			case 5: fprintf(fp,"SUB ");
				break;
				
			//multiply
			case 6: fprintf(fp,"MUL ");
				break;
				
			//divide
			case 7: fprintf(fp,"DIV ");
				break;
		}
		
		freeReg(); //dropping the higher numbered register among right and left
		fprintf(fp,"R%d, R%d\n",reg_num,reg_num+1);
		
		reg = reg_l;
	
	}
	
	//printf("op code end\n");
	//fflush(stdout);

	return reg;
	
}

void lib_code_gen(char func, int loc_reg, FILE *fp){

	//loc_reg: for read - location (and) for write - reg

	//printf("Lib code start\n");
	//fflush(stdout);
	
	for(int i=1; i<20; ++i){
		fprintf(fp,"PUSH R%d\n",i);
	}

	switch(func){
	
		//write
		case 'w': 	
				fprintf(fp,"MOV R0,\"Write\"\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0,-2\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0, R%d\n",loc_reg);
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				break;
				
		//read
		case 'r': 	fprintf(fp,"MOV R0,\"Read\"\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0,-1\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0, %d\n",loc_reg);
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				break;
				
		//exit
		case 'e': 	fprintf(fp,"MOV R0,\"Exit\"\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				break;
	
	}
	
	fprintf(fp,"CALL 0\n");
	fprintf(fp,"POP R0\n");
	fprintf(fp,"POP R1\n");
	fprintf(fp,"POP R1\n");
	fprintf(fp,"POP R1\n");
	fprintf(fp,"POP R1\n");
	
	for(int i=19; i>0; --i){
		fprintf(fp,"POP R%d\n",i);
	}
	

	//printf("Lib code end\n");
	//fflush(stdout);

}

//Main Code Generation Function
void codeGen(struct tnode *t, FILE *fp){

	reg_index reg_r;

	if(t == NULL)
		return ; 
		
	switch(t -> type){
		
		//connectors
		case 0: codeGen(t -> left,fp);
			codeGen(t->right,fp);
			break;
			
		//read lib call
		case 1: lib_code_gen('r',getVarLoc(t->left->varname),fp);
			break;
			
		//write lib call
		case 2: reg_r = oper_code_gen(t->left,fp);
			lib_code_gen('w',reg_r,fp);
			freeReg();
			break;
		
		//assignment (=)
		case 3: reg_r = oper_code_gen(t->right,fp);
			fprintf(fp,"MOV [%d], R%d\n",getVarLoc(t -> left -> varname), reg_r);
			freeReg();
			break;
			
		default: oper_code_gen(t,fp);
	
	}
	
	
	
}



