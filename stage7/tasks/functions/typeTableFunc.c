struct TypeTable* TypeTableCreate(){
	struct TypeTable* table = (struct TypeTable*)malloc(sizeof(struct TypeTable));
	char* name;

	
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"null");
	struct TypeTableEntry* null_type = TInstall(name,0, voidType,NULL);
	
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"void");
	struct TypeTableEntry* void_type = TInstall(name,0,voidType,NULL);
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"bool");
	struct TypeTableEntry* bool_type = TInstall(name,0, boolType,NULL);
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"int");
	struct TypeTableEntry* int_type = TInstall(name,1, intType,NULL);
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"string");
	struct TypeTableEntry* str_type = TInstall(name,1, stringType,NULL);
	
	null_type -> next = void_type;
	void_type -> next = bool_type;
	bool_type -> next = int_type;
	int_type -> next = str_type;
	
	table -> head = null_type;
	return table;
	
}

struct TypeTableEntry* TInstall(char* name,int size, int nodetype, struct FieldList* fl){
	struct TypeTableEntry* node = (struct TypeTableEntry*)malloc(sizeof(struct TypeTableEntry));
	node -> type_name = name;
	node -> nodetype = nodetype;
	node -> fieldList = fl;
	node -> size = size;
	node -> next = NULL;
	return node;
}


int GetSize(struct TypeTable* table, char* name){
	struct TypeTableEntry* temp = table -> head;
	
	while(temp != NULL){
		if(strcmp(temp -> type_name, name) == 0)
			return temp -> size;
		temp = temp -> next;
	}
	
	printf("Error: unknown type's size requested");
	exit(0);
}

struct TypeTableEntry* TLookup(struct TypeTable* table, char* name){
	struct TypeTableEntry* temp = table -> head;
	
	while(temp != NULL){
		if(strcmp(temp -> type_name, name) == 0)
			return temp;
		temp = temp -> next;
	}
	
	return NULL;
}


void addTupleToTypeTable(struct TypeTable* table, struct ParamStruct* pt, char* type_name){ //only for tuple type
	
	struct FieldList* fl = makeFieldListFromParam(pt);
	int size = calculateDtypeSize(fl,table);
	
	struct TypeTableEntry* entry = TInstall(type_name,size, tupleType,fl);
	
	struct TypeTableEntry* temp = table -> head;
	while(temp -> next != NULL)
		temp = temp -> next;
		
	temp -> next = entry;
}


void addUserDefToTypeTable(struct TypeTable* table, struct dnode* root, char* type_name){ //only for user def type
	
	struct TypeTableEntry* entry = TInstall(type_name,1, userDefType, NULL);
	
	struct TypeTableEntry* temp = table -> head;
	while(temp -> next != NULL)
		temp = temp -> next;
		
	temp -> next = entry;
	
	
	generateFieldList(entry, root,NULL, table);
	entry -> size = calculateDtypeSize(entry -> fieldList,table);
	
}

int calculateDtypeSize(struct FieldList* fl, struct TypeTable* table){
	struct FieldList* temp = fl;
	int count = 0;
	
	while(temp != NULL){
		count += temp -> dtype -> size;
		temp = temp -> next;
	}
	return count;
}



void generateFieldList(struct TypeTableEntry* type_entry, struct dnode* root, struct TypeTableEntry* field_dtype, struct TypeTable* table){
	
	static int fieldIndex = 0;
	if(root == NULL)
		return;
	
	switch(root -> nodetype){
	
		case connector : generateFieldList(type_entry,root -> left,field_dtype,table);
				generateFieldList(type_entry,root -> right,field_dtype,table);
				break;
		
		case type_node: generateFieldList(type_entry,root -> left,TLookup(table,root -> type_name),table);
				break;
		
		case leaf_node: addToFieldList(type_entry,FInstall(root -> varname, root -> dim, fieldIndex++, field_dtype));
				break;
				
		
		default: printf("Error: Invalid Declaration within type block");
			exit(0);
	}
}


void printTypeTable(struct TypeTable* table){

	if(table == NULL){
		printf("No types\n");
		fflush(stdout);
	}
	else{
		struct TypeTableEntry* entry = table -> head;
		struct FieldList* fl;
		printf("NAME : FIELDS : FIELD INDEX\n");
		while(entry != NULL){
			printf("%s : ",entry -> type_name);
			fl = entry -> fieldList;
			while(fl != NULL){
				printf("%s(%d) ",fl -> varname,fl -> fieldIndex);
				fl = fl -> next;
			}
			printf("\n");
			entry = entry -> next;
	}
	
	}
	
	
	
}




//--------------------------------------- FIELD FUNC ----------------------------------------------

struct FieldList* FInstall(char* varname, int dim, int fieldIndex, struct TypeTableEntry* dtype){
	struct FieldList* fl = (struct FieldList*)malloc(sizeof(struct FieldList));
	fl -> varname = varname;
	fl -> dim = dim;
	fl -> fieldIndex = fieldIndex;
	fl -> dtype = dtype;
	fl -> next = NULL;
	return fl;
}

void addToFieldList(struct TypeTableEntry* entry, struct FieldList* new_node){
	struct FieldList* temp = entry -> fieldList;
	int count = 0;
	
	if(entry -> fieldList == NULL)
		entry -> fieldList = new_node;
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
		
		if(count >= 8){
			printf("Member attribute count for %s is exceeding Limit(8)",entry -> type_name);
			exit(0);
		}
		else
			temp -> next = new_node;
	}
}

struct FieldList* FLookup(struct FieldList* fl, char* name){
	struct FieldList* temp = fl;
	
	while(temp != NULL){
		if(strcmp(temp -> varname, name) == 0)
			return temp;
		temp = temp -> next;
	}
	
	return NULL;
}
