#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tools.h"
#include "Object.h"
#include "List.h"
#include "Disciplina.h"
#include "Professor.h"
#include "interfaceDis.h"
#include "interfaceProf.h"

int interface(){
	int esc;
	printf("1.DISCIPLINAS\n"); 
	printf("2.PROFESSORES\n");
	linha('-', 35);
	printf("0.Sair\n: ");
	scanf(" %d", &esc);
	ov();
	return esc;
}


//Problemas:
//-Existe um erro ao cadastrar objetos. Ao setar 'no->item=NULL' 3 vezes,
//o código da erro(dentro de 'new(Node)';
//-Colocar as funções relacionadas a lista dentro da struct da lista;
//-Implementar um jeito de cancelar as operações;
//-O 'listPrintAll' ta esquisito, testar isso depois;
//-Um função para editar os dados;
//-Implementar um jeito de cadastrar um professor como responsável de uma disciplina;
//-Adicionar um 'system("clear")' nos lugares corretos;

int main(){
	List lst = new(List);
	
	while(1)
		switch(interface()){
			case 0: 
				return 0;
			case 1: 
				interDisciplina(lst);
				break;
			case 2: 
				interProfessor(lst);
				break;
			default: 
				printf("Opção inválida!\n"); 
				enter();
		}
}
