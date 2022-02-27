struct ClassTable* ClassTableCreate(){
	struct ClassTable* table = (struct ClassTable*)malloc(sizeof(struct ClassTable));
	table -> head = NULL;
	return table;
}

struct ClassTableEntry* CInstall(char* name, struct AttrList* attrList, struct MethodList* methodList, struct ClassTableEntry* parent){
	int attrCount = 0, methodCount = 0;
	struct ClassTableEntry* entry = (struct ClassTableEntry*)malloc(sizeof(struct ClassTableEntry));
	entry -> class_name = name;
	entry -> attrList = attrList;
	entry -> methodList = methodList;
	entry -> parent = parent;
	
	
	struct AttrList* temp = attrList;
	while(temp != NULL){
		++attrCount;
		temp = temp -> next;
	}
	
	struct MethodList* temp2 = methodList;
	while(temp2 != NULL){
		++methodCount;
		temp2 = temp2 -> next;
	}
	
	entry -> classIndex = getClassIndex();
	entry -> attrCount = attrCount;
	entry -> methodCount = methodCount;
	return entry;
}

struct ClassTableEntry* CLookup(struct ClassTable* table, char* name){

	if(table == NULL)
		return NULL;
	struct ClassTableEntry* temp = table -> head;
	
	while(temp != NULL){
		if(strcmp(temp -> class_name, name) == 0)
			return temp;
		temp = temp -> next;
	}
	
	return NULL;
}


void addToClassTable(struct ClassTable* classTable, struct TypeTable* typeTable, struct dnode* root, char* class_name){ //only for user def type
	
	struct ClassTableEntry* entry = CInstall(class_name, NULL, NULL, NULL);
	
	struct ClassTableEntry* temp = classTable -> head;
	
	if(temp == NULL){
		classTable -> head = entry;
	}else{
		while(temp -> next != NULL)
			temp = temp -> next;
		
		temp -> next = entry;
	}
	
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
		
		case func_node: addToClassMethodList(class_entry,MInstall(root -> varname, field_dtype, root -> params));
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

	struct MethodList* method = MLookup(classEntry -> methodList,name);
	
	
	if(method == NULL){
		printf("Function not declared: %s",name);
		exit(0);
	}
	
	if(method -> dtype != return_type){
		printf("Function declared with different return types: %s",name);
		exit(0);
	}
	
	struct ParamStruct* method_p = method -> params;
	struct ParamStruct* p = params;
	while(method_p != NULL && p != NULL){
		if(method_p -> dtype != p -> dtype || method_p -> ctype != p -> ctype){
			printf("Parameters inconsistent with declaration: %s", name);
			exit(0);
		}
		method_p = method_p -> next;
		p = p -> next;
	}
	if(method_p != NULL || p != NULL){
		printf("Parameters inconsistent with declaration: %s", name);
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
	int count = 0;
	
	if(entry -> attrList == NULL)
		entry -> attrList = new_node;
	else{
		while(temp -> next != NULL){
			++count;
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
		
		if(count >= 7){
			printf("Member attribute count for %s is exceeding Limit(8)",entry -> class_name);
			exit(0);
		}
		else{
			new_node -> fieldIndex = count + 1;
			temp -> next = new_node;
		}
	}
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


struct MethodList* MInstall(char* method_name, struct TypeTableEntry* dtype, struct ParamStruct* params){
	struct MethodList* method = (struct MethodList*)malloc(sizeof(struct MethodList));
	method -> method_name = method_name;
	method -> methodIndex = 0;
	method -> flabel = getFuncLabel();
	method -> dtype = dtype;
	method -> params = params;
	method -> next = NULL;
	return method;
}

void addToClassMethodList(struct ClassTableEntry* entry, struct MethodList* new_node){
	struct MethodList* temp = entry -> methodList;
	int count = 0;
	
	if(entry -> methodList == NULL)
		entry -> methodList = new_node;
	else{
		while(temp -> next != NULL){
			++count;
			if(strcmp(temp -> method_name, new_node -> method_name) == 0){
				printf("Error: Two methods fields with the same name (%s)",temp -> method_name);
				exit(0);
			}
			temp = temp -> next;
		}
		
		if(strcmp(temp -> method_name, new_node -> method_name) == 0){
				printf("Error: Two methods fields with the same name (%s)",temp -> method_name);
				exit(0);
		}
		
		if(count >= 7){
			printf("Member attribute count for %s is exceeding Limit(8)",entry -> class_name);
			exit(0);
		}
		else{
			new_node -> methodIndex = count + 1;
			temp -> next = new_node;
		}
	}
}

struct MethodList* MLookup(struct MethodList* method, char* name){
	struct MethodList* temp = method;
	
	while(temp != NULL){
		if(strcmp(temp -> method_name, name) == 0)
			return temp;
		temp = temp -> next;
	}
	
	return NULL;
}
