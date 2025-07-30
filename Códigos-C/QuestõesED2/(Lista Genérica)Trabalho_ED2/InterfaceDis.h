int interfaceDis(){
	system("clear");
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

Object searchDis(List lst, int codDis){

	Object aux = lst->init;
	while(aux){
		if(aux->type!=DISCIPLINA){
			aux=aux->next;
			continue;
		}
		
		Disciplina *dis=aux->item;
		if(dis->codDis==codDis)
			return aux;
		aux=aux->next;
	}
	
	return NULL;
}

void cadastrarDisciplina(List lst){
	system("clear");
	char nomeDis[45];
	int codDis=0;
	
	printf("Qual é o nome da disciplina?:\n"); 
	scanf(" %44[^\n]s", nomeDis); 
	ov();
	
	//setando 
	Object disciplina = new(Disciplina);
	//setando obj id em uma lista
	codDis = disciplina->id;
	
	disciplina->set(disciplina, nomeDis, codDis);
	lst->enQueue(lst, disciplina);
	printf("Disciplina Criada!\n");
	enter();
}

void deletarDis(List lst){	
	if(verifyErr(lst, "Não existem Disciplinas cadastradas!", DISCIPLINA))
		return;
	
	lst->print(lst, DISCIPLINA);
	printf("\nDigite o código de Disciplina que deseja excluir(Digite 0 para cancelar):\n");
	int id=0;
	scanf(" %d", &id);
	ov();
	if(!id){
		printf("Operação cancelada!\n");
		return;
	}
	Object alvo = lst->search(lst, id); 
	if(!alvo){
		printf("Não existe uma Disciplina com esse código!\n");
		return;
	}
	lst->pull(lst, alvo);
	alvo->destroy(alvo);
	printf("Disciplina excluída!\n");
}

void deletarTodosDis(List lst){
	system("clear");
	if(verifyErr(lst, "Não existem Disciplinas cadastradas!", DISCIPLINA))
		return;
	
	if(!confirma("Tem certeza que deseja apagar todos os alunos?(essa ação não pode ser desfeita)"))
		return;
	
	Object aux=lst->init;
	Object prox=NULL;
	while(aux){
		//ignorar o que não for disciplina
		if(aux->type!=DISCIPLINA){
			aux=aux->next;
			continue;
		}
		
		prox=aux->next;
		Object deletar = lst->pull(lst, aux);
		deletar->destroy(deletar);
		aux=prox;
	}
	printf("Todas as Disciplinas foram apagadas!\n");
}

void interDisciplina(List lst){
	lst->search = searchDis;
	while(1)
		switch(interfaceDis()){
			case 0: 
				return;
			case 1:
				cadastrarDisciplina(lst);
				break;
			case 2: 
				lst->print(lst, DISCIPLINA);
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
