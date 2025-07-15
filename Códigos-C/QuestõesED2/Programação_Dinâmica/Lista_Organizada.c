#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Produto em 'P'ilha
typedef struct ProdutoP{
	char nome[36];
	int id; 
	float valor;
	struct ProdutoP *prox;
}ProdutoP;


//signs
void ov();
void mostraProduto(ProdutoP *lst);

//aguarda a entrada de um ENTER no teclado
void enter(){
	setbuf(stdin,NULL);
	ov();
}

//"Limpa" o "buffer"
void ov(){
	while(getchar()!='\n');
}

//cria uma linha
void linha(char sim, int qtd){
	for(int i=0; i<qtd; i++)
		printf("%c", sim);
	printf("\n");
}

//Não permite a leitura de uma variável de tipo diferente da especificada
void lersomente(char *msg, char *tipo, void *var){
	int erro=0;
	printf("%s", msg);
	do{
		if(!scanf(tipo, var))
			erro=1;
		else
			erro=0;
	}while(erro);
}

//interface comum
int interface(){
	int escolha;
	printf("1.Adicionar produto\n");
	printf("2.Listar produtos\n");
	printf("3.Excluir produto\n");
	linha('-', 36); 
	printf("0.Sair\n");
	printf(": ");
	lersomente("", " %d", &escolha);
	return escolha;
}

//mensagem de confirmação
void mensagem_confirma(){
	printf("operação realizada com sucesso!\n");
	enter();
}

//Cria um novo produto e põe  ele organizado por tamanho do ID
ProdutoP *o_setProdutoP(ProdutoP *lst){
	ProdutoP *newP = malloc(sizeof(ProdutoP)); 
	lersomente("Digite o nome do produto: \n", " %[^\n]35s", newP->nome);
	ov();
	lersomente("Digite o preço do produto: \n", " %f", &newP->valor);
	ov();
	newP->id = rand()%10000; 
	newP->prox = NULL;
	
	if(!lst){
		mensagem_confirma();
		return newP;
	}
	
	//ordenando por id
	if(lst->id>newP->id){
		newP->prox = lst;
		mensagem_confirma();
		return newP;
	}
	
	ProdutoP *pAlvo = lst;
	while(1){
		if(!pAlvo->prox){
			pAlvo->prox = newP;
			mensagem_confirma();
			return lst;
		}	
		
		if(pAlvo->prox->id > newP->id){
			newP->prox = pAlvo->prox;
			pAlvo->prox = newP;
			mensagem_confirma();
			return lst;
		}
		pAlvo = pAlvo->prox;
	}
}

//Deleta um produto determinado pelo ID
ProdutoP *deletaP(ProdutoP *lst){
	int alvo;
	mostraProduto(lst);
	linha('!', 45);
	lersomente("Digite qual ID de produto que deseja apagar:\n", " %d", &alvo); 
	
	//verifica se o primeiro é o alvo
	if(lst->id==alvo){
		ProdutoP *aux = lst->prox; 
		free(lst); 
		mensagem_confirma();
		return aux;
	}
	
	ProdutoP *pAlvo=lst; 
	
	while(pAlvo){
		if(pAlvo->prox->id==alvo){
			pAlvo->prox = pAlvo->prox->prox;
			free(pAlvo->prox);
			mensagem_confirma();
			return lst;
		}
	}
	printf("Valor de ID não encontrado!\n");
	enter();
	return lst;
}

//mostra todos os produtos cadastrados
void mostraProduto(ProdutoP *lst){
	if(!lst)
		printf("{NULL}\n");
	
	while(lst){
		printf("Nome: %s\nID: %d\nValor: %.2f\n", lst->nome, lst->id, lst->valor);
		linha('#', 45);
		lst = lst->prox;
	}
}

int main(){
	//'Lista' em 'P'ilha
	srand(time(NULL));
	ProdutoP *lstP = NULL; 
	
	//interface
	while(1)
		switch(interface()){
			case 0:
				return 0;
			case 1:
				lstP = o_setProdutoP(lstP);
				break;
			case 2:
				mostraProduto(lstP);
				enter();
				break;
			case 3:
				lstP = deletaP(lstP);
				break;
			default: 
				printf("Opção inválida...\n");
				enter();
		}
}