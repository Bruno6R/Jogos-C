#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h>


int main (){
    char mat[10][5], vet[100]; 
    short int n; 

    //Alimentando a matriz com valores aleatórios de 0 a 1000 
    srand(time(NULL)); 
    for(short int i=0; i<10; i++) 
        for(short int j=0; j<5; j++)
            mat[i][j] = rand()%1000; 

    //Lendo
    printf("Digite o tamanho desejado da coluna: \n"); 
    scanf(" %hd", &n); 

    //Mandando a matriz pro buffer
    for(short int i=0; i<10; i++)
        for(short int j=0; j<5; j++) 
            sprintf(vet, "%*d", n, mat[i][j]);

    printf("%s\n", vet); 
    return 0; 
}