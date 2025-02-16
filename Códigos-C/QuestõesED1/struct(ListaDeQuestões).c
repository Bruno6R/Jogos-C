#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "datetime.h"

typedef struct{
    char arqui[20], modelCpu[25], dedGpu[4], modelGpu[30];
    int qtdNul, ram, memo;
    float velClock;
}computador;

#define tam 35

void Quest_1() {
    computador cad[tam]; 
    int qtd=0;
    Datetime d=dt_now();

    //Informando a data e a mensagem de bem vindo: 
    if(d.hour>=12 && d.hour<19)
        printf("Boa tarde!\n");
    if(d.hour>=19 && d.hour<24)
        printf("Boa noite!\n");
    if(d.hour>=00 && d.hour<12)
        printf("Bom dia!\n");
    
    //Lendo as informações do computador:
    printf("Insira os dados dos computadores:\n"); 
    for(int i=0; i<tam; i++){
        printf("Quantidade de núcleos:\n");
        scanf(" %d", &cad[qtd].qtdNul);
        if(cad[qtd].qtdNul<0)
            break;
        while(getchar()!='\n');
        printf("Quantos GHz?:\n");
        scanf(" %f", &cad[qtd].velClock);
        while(getchar()!='\n');
        printf("Quanto de memória RAM?:\n");
        scanf(" %d", &cad[qtd].ram); 
        while(getchar()!='\n');
        printf("Qual é a capacidade de armazenamento?:\n");
        scanf(" %d", &cad[qtd].memo);
        while(getchar()!='\n');
        printf("Qual é o tipo de arquitetura?:\n");
        scanf(" %[^\n]19s", cad[qtd].arqui);
        printf("Qual é modelo da CPU?:\n");
        scanf(" %[^\n]24s", cad[qtd].modelCpu);
        printf("Ela tem placa de vídeo dedicada?(s/n):\n");
        scanf(" %[^\n]3s", cad[qtd].dedGpu);
        printf("Qual é o modelo da GPU?:\n");
        scanf(" %[^\n]29s", cad[qtd].modelGpu);
        system("clear");
        printf("Cadastro realizado!\nPróximo:\n");
        qtd++;
    } 
    system("clear");
    //Imprimindo os resultados
    for(int i=0; i<qtd; i++){
        printf("Computador %d:\n", i+1);
        int j=0; 
 
    }
}

int main() {
    //Ainda incopleto...
    Quest_1();
    return 0;
}