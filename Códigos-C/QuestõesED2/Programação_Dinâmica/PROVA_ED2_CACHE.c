#include <stdio.h>
#include <stdlib.h>

typedef struct Valores{
	int valor;
	struct Valores *prox;
	struct Valores *ant;
}Valores;

Valores *add(Valores *lst, int valor){
	Valores *new=malloc(sizeof(Valores));
	
	new->valor = valor;
	
	if(!lst){
		new->prox=NULL;
		new->ant=NULL;
		return new;
	}
	
	new->prox=lst;
	lst->ant=new;
	new->ant=NULL;
	return new;
}

void mostrar(Valores *lst){
	//while(lst){
		//printf("[%d] ", lst->valor);
		//lst=lst->prox;
	//}
	
	if(!lst)
		return;
	mostrar(lst->prox);
	printf("[%d] ", lst->valor);
}

void inicArr(int *cache, int tam){
	for(int i=0; i<tam; i++)
		cache[i]=0;
}

int repetiu(Valores *lst, int valor){
	while(lst->ant){
		lst=lst->ant;
		if(lst->valor==valor)
			return 1;
	}
	return 0;
}

void mostArr(int *arr, int tam){
	for(int i=0; i<tam; i++){
		if(arr[i])
			printf("[%d] ", arr[i]);
	}
}

void encherCache(Valores *lst, int *cache, int tam){
	int i=0;
	while(lst && i<tam){
		if(!repetiu(lst,lst->valor) && lst->valor){
			cache[i]=lst->valor;
			i++;
		}
		lst=lst->prox;
	}
}

int main(){
	Valores *lst=NULL;
	int tamCache, valor;
	printf("Digite o tamanho máximo do cache:\n");
	scanf(" %d", &tamCache);
	
	printf("Digite os valores(Maiores que 0) dos dados:\n");
	while(1){
		scanf(" %d", &valor);
		if(valor<=0){
			lst = add(lst, valor);
			break;
		}
		lst = add(lst, valor);
	}
	
	system("cls");
	printf("Tamanho do cache: %d\n", tamCache);
	printf("Valores: ");
	mostrar(lst);
	printf("\nCache: ");
	
	int cache[tamCache];
	inicArr(cache, tamCache);
	
	encherCache(lst, cache, tamCache);
	
	mostArr(cache, tamCache);
	
	return 0;
}