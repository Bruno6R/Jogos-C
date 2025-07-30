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
	system("clear");
	int esc;
	printf("1.DISCIPLINAS\n"); 
	printf("2.PROFESSORES\n");
	linha('-', 35);
	printf("0.Sair\n: ");
	scanf(" %d", &esc);
	ov();
	return esc;
}

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
