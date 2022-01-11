

reg_index getReg(){
	return ++reg_num;
}

int getLabel(){
	return ++label_num;
}

void freeReg(){
	--reg_num;
}

int getVarLoc(char* varname){
	return 4096 + *varname - 'a';
}

reg_index oper_code_gen(struct tnode *t, FILE *fp){

	reg_index reg;
	reg_index reg_l;
	reg_index reg_r;
	
	
	
	if(t->nodetype == leaf_node){ //leaf node
		reg = getReg();
		if(t -> varname != NULL)
			fprintf(fp,"MOV R%d, [%d]\n",reg, getVarLoc(t -> varname));
		else
			fprintf(fp,"MOV R%d, %d\n",reg,t->val);
		
	}
	else{ //internal node
	
		reg_l = oper_code_gen(t->left,fp);
		reg_r = oper_code_gen(t->right,fp);
		switch(t -> nodetype){
			
			//add
			case add: fprintf(fp,"ADD ");
				break;
			
			//subtract
			case sub: fprintf(fp,"SUB ");
				break;
				
			//multiply
			case mul: fprintf(fp,"MUL ");
				break;
				
			//divide
			case div: fprintf(fp,"DIV ");
				break;
			
			//greater than
			case gt: fprintf(fp,"GT ");
				break;
			
			//greater than or equal	
			case gte: fprintf(fp,"GE ");
				break;
			
			//less than
			case lt: fprintf(fp,"LT ");
				break;
			
			//less than or equal
			case lte: fprintf(fp,"LE ");
				break;
			
			//equal
			case eq: fprintf(fp,"EQ ");
				break;
			
			//not equal
			case neq: fprintf(fp,"NE ");
				break;
		}
		
		freeReg(); //dropping the higher numbered register among right and left
		fprintf(fp,"R%d, R%d\n",reg_num,reg_num+1);
		
		reg = reg_l;
	
	}
	return reg;
	
}

void lib_code_gen(int func, int loc_reg, FILE *fp){

	//loc_reg: for read - location (and) for write - reg


	
	for(int i=1; i<20; ++i){
		fprintf(fp,"PUSH R%d\n",i);
	}

	switch(func){
	
		//write
		case write: 	
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
		case read: 	fprintf(fp,"MOV R0,\"Read\"\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0,-1\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0, %d\n",loc_reg);
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				break;
				
		//exit
		case end: 	fprintf(fp,"MOV R0,\"Exit\"\n");
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

}

//Main Code Generation Function
void codeGen(struct tnode *t, FILE *fp){

	reg_index reg_r;
	int label1 = -1,label2 = -1,label3 = -1, label4 = -1;
	

	if(t == NULL)
		return ; 
		
	switch(t -> nodetype){
		
		//connectors
		case connector: codeGen(t -> left,fp);
			codeGen(t->right,fp);
			break;
			
		//read lib call
		case read: lib_code_gen(read,getVarLoc(t->left->varname),fp);
			break;
			
		//write lib call
		case write: reg_r = oper_code_gen(t->left,fp);
			lib_code_gen(write,reg_r,fp);
			freeReg();
			break;
		
		//assignment (=)
		case assign: reg_r = oper_code_gen(t->right,fp);
			fprintf(fp,"MOV [%d], R%d\n",getVarLoc(t -> left -> varname), reg_r);
			freeReg();
			break;
		
		//if
		case if_node: 
			reg_r = oper_code_gen(t -> left,fp);
			label1 = getLabel();
			fprintf(fp,"JZ R%d, L%d\n",reg_r,label1);
			codeGen(t -> right -> left,fp);
			
			if(t -> right -> right != NULL){ // else condition exists
				label2 = getLabel();
				fprintf(fp,"JMP L%d\n",label2);
				fprintf(fp,"L%d:\n",label1);
				codeGen(t -> right -> right,fp);
			}
			
			label2 = label2 > label1 ? label2 : label1;
			fprintf(fp,"L%d:\n",label2);
			break;
		
		//while
		case while_node:
			label3 = getLabel(); //start
			fprintf(fp,"L%d:\n",label3);
			reg_r = oper_code_gen(t -> left,fp);
			label4 = getLabel(); //end
			fprintf(fp,"JZ R%d, L%d\n",reg_r,label4);
			codeGen(t -> right,fp);
			fprintf(fp,"JMP L%d\n",label3);
			fprintf(fp,"L%d:\n",label4);
			break;
			
		default: oper_code_gen(t,fp);
	
	}
	
	
	
}



