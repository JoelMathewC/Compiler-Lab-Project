void getVarMemLoc(struct tnode* t, FILE *fp, reg_index reg){ //returns a register in which memLoc is stored
	int reg1;

	if(t -> Lentry != NULL){
		fprintf(fp,"MOV R%d, BP\n",reg);
		fprintf(fp,"ADD R%d, %d\n",reg, t -> Lentry -> binding);
	}
	else{
		switch( t -> Gentry -> dim){
		
			case 0: 
				fprintf(fp,"MOV R%d, %d\n",reg, t -> Gentry -> binding);
				break;
			case 1: oper_code_gen(t -> index1,fp,reg);
				if(t -> Gentry -> binding == -1){ // null pointers
					printf("NULL Variable (%s) accessed\n",t -> varname);
					exit(0);
				}
				fprintf(fp,"ADD R%d, %d\n",reg,t -> Gentry -> binding);
				break;
			case 2: oper_code_gen(t -> index1,fp,reg);
				fprintf(fp,"MUL R%d, %d\n",reg,t -> Gentry -> shape[1]);

				reg1 = getReg(); //allocated register
				oper_code_gen(t -> index2,fp,reg1);
				fprintf(fp,"ADD R%d, R%d\n",reg,reg1);
				freeReg(); //deallocated register
				
				fprintf(fp,"ADD R%d, %d\n",reg,t -> Gentry -> binding);
				break;
		}
	}
}


void oper_code_gen(struct tnode *t, FILE *fp, reg_index reg){

	reg_index reg1;
	
	
	if(t->nodetype == leaf_node){ //leaf node
		if(t -> varname != NULL){
			getVarMemLoc(t,fp,reg);
			fprintf(fp,"MOV R%d, [R%d]\n",reg, reg);
			
		}else{
			t -> dtype == intType ? fprintf(fp,"MOV R%d, %d\n",reg,t-> val.num) : fprintf(fp,"MOV R%d, %s\n",reg,t->val.str);
		}
		
		return;
		
	}
	else{ //internal node
		oper_code_gen(t->left,fp,reg);
		
		reg1 = getReg(); //allocated register
		oper_code_gen(t->right,fp,reg1);
		
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
				
			//modulus
			case mod: fprintf(fp,"MOD ");
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
		
	
		fprintf(fp,"R%d, R%d\n",reg,reg1);
		freeReg(); //deallocated reg
	
	}

	
}

void lib_code_gen(int func, int reg, FILE *fp){

	//reg: for read - register storing location (and) for write - register storing value
	
	for(int i=1; i<=reg_num; ++i){
		fprintf(fp,"PUSH R%d\n",i);
	}

	switch(func){
	
		//write
		case write: 	
				fprintf(fp,"MOV R0,\"Write\"\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0,-2\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0, R%d\n",reg);
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"PUSH R0\n");
				break;
				
		//read
		case read: 	fprintf(fp,"MOV R0,\"Read\"\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0,-1\n");
				fprintf(fp,"PUSH R0\n");
				fprintf(fp,"MOV R0, R%d\n",reg);
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
	
	for(int i=reg_num; i>0; --i){
		fprintf(fp,"POP R%d\n",i);
	}

}

