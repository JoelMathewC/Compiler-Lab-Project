struct ClassTable* ClassTableCreate(){
	struct ClassTable* table = (struct ClassTable*)malloc(sizeof(struct ClassTable));
	table -> head = NULL;
	return table;
}

struct ClassTableEntry* CInstall(char* name, struct ClassTableEntry* parent){
	int attrCount = 0, methodCount = 0;
	struct ClassTableEntry* entry = (struct ClassTableEntry*)malloc(sizeof(struct ClassTableEntry));
	entry -> class_name = name;
	entry -> parent = parent;
	entry -> classIndex = getClassIndex();
	entry -> attrList = NULL;
	entry -> methodList = NULL;
	entry -> attrCount = 0;
	entry -> methodCount = 0;
	
	struct AttrList* temp_a;
	struct MethodList* temp_m;
	
	struct AttrList* attrList = NULL;
	struct MethodList* methodList = NULL;
	if(parent != NULL){
		
		temp_a = parent -> attrList;
		temp_m = parent -> methodList;
		
		while(temp_a != NULL){
			
			addToClassAttrList(entry, AInstall(temp_a -> varname, temp_a -> dim, temp_a -> dtype, temp_a -> ctype));
			temp_a = temp_a -> next;
		}
		
		while(temp_m != NULL){
		
			addToClassMethodList(entry, MInstall(temp_m -> method_name, temp_m -> flabel, True, temp_m -> dtype, temp_m -> params));
			temp_m = temp_m -> next;
			
		}
		
	
	}
	return entry;
}

struct ClassTableEntry* CLookup(struct ClassTable* table, char* name){

	if(table == NULL || name == NULL)
		return NULL;
	struct ClassTableEntry* temp = table -> head;
	
	while(temp != NULL){
		if(strcmp(temp -> class_name, name) == 0)
			return temp;
		temp = temp -> next;
	}
	
	return NULL;
}


void addToClassTable(struct ClassTable* classTable, char* class_name, char* parent_name){ //only for user def type
	
	struct ClassTableEntry* parent = CLookup(classTable,parent_name);
	struct ClassTableEntry* entry = CInstall(class_name,parent);
	
	struct ClassTableEntry* temp = classTable -> head;
	
	if(temp == NULL){
		classTable -> head = entry;
	}else{
		while(temp -> next != NULL)
			temp = temp -> next;
		
		temp -> next = entry;
	}
}

void addDeclToClassEntry(struct ClassTable* classTable, struct TypeTable* typeTable, struct dnode* root, char* class_name ){
	struct ClassTableEntry* entry = CLookup(classTable,class_name);
	generateClassAttrList(entry, root,NULL, entry, typeTable, classTable);
}

void generateClassAttrList(struct ClassTableEntry* class_entry, struct dnode* root, struct TypeTableEntry* field_dtype, struct ClassTableEntry* field_ctype, struct TypeTable* typeTable, struct ClassTable* classTable){
	

	if(root == NULL)
		return;
	
	switch(root -> nodetype){
	
		case connector : generateClassAttrList(class_entry,root -> left,field_dtype,field_ctype, typeTable, classTable);
				generateClassAttrList(class_entry,root -> right,field_dtype,field_ctype, typeTable, classTable);
				break;
		
		case type_node: generateClassAttrList(class_entry,root -> left,TLookup(typeTable,root -> type_name), CLookup(classTable,root -> type_name),typeTable, classTable);
				break;
		
		case func_node: addToClassMethodList(class_entry,MInstall(root -> varname, -1, False, field_dtype, root -> params));
				break;
		
		case leaf_node: addToClassAttrList(class_entry,AInstall(root -> varname, root -> dim, field_dtype, field_ctype));
				break;
				
		
		default: printf("Error: Invalid Declaration within type block");
			exit(0);
	}
}


void printClassTable(struct ClassTable* table){

	if(table == NULL){
		printf("No types\n");
		fflush(stdout);
	}
	else{
		struct ClassTableEntry* entry = table -> head;
		struct AttrList* attr;
		printf("NAME : FIELDS : FIELD INDEX\n");
		while(entry != NULL){
			printf("%s : ",entry -> class_name);
			attr = entry -> attrList;
			while(attr != NULL){
				printf("%s(%d) ",attr -> varname,attr -> fieldIndex);
				attr = attr -> next;
			}
			printf("\n");
			entry = entry -> next;
	}
	
	}
	
	
	
}

void verifyMethodHead(char* name, struct ParamStruct* params, struct TypeTableEntry* return_type, struct ClassTableEntry* classEntry){

	struct MethodList* method = MLookupWithParams(classEntry -> methodList, params, name);
	if(method == NULL){
		printf("Function not declared: %s",name);
		exit(0);
	}
}


//--------------------------------------- ATTR FUNC ----------------------------------------------

struct AttrList* AInstall(char* varname, int dim, struct TypeTableEntry* dtype, struct ClassTableEntry* ctype){
	struct AttrList* attr = (struct AttrList*)malloc(sizeof(struct AttrList));
	attr -> varname = varname;
	attr -> dim = dim;
	attr -> fieldIndex = 0;
	attr -> dtype = dtype;
	attr -> ctype = ctype;
	attr -> next = NULL;
	return attr;
}

