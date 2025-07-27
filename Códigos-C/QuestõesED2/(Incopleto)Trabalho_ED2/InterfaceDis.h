int interfaceDis(){
	printf("1.Cadastrar Disciplina\n");
	printf("2.Listar Disciplinas Cadastradas\n");
	printf("3.Apagar uma Disciplina\n");
	printf("4.Excluir todas as Disciplinas\n");
	linha('-', 35);
	printf("0.Voltar\n: ");
	int esc;
	scanf(" %d", &esc);
	ov();
	return esc;
}

Object searchDis(Object lista, int codDis){
	List lst = lista->item;
	
	Object aux = lst->init;
	do{
		if(aux && aux->type!=DISCIPLINA){
			aux=aux->next;
			continue;
		}
		
		Disciplina *dis=aux->item;
		if(dis->codDis==codDis)
			return aux;
		aux=aux->next;
	}while(aux);
	
	return NULL;
}

void cadastrarDisciplina(Object lista){
	char nomeDis[45];
	int codDis=0;
	List lst = lista->item;
	
	printf("Qual é o nome da disciplina?:\n"); 
	scanf(" %44[^\n]s", nomeDis); 
	ov();
	
	//setando 
	Object disciplina = new(Disciplina);
	//setando obj id em uma lista
	setObjectIdInList(lst, disciplina);
	
	codDis = disciplina->id;
	setDisciplina(disciplina, nomeDis, codDis);
	listEnQueue(lista, disciplina);
	printf("Disciplina Criada!\n");
	enter();
}

void deletarDis(Object lista){	
	List lst = lista->item;

	if(verifyErr(lista, "Não existem Disciplinas cadastradas!", DISCIPLINA))
		return;
	
	lst->print(lista, DISCIPLINA);
	printf("\nDigite o código de Disciplina que deseja excluir:\n");
	int id;
	scanf(" %d", &id);
	ov();
	Object alvo = searchDis(lista, id); 
	if(!alvo){
		printf("Não existe uma Disciplina com esse código!\n");
		enter();
		return;
	}
	listPull(lista, alvo);
	destroy(alvo);
	printf("Disciplina excluída!\n");
}

void deletarTodosDis(Object lista){
		
	List lst = lista->item;
	
	if(verifyErr(lista, "Não existem Disciplinas cadastradas!", DISCIPLINA))
		return;
	
	printf("Tem certeza que deseja apagar todos os alunos?(essa ação não pode ser desfeita)\n");
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
	
	Object aux=lst->init;
	Object prox=NULL;
	while(aux){
		//ignorar o que não for disciplina
		if(aux->type!=DISCIPLINA){
			aux=aux->next;
			continue;
		}
		
		prox=aux->next;
		Object deletar = lst->pull(lista, aux);
		deletar->destroy(deletar);
		aux=prox;
	}
	printf("Todas as Disciplinas foram apagadas!\n");
}

void interDisciplina(Object lst){
	List lista = lst->item;
	while(1)
		switch(interfaceDis()){
			case 0: 
				return;
			case 1:
				cadastrarDisciplina(lst);
				break;
			case 2: 
				lista->print(lst, DISCIPLINA);
				enter();
				break;
			case 3:
				deletarDis(lst);
				enter();
				break;
			case 4:
				deletarTodosDis(lst);
				enter();
				break;
			default:
				printf("Opção inválida!\n");
				enter();
		}
}
