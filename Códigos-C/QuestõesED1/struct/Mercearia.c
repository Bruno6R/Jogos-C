#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int codBar, qtd;
    float prec;
    char desc[100];
}Produto;

void cadastrarProd(Produto *prod){
    printf("Digite o nome do produto:\n");
    scanf(" %99[^\n]s", prod->desc);
    while(getchar()!='\n'); 
    printf("Digite o preço do %s\n", prod->desc);
    scanf(" %f", &prod->prec);
    printf("Quantos tem no estoque?:\n");
    scanf(" %d", &prod->qtd);
}

void mostrarProdutos(Produto prod){
    printf("\n\n-----------------------------\n");
    printf("Nome: %s\nCódigo de Barras: %d\nPreço: %.2f\nQuantidade no estoque: %d\n",
            prod.desc,
            prod.codBar,
            prod.prec,
            prod.qtd);
    printf("\n-----------------------------\n");

}

int vender(int cod, Produto *prod){
    //verificando o codBar:
    int achei=0, comp;
    char resp;
    if(cod==prod->codBar){
        achei=1;
        //Fazendo a venda:
        //Verificando quantos compra:
        do{
            printf("Quantos %s deseja comprar?:\n", prod->desc);
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
    return achei;
}

int main(){
    srand(time(NULL));
    Produto p[100];
    int quantos=0;
    char perg;
    //cadastrando e organizando, por codBar, os produtos:
    do{

        cadastrarProd(&p[quantos]);

        //Insertion sort (É melhor ir pro bubble sort):
        for(int i=1; i<quantos; i++){
            Produto guarda=p[i]; 
            for(int j=(i-1); j>(-1); j--){
                if(guarda.codBar<p[j].codBar){
                    p[j+1]=p[j];
                }else{
                    p[j+1]=guarda;
                    break;
                }
                if(j==0)
                    p[j]=guarda;
            }
        }

        //Gerando um código de barras aleatório e único:
        int alvo, encont;
        do{
            int fim=(quantos-1), inic=0;
            encont=0;

            alvo = rand()%256;
            //procurando se esse codBar já foi gerado:
            while(quantos>0){
                int mei=((fim-inic)/2 + inic);
                if(p[mei].codBar>=alvo){
                    if(p[mei].codBar==alvo){
                        encont=1;
                        break;
                    }
                    fim = mei - 1; 
                }else{
                    inic = mei + 1;
                }
                if(fim<inic)
                    break;
            }
        }while(encont);

        p[quantos].codBar = alvo;
        
        printf("Pronto!\n%s tem o código de barra igual a %d\n\n", p[quantos].desc, p[quantos].codBar);

        printf("Tem outro produto para cadastrar?(Digite \"s\" para sim e \"n\" para não):\n");
        scanf(" %c", &perg);
        while(getchar()!='\n'); 
        quantos++;
    }while(perg=='s' && quantos<100);

    do{
        printf("Deseja ver os produtos cadastrados?(s/n):\n");
        scanf(" %c", &perg);
        while(getchar()!='\n'); 
        if(perg=='s')
            for(int i=0; i<quantos; i++)
                mostrarProdutos(p[i]);   
            
        
        printf("Quer vender algum?(s/n):\n");
        scanf(" %c", &perg);
        while(getchar()!='\n'); 
        if(perg=='s'){
            int cod;
            printf("Qual produto deseja vender?(Digite o código de barras dele):\n");
            scanf(" %d", &cod);
            int achei=0;
            //Quando eu aprender a mandar um vetor inteiro para uma função eu uso uma busca binária aqui:
            for(int i=0; i<quantos; i++){
                achei = vender(cod, &p[i]);
                if(achei)
                    break;
                if(achei==0 && i==(quantos-1))
                    break;
            }
            if(!achei)  
                printf("Produto não encontrado!\n");
        }
    }while(1);  
    return 0; 
}