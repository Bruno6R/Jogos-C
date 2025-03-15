#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//structs:
typedef struct{
	int codBar, qtd;
	float prec;
	char desc[100];
}Produto;


//signs: 

//Vende um produto:
void vender(int cod, Produto *prod);
//Busca o código de um produto, 0 significa que não tem e 1 significa que existe:
int buscaProd(Produto *prod, int quantos, int cod);
//Gera um código de barras aleatório(de 0 a 255):
void gerarCodBar(Produto *prod, int quantos);
//Organiza os produto do menor codBar para o maior:
void organizar(int quantos, Produto *prod);
//Cadastra um produto:
void cadastrarProd(Produto *prod, int quantos);
//Mostra todos os produtos cadastrados:
void mostrarProdutos(Produto *prod, int quantos);
//espera a tecla ENTER:
void esp();
//limpa a tela:
void lim();
//Sem necessidade de descrever essa:
int interface();



//funcs:

void esp(){
	setbuf(stdin, NULL);
	printf("Aperte ENTER para continuar...");
	getchar();

}

void lim(){
	system("clear");
}

int buscaProd(Produto *prod, int quantos, int cod){
	int achei=0;
	int inic=0, fim=quantos-1;
	do{
		int mei=((fim-inic)/2)+inic;
		if(cod==prod[mei].codBar){
			achei=1;
			return achei;
		}
		inic = cod>prod[mei].codBar? mei+1 : inic;
		fim = cod<prod[mei].codBar? mei-1 : fim;
	}while(fim>=inic);
	return achei;
}

void cadastrarProd(Produto *prod, int quantos){
	printf("Digite o nome do produto:\n");
	scanf(" %99[^\n]s", prod[quantos].desc);
	while(getchar()!='\n');
	printf("Digite o preço do %s\n", prod[quantos].desc);
	scanf(" %f", &prod[quantos].prec);
	while(getchar()!='\n');
	printf("Quantos tem no estoque?:\n");
	scanf(" %d", &prod[quantos].qtd);
	while(getchar()!='\n');
	gerarCodBar(prod, quantos);
}

void mostrarProdutos(Produto *prod, int quantos){
	printf("\n\n-----------------------------\n\n");
    for(int i=0; i<quantos; i++){
   	 printf("Nome: %s\nCódigo de Barras: %d\nPreço: %.2f\nQuantidade no estoque: %d\n",
   			 prod[i].desc,
   			 prod[i].codBar,
   			 prod[i].prec,
   			 prod[i].qtd);
   	 printf("\n-----------------------------\n");
    }

}

void vender(int cod, Produto *prod){
	//verificando o codBar:
	int comp;
	char resp;

	//Fazendo a venda:
	//Verificando quantos compra:
	do{
		printf("Quantos \"%s\" deseja comprar?(existem %d no estoque!):\n", prod->desc, prod->qtd);
		scanf(" %d", &comp);
		if(comp>prod->qtd)
			printf("O valor é maior do que tem no estoque!\nCaso não queira comprar basta digitar um valor negativo:\n");
		else
			break;
	}while(comp>0);

	if(comp>=0){
		if(comp==0)
			printf("Porque comprar 0 %s? ta bom né\n", prod->desc);
		printf("Vai ficar R$ %.2f comprar %d %s!\nVai querer continuar?(s/n):\n", comp*prod->prec, comp, prod->desc);
		scanf(" %c", &resp);
		while(getchar()!='\n');
		if(resp=='s'){
			prod->qtd -= comp;
		}
	}
	
}

void organizar(int quantos, Produto *prod){
    for(int i=1; i<quantos; i++){
   	 Produto guarda = prod[i];
   	 for(int j=(i-1); j>(-1); j--){
   		 if(guarda.codBar<prod[j].codBar){
   			 prod[j+1] = prod[j];
   		 }else{
   			 prod[j+1]=guarda;
   			 break;    
   		 }
   		 if(j==0)
   			 prod[j]=guarda;
   	 }
    }
}

void gerarCodBar(Produto *prod, int quantos){
    int alvo;
   	 //procurando se esse codBar já foi gerado:
	do{
		alvo = rand()%256;
	}while(buscaProd(prod, quantos, alvo));
    prod[quantos].codBar = alvo;
}

int interface(){
	int op;
	lim();
	printf("1.Cadastrar produtos\n");
	printf("2.Ver produtos cadastrados\n");
	printf("3.Vender produtos\n");
	printf("4.Sair\n");
	printf("Escolha: ");
	scanf(" %d", &op);
	while(getchar()!='\n');
	return op;
}

int main(){
	srand(time(NULL));
	Produto p[100];
	int quantos=0;
	char perg;
	//cadastrando e organizando, por codBar, os produtos:
	//interface:
	do{
		switch (interface()){
			case 1:
				cadastrarProd(p, quantos++);
				printf("O código de barra do %s é %d\n\n", p[quantos-1].desc, p[quantos-1].codBar);
				organizar(quantos, p);
				esp();
				break;
			case 2: 
				if(quantos>0){
					mostrarProdutos(p, quantos);
					esp();
				}else{ 
					printf("Não existem produtos cadastrados!\n");
					esp();
				}
				break;
			case 3:
				if(quantos>0){
					int cod;
					printf("PRODUTOS:\n");
					mostrarProdutos(p, quantos);
					printf("Informe o código de barra do produto:\n");
					scanf(" %d", &cod);
					if(!buscaProd(p, quantos, cod)){
						printf("Esse produto não existe!\n");
						esp();
					}else 
						vender(cod, p);
				}else
					printf("Não existem produtos para vender!\n");
					break;
			case 4: 
				return 0;
			default: 
				printf("Opção inválida!\n");
		}
	}while(1);
	return 0;
}