void addToClassAttrList(struct ClassTableEntry* entry, struct AttrList* new_node){
	struct AttrList* temp = entry -> attrList;

	
	if(entry -> attrList == NULL)
		entry -> attrList = new_node;
	else{
		while(temp -> next != NULL){
			if(strcmp(temp -> varname, new_node -> varname) == 0){
				printf("Error: Two member fields with the same name (%s)",temp -> varname);
				exit(0);
			}
			temp = temp -> next;
		}
		
		if(strcmp(temp -> varname, new_node -> varname) == 0){
				printf("Error: Two member fields with the same name (%s)",temp -> varname);
				exit(0);
		}
		
		if(entry -> attrCount >= 8){
			printf("Member attribute count for %s is exceeding Limit(8)",entry -> class_name);
			exit(0);
		}
		else{
			new_node -> fieldIndex = entry -> attrCount;
			temp -> next = new_node;
		}
	}
	
	entry -> attrCount += 1;
}

struct AttrList* ALookup(struct AttrList* attr, char* name){
	struct AttrList* temp = attr;
	
	while(temp != NULL){
		if(strcmp(temp -> varname, name) == 0)
			return temp;
		temp = temp -> next;
	}
	
	return NULL;
}


//--------------------------------------------------- METHOD FUNC -----------------------------------


struct MethodList* MInstall(char* method_name, int flabel, boolean isInherited, struct TypeTableEntry* dtype, struct ParamStruct* params){
	struct MethodList* method = (struct MethodList*)malloc(sizeof(struct MethodList));
	method -> method_name = method_name;
	method -> methodIndex = 0;
	method -> isInherited = isInherited;
	method -> flabel = (flabel == -1) ? getFuncLabel() : flabel;
	method -> dtype = dtype;
	method -> params = params;
	method -> next = NULL;
	return method;
}

void addToClassMethodList(struct ClassTableEntry* entry, struct MethodList* new_node){
	struct MethodList* temp = entry -> methodList;
	boolean done = False;
	
	if(entry -> methodList == NULL){
		entry -> methodList = new_node;
		entry -> methodCount += 1;
	}else{
		while(temp -> next != NULL){
			if(isSameFuncDecl(temp, new_node -> params, new_node -> method_name) == True){
				if(temp -> isInherited == True){ // if function is being overwritten
					temp -> flabel = getFuncLabel();
					done = True;
				}
				else{
					printf("Error: Two methods fields with the same name (%s)",temp -> method_name);
					exit(0);
				}
			}
			temp = temp -> next;
		}
		
		if(isSameFuncDecl(temp, new_node -> params, new_node -> method_name) == True){
				if(temp -> isInherited == True){ // if function is being overwritten
					temp -> flabel = getFuncLabel();
					done = True;
				}
				else{
					printf("Error: Two methods fields with the same name (%s)",temp -> method_name);
					exit(0);
				}
		}
		
		if(entry -> methodCount >= 8){
			printf("Member attribute count for %s is exceeding Limit(8)",entry -> class_name);
			exit(0);
		}
		else if(done == False){
			new_node -> methodIndex = entry -> methodCount;
			temp -> next = new_node;
			entry -> methodCount += 1;
		}
	}
	
}

struct MethodList* MLookupWithArgs(struct MethodList* method, struct ArgStruct* args, char* name){
	struct MethodList* temp = method;
	while(temp != NULL){
		if(isSameFuncCall(temp,args,name) == True)
			return temp;
		temp = temp -> next;
	}
	return NULL;
}

struct MethodList* MLookupWithParams(struct MethodList* method, struct ParamStruct* params, char* name){
	struct MethodList* temp = method;
	
	while(temp != NULL){
		if(isSameFuncDecl(temp,params,name) == True)
			return temp;
		temp = temp -> next;
	}
	
	return NULL;
}

boolean isSameFuncCall(struct MethodList* method,struct ArgStruct* args, char* name){
	struct ArgStruct* temp = args;
	struct ParamStruct* params = method -> params;

	if(strcmp(method -> method_name,name) == 0){
		
		while(temp != NULL && params != NULL){

			if((temp -> arg -> dtype != NULL && params -> dtype != NULL)){
				if(strcmp(temp -> arg -> dtype -> type_name, params -> dtype -> type_name) != 0){
					return False;
				}
			}else if((temp -> arg -> ctype != NULL && params -> ctype != NULL)){
				if(strcmp(temp -> arg -> ctype -> class_name, params -> ctype -> class_name) != 0){
					return False;
				}
			}else{
				return False;
			}
			
			
			temp = temp -> next;
			params = params -> next;
		}
		
		if(temp == NULL && params == NULL){
			return True;
		}
		
	}
	
	return False;
	
}

boolean isSameFuncDecl(struct MethodList* method_old, struct ParamStruct* new_params, char* new_method_name){

	struct ParamStruct* p_old = method_old -> params;
	struct ParamStruct* p_new = new_params;
	if(strcmp(method_old -> method_name, new_method_name) == 0){
		while(p_old != NULL && p_new != NULL){
			
			if((p_old -> dtype != NULL && p_new -> dtype != NULL)){
				if(strcmp(p_old -> dtype -> type_name, p_new -> dtype -> type_name) != 0){
					return False;
				}
			}else if((p_old -> ctype != NULL && p_new -> ctype != NULL)){
				if(isClassAssignable(p_old -> ctype, p_new -> ctype) == False){
					return False;
				}
			}else{
				return False;
			}
			
			
			p_old = p_old -> next;
			p_new = p_new -> next;
		}
		
		if(p_old == NULL && p_new == NULL){
			return True;
		}
	}
	return False;
}
