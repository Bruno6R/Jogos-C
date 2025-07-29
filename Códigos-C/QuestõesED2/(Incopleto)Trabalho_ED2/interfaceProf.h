int interfaceProf(){
	printf("1.Cadastrar Professor\n");
	printf("2.Listar Professores Cadastrados\n");
	printf("3.Apagar um Professor\n");
	printf("4.Excluir todos os Professores\n");
	linha('-', 35);
	printf("0.Voltar\n: ");
	int esc;
	scanf(" %d", &esc);
	ov();
	return esc;
}

void cadastrarProfessor(List lst){
	char nome[45];
	int id=0;
	double sal=0;
		
	printf("Qual é o nome do Professor?:\n"); 
	scanf(" %44[^\n]s", nome); 
	printf("Qual é o salário de %s?:\n", nome);
	scanf(" %lf", &sal);
	
	//setando 
	Object prof = new(Professor);
	
	id=prof->id;
	prof->set(prof, nome, id, sal);
	lst->enQueue(lst, prof);
	printf("Professor Criado!\n");
	enter();
}

Object searchProf(List lst, int id){
	
	Object aux = lst->init;
	while(aux){
		if(aux->type!=PROFESSOR){
			aux=aux->next;
			continue;
		}
		
		Professor *prof=aux->item;
		if(prof->id==id)
			return aux;
		aux=aux->next;
	}
	
	return NULL;
}

void deletarProf(List lst){
	
	//verifica a existência de professores
	if(verifyErr(lst, "Não existem professores cadstrados!", PROFESSOR))
		return;
	
	lst->print(lst, PROFESSOR);
	printf("\nDigite o número do ID do Professor que deseja excluir:\n");
	int id;
	scanf(" %d", &id);
	ov();
	Object alvo = lst->search(lst, id);
	if(!alvo){
		printf("Não existe um professor com esse ID!\n");
		return;
	}
	lst->pull(lst, alvo);
	alvo->destroy(alvo);
	printf("Professor excluído\n");
}

void deletarTodosProf(List lst){
	
	//verificando a existência de professores na lista
	if(verifyErr(lst, "Não existem professores cadastrados!", PROFESSOR))
		return;
	
	printf("Tem certeza que deseja apagar todos os Professores?(essa ação não pode ser desfeita)\n");
	printf("1.Sim, eu tenho certeza!\n");
	printf("2.Pensando bem... acho melhor não\n");  
	int esco;
	scanf(" %d", &esco);
	ov();
	esco--;
	
	if(esco){
		printf("Ação cancelada!\n");
		return;
	}
	
	Object prox=NULL;
	Object aux=lst->init;
	while(aux){
		//ignora o que não for professor
		if(aux->type!=PROFESSOR){
			aux=aux->next; 
			continue;
		}
		
		prox = aux->next;
		Object deletar = lst->pull(lst, aux);
		deletar->destroy(deletar);
		aux=prox;
	}
	printf("Todos os professores foram apagados!\n");
}

void interProfessor(List lst){
	lst->search=searchProf;
	while(1)
		switch(interfaceProf()){
			case 0: 	
				return;
			case 1:
				cadastrarProfessor(lst);
				break;
			case 2:
				lst->print(lst, PROFESSOR);
				enter();
				break;
			case 3:
				deletarProf(lst);
				enter();
				break;
			case 4:
				deletarTodosProf(lst);
				enter();
				break;
			default: 
				printf("Opção inválida!\n");
				enter();
		}
}
