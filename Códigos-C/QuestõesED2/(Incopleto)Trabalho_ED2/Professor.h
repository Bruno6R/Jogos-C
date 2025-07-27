typedef struct Professor{
	int id;
	int salario;
	char nome[45]; 
}Professor;

void printProf(Object prof){
	Professor *self = prof->item; 
	printf("Nome do Professor: %s / id: %d / salário: %i\n",
			self->nome, self->id, self->salario);
}

//Se eu coloco um 'float' como parametro ele quebra(?). De repente o erro:
//warning assignment from incompatible pointer type
//aparece na linha que contém o 'novo->set=setProfessor' (linha 38, dentro de 'new(Professor)'
void setProfessor(Object prof, char *nome, int id, int sal){
	Professor *self=prof->item;
	
	strcpy(self->nome, nome);
	self->id = id;  
	self->salario=sal;
}

Object new_Professor(){
	Object novo=new(Node);
	
	novo->item=malloc(sizeof(Professor));
	
	Professor *self=novo->item;
	
	//setando
	strcpy(self->nome, "{NULL}");
	self->id=0; 
	self->salario=0;
	novo->print = printProf;
	novo->type = PROFESSOR;
	//!!!?Porque ele dá um aviso de incopatibilidade de ponteiro só de usar um float?!!!
	novo->set=setProfessor;
	return novo;
}
