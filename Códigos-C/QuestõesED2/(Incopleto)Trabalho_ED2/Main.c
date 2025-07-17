#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Python.h"
#include "Alunos.h"
#include "Professor.h"
#include "List.h"

void linha(char sim, int qtd){
	for(int i=0; i<qtd; i++)
		printf("%c", sim); 
	printf("\n");
	
}

void ov(){
	while(getchar()!='\n'); 
}

void enter(){
	setbuf(stdin, NULL); 
	printf("Aperte ENTER para continuar...\n");
	ov();
}

int interface(){
	int esc;
	printf("1.Cadastrar Aluno\n"); 
	printf("2.Cadastrar Professor\n");
	printf("3.Mostrar Alunos\n");  
	printf("4.Mostrar Professor\n"); 
	linha('-', 35);
	printf("0.Sair\n");
	scanf(" %d", &esc);
	ov();
	return esc;
}

void cadastrarAluno(Object lista){
	Object aluno = new(Aluno);
	char nome[45];
	int id=0;
	List lst = lista->item;
	if(lst->init){
		Object obj = lst->end;
		Aluno *self = obj->item;
		id = self->matricula;
		id++;
	}else
		id=1;
	printf("Qual é o nome do aluno?:\n"); 
	scanf(" %44[^\n]s", nome); 
	
	//setando 
	setAluno(aluno, nome, id);
	printf("Aluno Criado!\n");
	listEnQueue(lista, aluno);
}

void cadastrarProfessor(Object lst){
	Object aluno = new(Aluno);
	char nome[45];
	int id=0;
	List lst = lista->item;
	if(lst->init){
		Object obj = lst->end;
		Aluno *self = obj->item;
		id = self->matricula;
		id++;
	}else
		id=1;
	printf("Qual é o nome do aluno?:\n"); 
	scanf(" %44[^\n]s", nome); 
	
	//setando 
	setAluno(aluno, nome, id);
	printf("Aluno Criado!\n");
	
}


int main(){
	Object lst_alunos = new(List);
	Object lst_professores = new(List);
	
	while(1)
		switch(interface()){
			case 0: 
				return 0;
			case 1: 
				cadastrarAluno(lst_alunos);
				break;
			case 2: 
				cadastrarProfessor(lst_professores);
				break;
			case 3: 
				printListAl(lst_alunos);
				break;
			case 4: 
				printListProf(lst_professores);
				break;
			default: 
				printf("Opção inválida!\n"); 
				enter();
		}
	
	return 0;
}
