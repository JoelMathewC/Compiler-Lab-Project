void dimResCodeGen(FILE* fp, reg_index reg, int dim_cur, int dim_abs, struct ArrayDims* indices){// (dim_cur is current dim) and (dim_abs is dim in symbol table)
	struct ArrayDims* temp_i = indices;
	int reg1;

	
	
	for(int i=0; i < (dim_abs - dim_cur); ++i){ 
		if(temp_i != NULL){// resolve the array part first
			reg1 = getReg();
			
			fprintf(fp,"MOV R%d, [R%d]\n",reg,reg);
			oper_code_gen(temp_i -> node,fp,reg1);
			fprintf(fp,"ADD R%d, R%d\n",reg,reg1);
			
			freeReg();
			
			temp_i = temp_i -> next;
		}
		else{
			fprintf(fp,"MOV R%d, [R%d]\n",reg,reg);
		}
	}
		
	
}


int getVarMemLoc(struct tnode* t, FILE *fp, reg_index reg, boolean findParentOfMethod){ 
/*
if it recieves a tnode with
	
	1. local entry :
				1.1. leaf_node: store the memory location of leaf node in reg, 
					1.1.1. for pointers: then performs dereferencing (dim_abs-(dim_curr + number of indices)) times and stores the final memory location in reg
					1.1.2. for arrays: stores the actual memory location of the element being referenced in reg
					1.1.3. for normal variables: nothing else
				
				1.2. ptr_node (*expr): gets you the computed value of expr and stores it in reg1
				
	2. Global entry : 
			same

*/
	int reg1;
	struct tnode* temp;
	struct MethodList* method;

	if(t -> Lentry != NULL){
		
		switch(t -> nodetype){ //pointers and normal variables
		
			case leaf_node: fprintf(fp,"MOV R%d, BP\n",reg);
					fprintf(fp,"ADD R%d, %d\n",reg, t -> Lentry -> binding); //got the memory location of variable
					dimResCodeGen(fp,reg,t -> dim,t -> Lentry -> dim, NULL);
			
					
					// when its a user defined type
					temp = t -> left;
					while(temp != NULL){ //an attribute is being referenced
						if(temp -> nodetype == leaf_node){
							fprintf(fp,"MOV R%d, [R%d]\n",reg,reg);
							fprintf(fp,"ADD R%d, %d\n", reg, temp -> fieldRef == NULL ? temp -> attrRef -> fieldIndex : temp -> fieldRef -> fieldIndex);
							temp = temp -> left;
						}
						else if(temp -> nodetype == func_node){
							if(findParentOfMethod == True) //in the case they are trying to find the parent of a func
								return func_node;
							
							
							fprintf(fp,"ADD R%d, 1\n",reg);
							fprintf(fp,"MOV R%d, [R%d]\n",reg,reg);
							fprintf(fp,"ADD R%d, %d\n",reg,temp -> methodRef -> methodIndex);
							return func_node;
						}
					}
					break;
			
			
			default: printf("Trying to access memory from a non-leaf/non-ptr notde");
				exit(0);
		}
		
		
			
	}
	else if(t -> Gentry != NULL){
		switch(t -> nodetype){ //pointers and normal variables
		
			case leaf_node: fprintf(fp,"MOV R%d, %d\n",reg, t -> Gentry -> binding); //got the memory location of variable
					dimResCodeGen(fp,reg,t -> dim,t -> Gentry -> dim, t -> indices);
					
					// When its a user defined type
					temp = t -> left;
					while(temp != NULL){ //an attribute is being referenced
						if(temp -> nodetype == leaf_node){
							fprintf(fp,"MOV R%d, [R%d]\n",reg,reg);
							fprintf(fp,"ADD R%d, %d\n", reg, temp -> fieldRef == NULL ? temp -> attrRef -> fieldIndex : temp -> fieldRef -> fieldIndex);
							temp = temp -> left;
						}
						else if(temp -> nodetype == func_node){
							if(findParentOfMethod == True) //in the case they are trying to find the parent of a func
								return func_node;
							
							fprintf(fp,"ADD R%d, 1\n",reg);
							fprintf(fp,"MOV R%d, [R%d]\n",reg,reg);
							fprintf(fp,"ADD R%d, %d\n",reg,temp -> methodRef -> methodIndex);
							return func_node;
						}
					}
					break;
			
			default: printf("Trying to access memory from a non-leaf/non-ptr notde");
				exit(0);
		}
	}
	else if(t -> nodetype == ptr_node){
		oper_code_gen(t -> left,fp,reg);
	}
	
	return leaf_node;
}


