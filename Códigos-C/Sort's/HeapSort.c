#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_VETOR_MAX 5

//Funções extras:
void preencherVetor(int *vetor, int tam){
	for(int i=0; i<tam; i++)
		vetor[i] = rand()%100; 
}

void mostrarVetor(int *vetor, int tam){
	for(int i=0; i<tam; i++)
		printf("[%d] ", vetor[i]);
	printf("\n");
}

void enter(){
	setbuf(stdin, NULL); 
	printf("Aperte ENTER para continuar...");
	while(getchar()!='\n'); 
}

//HeapSort:
void aplicarHeap(int *vetor, int tam, int pos){
	int raiz = pos; 
	int esquerda = 2*pos + 1; 
	int direita = 2*pos + 2; 
	
	if(vetor[esquerda]>vetor[raiz] && esquerda < tam) 	
		raiz = esquerda; 
	if(vetor[direita]>vetor[raiz] && direita < tam) 
		raiz = direita;
		
	if(raiz!=pos){
		int aux = vetor[raiz]; 
		vetor[raiz] = vetor[pos]; 
		vetor[pos] = aux; 
		aplicarHeap(vetor, tam, raiz); 
	}
}

void organizaHeap(int *vetor, int tam){
	for(int i=tam-1; i>0; i--){
		int aux = vetor[i]; 
		vetor[i] = vetor[0]; 
		vetor[0] = aux; 
		aplicarHeap(vetor, i, 0);
	}
}

void heapSort(int *vetor, int tam){
	for(int i=(tam/2) - 1; i>=0; i--) 
		aplicarHeap(vetor, tam, i);

	//
	printf("Vetor quase ordenado:\n");
	mostrarVetor(vetor, tam); 
	enter();
	
	organizaHeap(vetor, tam);
}

int main(){
	//srand(time(NULL));
	int vetor[TAM_VETOR_MAX];
	preencherVetor(vetor, TAM_VETOR_MAX); 
	
	printf("Vetor antes de ordenado:\n");
	mostrarVetor(vetor, TAM_VETOR_MAX); 
	enter();
	
	heapSort(vetor, TAM_VETOR_MAX); 
	
	printf("Vetor Organizado: ");
	mostrarVetor(vetor, TAM_VETOR_MAX); 
	return 0;
}

