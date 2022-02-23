struct TypeTable* TypeTableCreate(){
	struct TypeTable* table = (struct TypeTable*)malloc(sizeof(struct TypeTable));
	char* name;

	
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"null");
	struct TypeTableEntry* null_type = TInstall(name,0,NULL);
	
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"void");
	struct TypeTableEntry* void_type = TInstall(name,0,NULL);
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"bool");
	struct TypeTableEntry* bool_type = TInstall(name,0,NULL);
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"int");
	struct TypeTableEntry* int_type = TInstall(name,1,NULL);
	
	name = (char*)malloc(sizeof(char));
	strcpy(name,"string");
	struct TypeTableEntry* str_type = TInstall(name,1,NULL);
	
	null_type -> next = void_type;
	void_type -> next = bool_type;
	bool_type -> next = int_type;
	int_type -> next = str_type;
	
	table -> head = null_type;
	return table;
	
}

struct TypeTableEntry* TInstall(char* name,int size, struct FieldList* fl){
	struct TypeTableEntry* node = (struct TypeTableEntry*)malloc(sizeof(struct TypeTableEntry));
	node -> type_name = name;
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
	
	printf("Error: unknown type requested");
	exit(0);
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


void addToTypeTable(struct TypeTable* table, struct dnode* root, char* type_name){
	
	struct TypeTableEntry* entry = TInstall(type_name,1, NULL);
	
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
	if(entry -> fieldList == NULL)
		entry -> fieldList = new_node;
	else{
		while(temp -> next != NULL)
			temp = temp -> next;
		
		temp -> next = new_node;
	}
}

void generateFieldList(struct TypeTableEntry* type_entry, struct dnode* root, struct TypeTableEntry* field_dtype, struct TypeTable* table){
	
	static int fieldIndex = 0;
	if(root == NULL)
		return;
	
	switch(root -> nodetype){
	
		case connector : generateFieldList(type_entry,root -> left,field_dtype,table);
				generateFieldList(type_entry,root -> right,field_dtype,table);
				break;
		
		case type_node: 
				generateFieldList(type_entry,root -> left,TLookup(table,root -> type_name),table);
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