void oper_code_gen(struct tnode *t, FILE *fp, reg_index reg){ 

/*

if it recieves a
1. tnode with root as an operator: evaluates code for the entire operation and stores final result in reg1
2. tnode with root as func_node: generates code to call func
3. tnode with root as leaf node: stores the value of the leaf node in reg1
4. tnode with root as ptr_node (*expr): calculates expr, then dereferences to expr and stores the value in reg1

*/

	reg_index reg1;
	int nodetype;
	struct tnode* temp;
	
	switch(t -> nodetype){
		
		case leaf_node: 	if(t -> varname != NULL){
						nodetype = getVarMemLoc(t,fp,reg,False);
						if(nodetype == leaf_node){
							fprintf(fp,"MOV R%d, [R%d]\n",reg, reg);
						}else{
							temp = t;
							while(t -> nodetype != func_node)
								t = t -> left;
							
							functionCallerCode(fp,-1,t -> args,True,reg);
							fprintf(fp,"MOV R%d, R0\n",reg);
						}
						
					}else{
						if(t -> dim > 0){
							fprintf(fp,"MOV R%d, %d\n",reg,t-> val.num);
							if(t -> Lentry != NULL)
								fprintf(fp,"ADD R%d, BP\n",reg);
						}else{
							
							if(strcmp(t -> dtype -> type_name,"string") == 0)
								fprintf(fp,"MOV R%d, %s\n",reg,t->val.str);
							else if(strcmp(t -> dtype -> type_name,"null") == 0)
								fprintf(fp,"MOV R%d, %d\n",reg,0);
							else
								fprintf(fp,"MOV R%d, %d\n",reg,t-> val.num);
						}
					}
					break;
					
					
		case type_alloc_node:	lib_code_gen(type_alloc_node,-1,fp);
					fprintf(fp,"MOV R%d, R0\n",reg);
					break;
		
		case class_alloc_node:	lib_code_gen(class_alloc_node,-1,fp);
					fprintf(fp,"MOV R%d, R0\n",reg);
					break;
		
		case free_node:	reg1 = getReg();
					oper_code_gen(t->left,fp,reg1);
					lib_code_gen(free_node,reg1,fp);
					freeReg();
					fprintf(fp,"MOV R%d, R0\n",reg);
					break;
				
		case mem_init_node:	lib_code_gen(mem_init_node,-1,fp);
					fprintf(fp,"MOV R%d, R0\n",reg);
					break;
					
		case func_node: 	codeGen(t, fp, NULL);
					fprintf(fp,"MOV R%d, R0\n",reg);
					break;
					
		case ptr_node: 	oper_code_gen(t -> left,fp,reg);
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
	//	for free - register storing address of location to be freed
	int temp_reg_num = reg_num;
	for(int i=1; i<=temp_reg_num; ++i){
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
			
		//Initialize	
		case mem_init_node:	fprintf(fp,"MOV R0,\"Initialize\"\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"PUSH R0\n");
					break;
		
		//Alloc
		case class_alloc_node:	
		case type_alloc_node:	fprintf(fp,"MOV R0,\"Alloc\"\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"PUSH R0\n");
					break;
		
		//Free	
		case free_node:	fprintf(fp,"MOV R0,\"Free\"\n");
					fprintf(fp,"PUSH R0\n");
					fprintf(fp,"MOV R0, R%d\n",reg);
					fprintf(fp,"PUSH R0\n");
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
	
	for(int i=temp_reg_num; i>0; --i){
		fprintf(fp,"POP R%d\n",i);
	}
	reg_num = temp_reg_num;

}

//Main Code Generation Function
void codeGen(struct tnode *t, FILE *fp, struct LoopStack *lp){

	reg_index reg1, reg2, reg3;
	int label1 = -1,label2 = -1,label3 = -1, label4 = -1;
	int nodetype;
	

	if(t == NULL)
		return ; 
		
	switch(t -> nodetype){
		
		//connectors
		case connector: 
			codeGen(t -> left,fp,lp);
			codeGen(t->right,fp,lp);
			break;
			
		//read lib call
		case read: 	
				reg1 = getReg();
				getVarMemLoc(t->left,fp,reg1,False); //cannot be func_node
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
				getVarMemLoc(t -> left,fp,reg2,False); //cannot be func_node
				
				if(t -> right -> nodetype == class_alloc_node){
					reg3 = getReg();
					fprintf(fp,"MOV R%d, R%d\n",reg3,reg2);
					fprintf(fp,"ADD R%d, 1\n",reg3); //to get virtual func table ptr
					fprintf(fp,"MOV [R%d], %d\n",reg3, 4096 + (t -> right -> ctype -> classIndex * 8));
					freeReg();
				}
				
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
			functionCallerCode(fp,t -> Gentry -> flabel,t -> args,False,-1);
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

void functionCallerCode(FILE *fp, int label, struct ArgStruct *args, boolean isMethod, int method_addr_reg){
	int reg1,reg2;
	int temp_reg_num = reg_num;
	struct tnode* node;
	
	
	//push registers
	for(int i=1; i<=temp_reg_num; ++i)
		fprintf(fp,"PUSH R%d\n",i);
	
	fprintf(fp,"MOV R1, R%d\n",method_addr_reg);
	reg_num = 1;
		
	//push args to temp stack
	int len = 0;
	struct ArgStruct* temp = args;
	struct ArgStack *st = (struct ArgStack*)malloc(sizeof(struct ArgStack));
	st -> head = NULL;
	
	while(temp != NULL){
		pushArgStack(st,temp -> arg);
		temp = temp -> next;
	}
	
	//adding self in case of methods
	if(isMethod == True){ 
		
		node = popArgStack(st);
		reg1 = getReg();
		
		//pushing class object
		getVarMemLoc(node,fp,reg1,True);
		reg2 = getReg();
		fprintf(fp,"MOV R%d, R%d\n",reg2,reg1);
		fprintf(fp,"MOV R%d, [R%d]\n",reg2,reg2);
		fprintf(fp,"PUSH R%d\n",reg2);
		freeReg();
		
		//pushing virtual func table ptr
		fprintf(fp,"ADD R%d, 1\n",reg1);
		fprintf(fp,"MOV R%d, [R%d]\n",reg1,reg1);
		fprintf(fp,"PUSH R%d\n",reg1);
		
		freeReg();
		len += 2;
	}	
	
	//pushing the arguments
	while(st -> head != NULL){
		reg1 = getReg();
		node = popArgStack(st);
		oper_code_gen(node,fp,reg1);
		fprintf(fp,"PUSH R%d\n",reg1);
		freeReg();
		++len;
	}
	
	//return val space
	fprintf(fp,"PUSH R0\n");

	
	//call
	if(isMethod == True){
		//method_addr_reg has been moved to R1
		fprintf(fp,"MOV R1, [R1]\n");
		fprintf(fp,"CALL R1\n");	
	}else
		fprintf(fp,"CALL F%d\n", label);
	
	//store ret val
	fprintf(fp,"POP R0\n");
	
	//pop args
	for(int i=0; i< len; ++i)
		fprintf(fp,"POP R1\n");
	
	//pop registers
	for(int i=temp_reg_num; i>0; --i)
		fprintf(fp,"POP R%d\n",i);
	reg_num = temp_reg_num;
}

void functionCalledStartCode(FILE *fp){
	int label1 = getLabel();
	
	fprintf(fp,"PUSH BP\n");
	fprintf(fp,"MOV BP, SP\n");
	
	if(localMemLoc > 0){
		fprintf(fp,"MOV R2, SP\n");
		fprintf(fp,"ADD SP, %d\n",localMemLoc); //statically allocates global variable space
		fprintf(fp,"L%d:\n",label1);
		fprintf(fp,"ADD R2, 1\n");
		fprintf(fp,"MOV R1, R2\n");
		fprintf(fp,"MOV [R1], 0\n");
		fprintf(fp,"EQ R1, SP\n");
		fprintf(fp,"JZ R1, L%d\n",label1);
	}
}

void functionCalledEndCode(FILE *fp,int label){
	for(int i=1; i<=localMemLoc; ++i)
		fprintf(fp,"POP R0\n");
	fprintf(fp,"POP BP\n");
	fprintf(fp,"RET\n");
}


