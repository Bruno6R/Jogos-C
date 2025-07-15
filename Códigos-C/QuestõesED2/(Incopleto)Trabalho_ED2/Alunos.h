typedef struct Aluno{
	int matricula;
	char nome[45];
}Aluno;

Object new_Aluno(){
	Object novo=new(Node);
	novo->item=malloc(sizeof(Aluno));
	Aluno *self=novo->item;
	self->matricula=0;
	strcpy(self->nome, "");
	return novo;
}

void setAluno(Object aluno, char *nome, int mat){
	Aluno *self=aluno->item;
	
	self->matricula=mat;
	strcpy(self->nome, nome);
}

void printAl(Object aluno){
	Aluno *self=aluno->item;
	printf("Nome: %s / Matrícula: %d\n", self->nome, self->matricula);
}
