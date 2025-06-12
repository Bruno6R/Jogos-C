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
	struct ProdutoFil* novo;  
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
		
		inicio = inicio->novo;
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

ProdutoFil* setNovoProdFil(ProdutoFil* fim, int *id){
	ProdutoFil* produto;
	produto = malloc(sizeof(ProdutoFil));
	printf("Digite o nome do produto: ");
	scanf(" %19[^\n]s", produto->nome);
	ov();
	input("Digite o valor do produto: ", FLOAT, &produto->valor);
	ov();
	input("Quantos tem?: ", INT, &produto->qtd); 
	ov();
	*id += 1;
	produto->id = *id;
	
	if(fim)
		fim->novo = produto;
		
	produto->novo = NULL;
	printf("Produto adicionado!\n");
	enter();
	return produto;
}

ProdutoPil* setNovoProdPil(ProdutoPil* antes, int *id){
	ProdutoPil* produto;
	produto = malloc(sizeof(ProdutoPil));
	printf("Digite o nome do produto: ");
	scanf(" %19[^\n]s", produto->nome);
	ov();
	input("Digite o valor do produto: ", FLOAT, &produto->valor);
	ov();
	input("Quantos tem?: ", INT, &produto->qtd); 
	ov();
	*id += 1;
	produto->id = *id;
	produto->anterior = antes;
	printf("Produto adicionado!\n");
	enter();
	return produto;
}

int main(){
	ProdutoPil* listaProdPil = NULL;
	
	ProdutoFil* inicioDaFila = NULL;
	ProdutoFil* fimDaFila = NULL;
	int id=0;
	while(1){
		switch(interface()){
			case 0:
				return 0; 
			case 1:
				listaProdPil = setNovoProdPil(listaProdPil, &id); 
				break; 
			case 2: 
				fimDaFila = setNovoProdFil(fimDaFila, &id);
				if(!inicioDaFila)
					inicioDaFila = fimDaFila; 
				break;
			case 3:
				printf("Pilha:\n");
				mostrarProdutosPil(listaProdPil);
				enter();
				printf("Fila:\n");
				mostrarProdutosFil(inicioDaFila);
				enter();
				break;
			default:
				printf("Opção inválida!");
				enter();
		}
	}
}

