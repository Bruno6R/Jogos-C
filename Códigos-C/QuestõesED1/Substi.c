#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define MAX_STR 21

int main(){
    char string[MAX_STR], c1, c2; 

    //Ler os dados 
    printf("Digite um texto de até 20 caracteres:\n");
    scanf(" %20[^\n]s", string); 
    while(getchar()!='\n');
    printf("Agora um caractere indesejado:\n"); 
    scanf(" %c", &c1); 
    while(getchar()!='\n');
    printf("E por fim, um outro caractere para substituir o anterior:\n"); 
    scanf(" %c", &c2); 

    //Trocando as coisas de lugar 
    for (short int i=0; i<MAX_STR; i++) 
        if(string[i]==c1) 
            string[i] = c2; 

    //Mostrando resultado 
    printf("Agora a frase é: %s", string); 
    return 0;
}