#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5 
#define INEXISTENTE -1

//Iterativas
void fiboIte(int n){
	int soma=1;
	int anterior=0, atual=0;
	for(int i=0; i<n; i++){
		soma+=anterior;
		anterior=atual;
		atual=soma;
		printf("%d,", soma);
	}
	printf("\b.");
}

void organizaInsert(int *vet){
	for(int i=1; i<MAX; i++){
		int tmp = vet[i]; 
		for(int j=(i-1); j>=0; j--){
			if(tmp<=vet[j])
				vet[j+1] = vet[j];
			else{
				vet[j+1] = tmp; 
				break;
			}
			if(!j) 
				vet[j]=tmp; 
		}
	}
}

void mostraArray(int array[]){
	for(int i=0; i<MAX; i++) 
		printf("[%d]: %d\n", i, array[i]);
}

void preencheArray(int *array){
	for(int i=0; i<MAX; i++) 
		array[i] = rand()%100; 
}

//recursivas
void fiboRec(int n, int atual, int anterior){
	if(!n){
		
		return; 
	}
	int soma = atual + anterior; 
	if(!soma) 
		soma=1;
	printf("%d,", soma);
	fiboRec(n-1, soma, atual);
}

int buscaBin(int *array, int tam, int inic, int valor){
	int fim = tam, meio = (fim - inic)/2 + inic; 
	
	if(fim<inic) 
		return INEXISTENTE;
	
	if(array[meio]==valor)
		return meio; 
	if(array[meio]>valor) 
		return buscaBin(array, meio-1, inic, valor);
	else	
		return buscaBin(array, fim, meio+1, valor); 
}

int buscaSeq(int *array, int tam, int valor){
	if(tam<0) 
		return INEXISTENTE; 
	if(array[tam] == valor) 
		return tam; 
	else 
		return buscaSeq(array, tam-1, valor); 
}

int maiorValorArray(int *vetor, int tam){
	if(!tam) 
		return vetor[tam]; 
	int maior = maiorValorArray(vetor, tam-1); 
	if(maior>vetor[tam]) 
		return maior;
	else 
		return vetor[tam];
}

int somaArray(int *array, int tam){
	if(!tam) 
		return array[tam]; 
	return array[tam]+somaArray(array, tam-1); 
}

int potencia(int x, int y){
	if(y==1) 
		return x; 
	return x*potencia(x, y-1); 
}

int main(){
	srand(time(NULL)); 
	int vet[MAX], quest;
	preencheArray(vet); 
	printf("Digite o número da questão:\n");
	scanf(" %d", &quest); 
	system("clear");
	int x, y;
	switch(quest){
		case 1: 
			printf("Digite a base:\n");
			scanf(" %d", &x);
			printf("Qual é o expoente?:\n");
			scanf(" %d", &y);
			printf("Resultado: %d\n", potencia(x,y));
			break; 
		case 2: 
			printf("Array:\n");
			mostraArray(vet); 
			int a = somaArray(vet, MAX-1);
			printf("Soma do Vetor: %d\n", a);			
			break; 
		case 3: 
			x = maiorValorArray(vet, MAX-1);
			mostraArray(vet);
			printf("O maior valor do array é: %d", x); 
			break;
		case 4:
			mostraArray(vet); 
			printf("Digite o valor que deseja encontrar o índice: \n");
			scanf(" %d", &x);
			y = buscaSeq(vet, MAX-1, x); 
			if(y==INEXISTENTE) 
				printf("Esse valor não se encontra no vetor!\n");
			else
				printf("Esse valor se encontra no índice: %d\n", y);
			break; 
		case 5:
			organizaInsert(vet); 
			mostraArray(vet);
			printf("Digite o valor que deseja encontrar o índice(Binário): \n");
			scanf(" %d", &x);
			y = buscaBin(vet, MAX-1, 0, x);
			if(y!=INEXISTENTE)
				printf("O valor se encontra em: %d", y);
			else 
				printf("Valor não encontrado no array\n");
			break; 
		case 6: 
			printf("Fibonacci(Iterativo):\n");
			fiboIte(45); 
			printf("\nFibonacci(recursivo):\n");
			fiboRec(45, 0, 0); 
			break;
	}
	return 0;
}

