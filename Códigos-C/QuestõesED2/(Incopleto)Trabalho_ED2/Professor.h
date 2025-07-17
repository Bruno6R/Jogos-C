typedef struct Professor{
	int id;
	char nome[100]; 
}Professor;

Object new_Professor(){
	Object novo=new(Node);
	novo->item=malloc(sizeof(Professor));
	Professor *self=novo->item;
	strcpy(self->nome, " ");
	self->id=0; 
	return novo;
}

void setProfessor(Object prof, char *nome, int id){
	Professor* self=prof->item;
	strcpy(self->nome, nome);
	self->id = id;  
}

void printProf(Object prof){
	Professor *self = prof->item; 
	printf("Nome do Professor: %s / id: %d\n",
			self->nome, self->id);
}
