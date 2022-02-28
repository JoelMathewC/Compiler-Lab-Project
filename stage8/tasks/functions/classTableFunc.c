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
			
			if(attrList == NULL){
				attrList = AInstall(temp_a -> varname, temp_a -> dim, temp_a -> dtype, temp_a -> ctype);
				entry -> attrList = attrList;
			}else
				addToClassAttrList(entry, AInstall(temp_a -> varname, temp_a -> dim, temp_a -> dtype, temp_a -> ctype));

			temp_a = temp_a -> next;
			entry -> attrCount += 1;
		}
		
		while(temp_m != NULL){
		
			if(methodList == NULL){
				methodList = MInstall(temp_m -> method_name, temp_m -> flabel, temp_m -> dtype, temp_m -> params);
				entry -> methodList = methodList;
			}else
				addToClassMethodList(entry, MInstall(temp_m -> method_name, temp_m -> flabel, temp_m -> dtype, temp_m -> params));
				
			temp_m = temp_m -> next;
			entry -> methodCount += 1;
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
		
		case func_node: addToClassMethodList(class_entry,MInstall(root -> varname, -1, field_dtype, root -> params));
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
			new_node -> fieldIndex = entry -> attrCount + 1;
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


struct MethodList* MInstall(char* method_name, int flabel, struct TypeTableEntry* dtype, struct ParamStruct* params){
	struct MethodList* method = (struct MethodList*)malloc(sizeof(struct MethodList));
	method -> method_name = method_name;
	method -> methodIndex = 0;
	method -> flabel = flabel;
	method -> dtype = dtype;
	method -> params = params;
	method -> next = NULL;
	return method;
}

void addToClassMethodList(struct ClassTableEntry* entry, struct MethodList* new_node){
	struct MethodList* temp = entry -> methodList;
	
	if(entry -> methodList == NULL)
		entry -> methodList = new_node;
	else{
		while(temp -> next != NULL){
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
		
		if(entry -> methodCount >= 8){
			printf("Member attribute count for %s is exceeding Limit(8)",entry -> class_name);
			exit(0);
		}
		else{
			new_node -> methodIndex = entry -> methodCount + 1;
			temp -> next = new_node;
		}
	}
	
	entry -> methodCount += 1;
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
