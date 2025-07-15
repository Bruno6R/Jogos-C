#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Python.h"
#include "Alunos.h"
#include "List.h"

int main(){
	Object lst = new(List);
	Object pessoa = new(Aluno);
	setAluno(pessoa, "Paulo", 12);
	listPushEnd(lst, pessoa);
	printList(lst);
	
	return 0;
}

