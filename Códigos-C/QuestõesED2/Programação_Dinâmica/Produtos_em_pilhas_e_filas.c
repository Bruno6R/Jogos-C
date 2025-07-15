#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT " %d"
#define STR " %s"
#define FLOAT " %f"

typedef struct ProdutoPil{
	float valor; 
	int qtd, id;
	char nome[20];
	struct ProdutoPil* anterior;  
}ProdutoPil; 

typedef struct ProdutoFil{
	float valor; 
	int qtd, id;
	char nome[20];
	struct ProdutoFil* prox;  
}ProdutoFil;

void ov(){
	while(getchar()!='\n');	
}

void enter(){
	setbuf(stdin, NULL); 
	printf("Aperte ENTER para continuar...");
	while(getchar()!='\n');
}

void linha(char sim, int qtd){
	for(int i=0; i<qtd; i++)
		printf("%c", sim);
	printf("\n");
}

int interface(){
	system("clear");
	int escolha; 
	printf("1.Adicionar produto(Pilha)\n");
	printf("2.Adicionar produto(Fila)\n");
	printf("3.Listar Produtos\n");
	linha('-', 20); 
	printf("0. Sair\n: ");
	scanf(" %d", &escolha);
	while(getchar()!='\n'); 
	return escolha;
}

void input(char *msg, char *tipo, void* var){
	printf("%s", msg);
	scanf(tipo, var);
}

void mostrarProdutosFil(ProdutoFil* inicio){
	while(inicio){
		linha('+', 25);
		printf("Nome: %s\nID: %d\nValor: %.2f\nQuantidade: %d\n",
		inicio->nome, inicio->id, inicio->valor, inicio->qtd);
		
		inicio = inicio->prox;
	}
	printf("\n");
}

void mostrarProdutosPil(ProdutoPil* prod){
	while(prod){
		linha('+', 25);
		printf("Nome: %s\nID: %d\nValor: %.2f\nQuantidade: %d\n",
		prod->nome, prod->id, prod->valor, prod->qtd);
		
		prod = prod->anterior;
	}
	printf("\n");
}

void mostrarTodosProds(ProdutoPil* topoPilha, ProdutoFil* inicioDaFila){
	printf("Pilha:\n");
	if(!topoPilha)
		printf("{NULL}");
	mostrarProdutosPil(topoPilha);
	enter();
	printf("Fila:\n");
	if(!inicioDaFila)
		printf("{NULL}");
	mostrarProdutosFil(inicioDaFila);
	enter();	
}

ProdutoFil* setNovoProdFil(ProdutoFil* fim, int *id){
	ProdutoFil* novoProd;
	novoProd = malloc(sizeof(ProdutoFil));
	
	printf("Digite o nome do produto: ");
	scanf(" %19[^\n]s", novoProd->nome);
	ov();
	input("Digite o valor do produto: ", FLOAT, &novoProd->valor);
	ov();
	input("Quantos tem?: ", INT, &novoProd->qtd); 
	ov();
	*id += 1;
	novoProd->id = *id;
	
	if(fim)
		fim->prox = novoProd;
		
	novoProd->prox = NULL;
	printf("Produto adicionado!\n");
	enter();
	return novoProd;
}

ProdutoPil* setNovoProdPil(ProdutoPil* antes, int *id){
	ProdutoPil* novoProd;
	novoProd = malloc(sizeof(ProdutoPil));
	
	printf("Digite o nome do produto: ");
	scanf(" %19[^\n]s", novoProd->nome);
	ov();
	input("Digite o valor do produto: ", FLOAT, &novoProd->valor);
	ov();
	input("Quantos tem?: ", INT, &novoProd->qtd); 
	ov();
	*id += 1;
	novoProd->id = *id;
	
	novoProd->anterior = antes;
	printf("Produto adicionado!\n");
	enter();
	return novoProd;
}

int main(){
	ProdutoPil* topoPilha = NULL;
	
	ProdutoFil* inicioDaFila = NULL;
	ProdutoFil* fimDaFila = NULL;
	int id=0;
	
	while(1){
		switch(interface()){
			case 0:
				return 0; 
			case 1:
				topoPilha = setNovoProdPil(topoPilha, &id); 
				break; 
			case 2: 
				fimDaFila = setNovoProdFil(fimDaFila, &id);
				if(!inicioDaFila)
					inicioDaFila = fimDaFila; 
				break;
			case 3:
				mostrarTodosProds(topoPilha, inicioDaFila);
				break;
			default:
				printf("Opção inválida!\n");
				enter();
		}
	}
}

