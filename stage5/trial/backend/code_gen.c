void dimResCodeGen(FILE* fp, reg_index reg, int dim_cur, int dim_abs, struct ArrayDims* indices, struct ArrayShape* shape){// (dim_cur is current dim) and (dim_abs is dim in symbol table)
	struct ArrayDims* temp_i = indices;
	struct ArrayShape* temp_s = shape;
	int reg1;
	
	for(int i=0; i < (dim_abs - dim_cur); ++i){
		if(temp_i != NULL){
			reg1 = getReg();
			oper_code_gen(temp_i -> node,fp,reg1);
			fprintf(fp,"MUL R%d, %d\n",reg1,temp_s -> index);
			fprintf(fp,"ADD R%d, R%d\n",reg, reg1);
			freeReg();
			
			temp_i = temp_i -> next;
			temp_s = temp_s -> next;
		}
		fprintf(fp,"MOV R%d, [R%d]\n",reg,reg);
	}
}


void getVarMemLoc(struct tnode* t, FILE *fp, reg_index reg){ //returns a register in which memLoc is stored
	int reg1;

	if(t -> Lentry != NULL){
		
		switch(t -> nodetype){ //pointers and normal variables
		
			case leaf_node: fprintf(fp,"MOV R%d, BP\n",reg);
					fprintf(fp,"ADD R%d, %d\n",reg, t -> Lentry -> binding); //got the memory location of variable
					dimResCodeGen(fp,reg,t -> dim,t -> Lentry -> dim, NULL, NULL);
					break;
			
			case ptr_node: //when its of the form *(a + k) and others
					oper_code_gen(t -> left,fp,reg);
					break;
			
			default: printf("Trying to access memory from a non-leaf/non-ptr notde");
				exit(0);
		}
		
		
			
	}
	else{
		switch(t -> nodetype){ //pointers and normal variables
		
			case leaf_node: fprintf(fp,"MOV R%d, BP\n",reg);
					fprintf(fp,"ADD R%d, %d\n",reg, t -> Gentry -> binding); //got the memory location of variable
					dimResCodeGen(fp,reg,t -> dim,t -> Gentry -> dim, t -> indices, t -> Gentry -> shape);
					break;
			
			case ptr_node: //when its of the form *(a + k) and others
					oper_code_gen(t -> left,fp,reg);
					break;
			
			default: printf("Trying to access memory from a non-leaf/non-ptr notde");
				exit(0);
		}
	}
}


void oper_code_gen(struct tnode *t, FILE *fp, reg_index reg){

	reg_index reg1;
	
	switch(t -> nodetype){
		
		case leaf_node: 	if(t -> varname != NULL){
						getVarMemLoc(t,fp,reg);
						fprintf(fp,"MOV R%d, [R%d]\n",reg, reg);
						
					}else{
						t -> dtype == intType ? fprintf(fp,"MOV R%d, %d\n",reg,t-> val.num) : fprintf(fp,"MOV R%d, %s\n",reg,t->val.str);
					}
					break;
					
		case func_node: 	codeGen(t, fp, NULL);
					fprintf(fp,"MOV R%d, R0\n",reg);
					break;
		case ptr_node: 	getVarMemLoc(t -> left,fp,reg);
					fprintf(fp,"MOV R%d, [R%d]\n",reg, reg);
					break;
		default:		
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
		case assign: 	reg1 = getReg();
				oper_code_gen(t->right,fp,reg1);
				
				reg2 = getReg();
				getVarMemLoc(t -> left,fp,reg2);
				
				fprintf(fp,"MOV [R%d], R%d\n",reg2, reg1);
				freeReg();
				freeReg();
			break;
		
		//if
		case if_node: 
			if(t -> left -> nodetype == and || t -> left -> nodetype == or){
				label1 = getLabel();
				codeGen(t -> left,fp,lp);
			}
			else{
				reg1 = getReg();
				oper_code_gen(t -> left,fp,reg1);
				label1 = getLabel();
				fprintf(fp,"JZ R%d, L%d\n",reg1,label1);
				freeReg();
			}
			codeGen(t -> right -> left,fp,lp);
			
			if(t -> right -> right != NULL){ // else condition exists
				label2 = getLabel(); 
				fprintf(fp,"JMP L%d\n",label2);
				fprintf(fp,"L%d:\n",label1);
				codeGen(t -> right -> right,fp,lp);
			}
			
			label2 = label2 > label1 ? label2 : label1;
			fprintf(fp,"L%d:\n",label2);
			
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
			fprintf(fp,"MOV [R%d], R%d\n",reg2,reg1);
			freeReg();
			freeReg();
			break;
		
		case func_node:
			functionCallerCode(fp,t -> Gentry -> binding,t -> args);
			break;
		
		case and:	
				if(t -> left -> nodetype == and || t -> left -> nodetype == or){
					codeGen(t -> left,fp,lp);
				}else{
					reg1 = getReg();
					oper_code_gen(t -> left,fp,reg1);
					fprintf(fp,"JZ R%d, L%d\n",reg1,label_num);
					freeReg();
				}
				
				if(t -> right -> nodetype == and || t -> right -> nodetype == or){
					codeGen(t -> right,fp,lp);
				}else{
					reg1 = getReg();
					oper_code_gen(t -> right,fp,reg1);
					fprintf(fp,"JZ R%d, L%d\n",reg1,label_num);
					freeReg();
				}
			break;
		
		case or:
				label1 = getLabel();
				if(t -> left -> nodetype == and || t -> left -> nodetype == or){
					codeGen(t -> left,fp,lp);
				}else{
					reg1 = getReg();
					oper_code_gen(t -> left,fp,reg1);
					fprintf(fp,"JNZ R%d, L%d\n",reg1,label1);
					freeReg();
				}
				
				if(t -> right -> nodetype == and || t -> right -> nodetype == or){
					codeGen(t -> right,fp,lp);
				}else{
					reg1 = getReg();
					oper_code_gen(t -> right,fp,reg1);
					label2 = getLabel();
					fprintf(fp,"JZ R%d, L%d\n",reg1,label_num-1);
					freeReg();
				}
				fprintf(fp,"L%d:\n",label1);
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
	struct ArgStack *st = (struct ArgStack*)malloc(sizeof(struct ArgStack));
	st -> head = NULL;
	
	while(temp != NULL){
		pushArgStack(st,temp -> arg);
		temp = temp -> next;
	}	
	
	while(st -> head != NULL){
		reg1 = getReg();
		struct tnode* node = popArgStack(st);
		oper_code_gen(node,fp,reg1);
		fprintf(fp,"PUSH R%d\n",reg1);
		freeReg();
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


