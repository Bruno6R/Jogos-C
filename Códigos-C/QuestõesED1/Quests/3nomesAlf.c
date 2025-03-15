#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int main() {
    //Ler os nomes
    char nom1[11], nom2[11], nom3[11]; 
    printf("Digite os três nomes:\n");
    scanf(" %10[^\n]s", nom1); 
    while(getchar()!='\n');
    scanf(" %10[^\n]s", nom2); 
    while(getchar()!='\n');
    scanf(" %10[^\n]s", nom3);
    while(getchar()!='\n');

    //Achando quem é maior e trocando de lugar 
    char aux[11]; 
    if(strcmp(nom1,nom2)>0) {
        strcpy(aux, nom2);
        strcpy(nom2,nom1);
        strcpy(nom1, aux);
    }
    if(strcmp(nom1,nom3)>0){
        strcpy(aux, nom3); 
        strcpy(nom3, nom1);
        strcpy(nom1,aux);
    }
    if(strcmp(nom2,nom3)>0){
        strcpy(aux,nom3);
        strcpy(nom3,nom2); 
        strcpy(nom2,aux); 
    }

    //Printando os nomes 
    printf("Os nomes em ordem alfabetica são: %s, %s, %s", nom1, nom2, nom3);
    return 0;
}