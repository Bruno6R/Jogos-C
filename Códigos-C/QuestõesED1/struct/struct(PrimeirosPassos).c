#include <stdlib.h>
#include <stdio.h>
#include <string.h> 
#include <time.h>

typedef struct{
    char nome[70], cpf[15];
    float altura, peso;
    int idade;  
}Pessoa;

int main() {
    //Lendo os dados pessoais de uma pessoa
    Pessoa cadastro[100]; 
    int qtdcad=0; 

    //Repetição que lê os dados 
    do{
        printf("Digite o seu nome(escreva \"exit\" para sair):\n");
        scanf(" %[^\n]69s", cadastro[qtdcad].nome);
        //Linha para caso a pessoa digitar exit para "sair" do código
        if(!strcmp(cadastro[qtdcad].nome,"exit"))
            break;
        printf("Digite o seu cpf:\n");
        scanf(" %[^\n]s", cadastro[qtdcad].cpf);
        printf("Altura:\n");
        scanf(" %f", &cadastro[qtdcad].altura);
        printf("Peso:\n");
        scanf(" %f", &cadastro[qtdcad].peso);
        printf("Idade:\n");
        scanf(" %d", &cadastro[qtdcad].idade);
        printf("Cadastro feito!\nAperte ENTER para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");
        qtdcad++; 
    }while(qtdcad<100);

    //Mostrando os dados 
    char mensagem[100];
    for(int i=0; i<qtdcad; i++){
        printf("Nome: %s\nCPF: %s\nAltura: %.2f\nPeso: %.2f\nIdade: %d",
            cadastro[i].nome,
            cadastro[i].cpf,
            cadastro[i].altura,
            cadastro[i].peso, 
            cadastro[i].idade); 
        printf("\n\n\n\n\n\n\n\n");
    }
    return 0;
}