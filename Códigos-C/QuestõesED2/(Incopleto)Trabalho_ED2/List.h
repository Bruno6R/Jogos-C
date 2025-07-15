typedef struct _List{
	Object init;
	Object end;
	int size;
}_List;

typedef _List* List;

Object new_List(){
	Object novo=new(Node);
	novo->item=malloc(sizeof(_List));
	List lst=novo->item;
	lst->init=NULL;
	lst->end=NULL;
	lst->size=0;
	return novo;
}

void printList(Object lista){
	List lst = lista->item;
	
	if(!lst->init){
		printf("Não existe lista!\n");
		return;
	}
	
	Object alun=lst->init;
	do{
		printAl(alun);
		alun=alun->next;
	}while(alun);
}

void listEnQueue(Object lista, Object obj){
	List lis = lista->item;
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

Object listPop(Object lista, Object obj){
	List lst=lista->item; 
	if(!lst->init){
		printf("Não é possível remover pois a lista é null\n");
		return lista;
	}
	
	Object aux=lst->init; 
	lst->init=aux->next;
	aux->next->prev=NULL;
	aux->next=NULL;
	return aux;
}

