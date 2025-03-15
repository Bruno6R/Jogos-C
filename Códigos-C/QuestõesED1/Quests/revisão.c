#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int n,x,y; 
    srand(time(NULL));
    printf("Digite o tamanho do vetor: "); 
    scanf(" %d", &n); 
    printf("Digite o intervalo dos números que irão preencher o vetor(x a y):\n"); 
    //verificando a validade de x e y
    int erro=0; 
    do{
        erro=0;
        scanf(" %d %d", &x,&y); 
        if((y-x+1)<n){
            printf("\nOs valores são inválidos!, digite novamente:\n"); 
            erro=1;
        }
    }while(erro);

    //Preenchendo com números aleatórios e não repetitivos
    int col=0, vetor[n]; 
    while(1){
        erro=0;
        vetor[col]=rand()%(y-x+1) + x; 
        for(int j=0; j<col; j++)
            if(vetor[col]==vetor[j]) 
                erro=1;
        if(!erro)
            col++; 
        if(col==n)
            break;
    }
    
    //Mostrando o vetor
    for(int i=0; i<n; i++)
        printf("[%02d] ", vetor[i]); 
    printf("\n");

    //Problema 1
    int sub[n-1]; 
    //Fazendo a subtração
    for(int i=0; i<(n-1); i++){
        if(vetor[i]>vetor[i+1]) 
            sub[i]=(vetor[i]-vetor[i+1]);
        else 
            sub[i]=(vetor[i+1]-vetor[i]); 
        //printf("[%02d] ",sub[i]);
    }

    //descobrindo qual é o maior e lidando com o empate
    int maior=sub[0], ima=0;
    for(int i=0; i<(n-1); i++){
        if(sub[i]>maior || (sub[i]==maior && (vetor[i]+vetor[i+1])>(vetor[ima]+vetor[ima+i]))){
            maior=sub[i]; 
            ima=i;
        }
    }

    //mostrando o resultado 
    printf("\nA maior subtração consecutiva de pares é: [%02d]-[%02d] = %d", vetor[ima], vetor[ima+1], maior); 

    //PROBLEMA 2
    int cont=1, contM=1, soma=0, somaM=0;
    ima=0;
    //descobrindo a maior sequência e lidando com o empate
    for(int i=0; i<(n-1); i++){
        if(vetor[i]<vetor[i+1]){
            cont++;
            soma+=vetor[i];
            for(int j=(i+1); j<n; j++){
                if(vetor[j]<vetor[j+1]){
                    cont++;
                    soma+=vetor[j];
                    //printf("\ni=%d, cont=%d, contM=%d\n", i, cont, contM);
                }else{ 
                    soma+=vetor[j];
                    break;
                }
            }
            if(cont>contM || (cont==contM && soma>somaM)){
                contM=cont; 
                ima=i; 
                somaM=soma;
            }
            soma=0;
            cont=1;
        }
    } 

    //mostrando o resultado 
    printf("\nMaior sequência: ", contM,ima); 
    for(int i=ima; i<(ima+contM); i++)
        printf("[%02d] ", vetor[i]);
    
    return 0; 
}