//Main Code Generation Function
void codeGen(struct tnode *t, FILE *fp, struct LoopStack *lp){

	reg_index reg1, reg2;
	int label1 = -1,label2 = -1,label3 = -1, label4 = -1;
	

	if(t == NULL)
		return ; 
		
	switch(t -> nodetype){
		
		//connectors
		case connector: 
			codeGen(t -> left,fp,lp);
			codeGen(t->right,fp,lp);
			break;
			
		//read lib call
		case read: 	reg1 = getReg();
				getVarMemLoc(t->left,fp,reg1);
				lib_code_gen(read,reg1,fp);
				freeReg();
			break;
			
		//write lib call
		case write: 	reg1 = getReg();
				oper_code_gen(t->left,fp,reg1);
				lib_code_gen(write,reg1,fp);
				freeReg();
			break;
		
		//assignment (=)
		case assign: 	
				reg1 = getReg();
				oper_code_gen(t->right,fp,reg1);
				
				reg2 = getReg();
				getVarMemLoc(t -> left,fp,reg2);
				
				fprintf(fp,"MOV [R%d], R%d\n",reg2, reg1);
				freeReg();
				freeReg();
			break;
		
		//if
		case if_node: 
			reg1 = getReg();
			oper_code_gen(t -> left,fp,reg1);
			label1 = getLabel();
			fprintf(fp,"JZ R%d, L%d\n",reg1,label1);
			codeGen(t -> right -> left,fp,lp);
			
			if(t -> right -> right != NULL){ // else condition exists
				label2 = getLabel();
				fprintf(fp,"JMP L%d\n",label2);
				fprintf(fp,"L%d:\n",label1);
				codeGen(t -> right -> right,fp,lp);
			}
			
			label2 = label2 > label1 ? label2 : label1;
			fprintf(fp,"L%d:\n",label2);
			freeReg();
			
			break;
		
		//while
		case while_node:
			label3 = getLabel(); //start
			label4 = getLabel(); //end
			
			loopStackPush(lp,label3,label4);
			
			fprintf(fp,"L%d:\n",label3);
			
			reg1 = getReg();
			oper_code_gen(t -> left,fp,reg1);
			fprintf(fp,"JZ R%d, L%d\n",reg1,label4);
			codeGen(t -> right,fp,lp);
			fprintf(fp,"JMP L%d\n",label3);
			fprintf(fp,"L%d:\n",label4);
			
			freeReg();
			loopStackPop(lp);
			break;
		
		//do-while
		case do_while:
			label3 = getLabel(); //start
			label4 = getLabel(); //end
			
			loopStackPush(lp,label3,label4);
			
			fprintf(fp,"L%d:\n",label3);
			codeGen(t -> right,fp,lp);
			
			reg1 = getReg();
			oper_code_gen(t -> left,fp,reg1);
			fprintf(fp,"JZ R%d, L%d\n",reg1,label4);
			fprintf(fp,"JMP L%d\n",label3);
			fprintf(fp,"L%d:\n",label4);
			freeReg();
			
			loopStackPop(lp);
			break;
		
		//continue
		case continue_node:
			if(lp -> top != NULL){
				fprintf(fp,"JMP L%d\n",lp -> top -> open_label);
			}
			break;
		
		//break
		case break_node:
			if(lp -> top != NULL){
				fprintf(fp,"JMP L%d\n",lp -> top -> close_label);
			}
			break;
		
		case return_node:
			reg1 = getReg();
			oper_code_gen(t -> left,fp,reg1);
			
			reg2 = getReg();
			fprintf(fp,"MOV R%d, BP\n",reg2);
			fprintf(fp,"SUB R%d, 2\n",reg2);
			fprintf(fp,"MOV [%d], R%d\n",reg2,reg1);
			freeReg();
			freeReg();
			break;
		
		case func_node:
			functionCallerCode(fp,t -> Gentry -> binding,t -> args);
			break;
			
		default: 	
				reg1 = getReg();
				oper_code_gen(t,fp,reg1);
				freeReg();
	
	}
	
	
	
}


void funcCodeGen(struct tnode *t, FILE *fp, int label){
	reg_num = 0;
	struct LoopStack* lp = (struct LoopStack*)malloc(sizeof(struct LoopStack));
	lp -> top = NULL;
	
	if(label == -1)
		fprintf(fp,"MAIN:\n");
	else
		fprintf(fp,"F%d:\n",label);
	functionCalledStartCode(fp);
	codeGen(t,fp,lp);
	functionCalledEndCode(fp,label);
	
}

void functionCallerCode(FILE *fp, int label, struct ArgStruct *args){
	int reg1;
	//push registers
	for(int i=1; i<=reg_num; ++i)
		fprintf(fp,"PUSH R%d\n",i);
		
	//push args
	int len = 0;
	struct ArgStruct* temp = args;
	while(temp != NULL){
		reg1 = getReg();
		oper_code_gen(temp -> arg,fp,reg1);
		fprintf(fp,"PUSH R%d\n",reg1);
		freeReg();
		temp = temp -> next;
		++len;
	}
	
	//return val space
	fprintf(fp,"PUSH R0\n");

	
	//call
	fprintf(fp,"CALL F%d\n", label);
	
	//store ret val
	fprintf(fp,"POP R0\n");
	
	//pop args
	for(int i=0; i< len; ++i)
		fprintf(fp,"POP R1\n");
	
	//pop registers
	for(int i=reg_num; i>0; --i)
		fprintf(fp,"POP R%d\n",i);
}

void functionCalledStartCode(FILE *fp){
	fprintf(fp,"PUSH BP\n");
	fprintf(fp,"MOV BP, SP\n");
	fprintf(fp,"ADD SP, %d\n",localMemLoc);
}

void functionCalledEndCode(FILE *fp,int label){
	for(int i=1; i<=localMemLoc; ++i)
		fprintf(fp,"POP R0\n");
	fprintf(fp,"POP BP\n");
	fprintf(fp,"RET\n");
}


