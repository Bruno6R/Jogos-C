typedef struct Disciplina{
	int codDis;
	char nomeDis[45];
}Disciplina;

void printDis(Object disciplina){
	Disciplina *self=disciplina->item;
	if(!self){
		printf("A disciplina não existe!\n");
		return;
	}
	printf("Nome da disciplina: %s / Codigo Disciplina: %d\n",
	self->nomeDis, self->codDis);
}

void setDisciplina(Object disciplina, char *nomeDis, int codDis){
	Disciplina *self=disciplina->item;
	
	self->codDis=codDis;
	strcpy(self->nomeDis, nomeDis);
}

Object new_Disciplina(){
	Object novo=new(Node);
	
	novo->item=malloc(sizeof(Disciplina));
	
	Disciplina *self=novo->item;
	
	//setando
	self->codDis=0;
	strcpy(self->nomeDis, "{NULL}");
	novo->print = printDis;
	novo->type = DISCIPLINA; 
	novo->set = setDisciplina;
	return novo;
}
