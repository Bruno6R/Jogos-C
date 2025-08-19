#ifdef _WIN32
	#ifndef _WINDOWS_
		#include "windows.h"
	#endif
	void sleep(int tempo){
		tempo*=1000;
		Sleep(tempo);
	}
	
	void clear(){
		system("cls");
	}
#endif

#ifdef __GNU__
	void sleep(int tempo){
		system("sleep %d", tempo);
	}
	void clear(){
		system("clear");
	}
#endif

//CORES
#define PRETO "\033[30m"
#define VERMELHO "\033[31m"
#define VERDE "\033[32m"
#define AMARELO "\033[33m"
#define AZUL "\033[34m"
#define ROXO "\033[35m"
#define CIANO "\033[36m"
#define FIM_COR "\033[0m"

void preencherVetor(int *vetor, int tam){
	for(int i=0; i<tam; i++)
		vetor[i] = rand()%100; 
}

void mostrarVetor(int *vetor, int tam){
	for(int i=0; i<tam; i++)
		printf("[%d] ", vetor[i]);
	printf("\n");
}

void ov(){
	int a=0;
	while((a = getchar())!='\n' && a!=EOF); 
}

void enter(){
	printf("Aperte ENTER para continuar...\n");
	ov();
}

void linha(char sim, int qtd){
	for(int i=0; i<qtd; i++)
		printf("%c", sim); 
	printf("\n");
}

