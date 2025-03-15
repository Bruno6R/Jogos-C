#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    //Fazendo binary search; 
    srand(time(NULL));
    int tam;
    printf("Digite o tamanho do vetor:\n");
    scanf(" %d", &tam);
    int vetor[tam]; 
    //Colocando valores aleatórios de 0 até 40 e mostrando o vetor desorganizado:
    printf("Vetor desorganizado:\n");
    for(int i=0; i<tam; i++){
        vetor[i]=rand()%41; 
        printf("[%d] ", vetor[i]);
    }
    //Organizar o vetor insertion sort:
    for(int i=1; i<tam; i++){
        int guarda=vetor[i];
        for(int j=(i-1); j>(-1); j--){
            if(guarda<vetor[j]){
                vetor[j+1]=vetor[j];
            }else{
                vetor[j+1]=guarda;
                break;
            }
            if(j==0)
                vetor[j]=guarda;
        }
    }

    //procurando com o binary search:
    int inic=0, fim=(tam-1), alvo, local=-1;
    printf("\nDigite o valor a ser procurado:\n");
    scanf(" %d", &alvo);

    do{
        int mei=((fim-inic)/2+inic); 

        if(vetor[mei]>alvo){
            fim=(mei-1); 
            continue;
        }else{
            //verificando se já achou
            if(vetor[mei]==alvo){
                local=mei;
                break;
            }
            inic=(mei+1); 
        }
    }while(fim>=inic);

    //Mostrando o vetor:
    printf("\nVetor Organizado e o valor procurado:\n");
    for(int i=0; i<tam; i++){
        if(local==i)
            printf("\33[33m[%d] \33[39m", vetor[i]);
        else
            printf("[%d] ", vetor[i]);
    }   
    char mens[100]; 
    int j;
    //O sprintf também retorna o último valor usado pela string, possibilitando colocar diversas mensagens em uma única string
    if(local>=0)
        sprintf(mens, "se encontra no índice %d", local);
    else 
        j = sprintf(mens, "não foi encontrado!");
    
    printf("\nO valor procurado era: \"%d\"\ne %s", alvo, mens);
    return 0;
}