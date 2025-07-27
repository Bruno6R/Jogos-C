typedef struct _List{
	Object init;
	Object end;
	int size;
	//funcs da lista
	void (*enQueue)();
	void (*push)();
	Object (*pop)();
	Object (*pull)();
	void (*printAll)();
	void (*print)();
}_List;

typedef _List* List;

void setObjectIdInList(List lst, Object obj){
	if(lst->init){
		Object aux=lst->end; 
		obj->id=aux->id + 1;
	}else
		obj->id=1;
}

int listVerify(List lst, TypeObject who){
	
	//verificação genérica
	if(who<0){
		if(lst->init)
			return 1; 
		else
			return 0;
	}
	
	Object aux=lst->init; 
	while(aux){
		if(aux->type==who)
			return 1;
		aux=aux->next;
	}
	return 0;
}

int verifyErr(List lista, char* msg, TypeObject who){
	int exist = listVerify(lista, who);
	
	if(!exist){
		printf("%s\n", msg);
		return 1;
	}	
	return 0;
}

void listEnQueue(List lis, Object obj){
	if(!lis->init){
		lis->init=obj;
		lis->end=lis->init;
		lis->size=1;
		return;
	}
	
	obj->prev=lis->end;
	lis->end=obj;
	obj->prev->next=obj;
	lis->size++;
	return;
}

void listPush(Object lista, Object obj){
	List lis = lista->item;
	if(!lis->init){
		lis->init=obj;
		lis->end=lis->init;
		lis->size=1;
		return;
	}
	
	obj->next=lis->init;
	lis->init=obj;
	obj->next->prev=obj;
	lis->size++;
	return;
}

Object listPop(Object lista){
	List lst=lista->item; 
	if(!lst->init){
		printf("Não é possível remover pois a lista é null\n");
		return lista;
	}
	
	Object aux=lst->init; 
	lst->init=aux->next;
	if(aux->next)
		aux->next->prev=NULL;
	aux->next=NULL;
	lst->size--;
	return aux;
}

Object listPull(List lst, Object alvo){
	if(lst->init==alvo)
		lst->init=alvo->next;
	if(lst->end==alvo)	
		lst->end=alvo->prev;
	if(alvo->next)
		alvo->next->prev=alvo->prev;
	if(alvo->prev)
		alvo->prev->next=alvo->next;
	alvo->next=NULL;
	alvo->prev=NULL;
	lst->size--;
	return alvo;
}

void listPrintAll(List lst){
	
	if(verifyErr(lst, "Não existe nada na lista!", -1))
		return;
	
	//printando toda a lista
	Object aux = lst->init; 
	do{
		aux->print(aux);
		aux=aux->next;
	}while(aux);
}

void listPrint(List lst, TypeObject who){
	if(verifyErr(lst, "Vazio", who))
		return;
	
	Object aux = lst->init; 
	do{
		if(who==aux->type)
			aux->print(aux);
		aux=aux->next;
	}while(aux);
}

List new_List(){
	List lst=malloc(sizeof(List));
	lst->init=NULL;
	lst->end=NULL;
	lst->size=0;
	
	//setando funcs
	lst->enQueue = listEnQueue;
	lst->push = listPush;
	lst->pop = listPop; 
	lst->pull = listPull; 
	lst->printAll = listPrintAll; 
	lst->print = listPrint;
	return lst;
}
