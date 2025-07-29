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
//-Linha 82:Interface Dis. Mudar para while-case
//-Mudar o id, fazer com índice;
//-Implementar uma maneira de cancelar as ações;
//-O 'listPrintAll' ta esquisito, testar isso depois;
//-Implementar um jeito de cadastrar um professor como responsável de uma disciplina;
//-Um função para editar os dados;
//-Adicionar um 'system("clear")' nos lugares corretos;

int main(){
	List lst = new(List);
	while(1){
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
	return 0;
}
