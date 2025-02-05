#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL)); 
    int n, x, teste;


    //Lendo x e n
    printf("Digite o tamanho do vetor:\n");
    do{
        teste=1;
        scanf(" %d", &n);
        while(getchar()!='\n');
        teste = n<=0? 1 : 0; 
        if(teste)
            printf("O tamanho do vetor tem que ser maior que 0!\n");
    }while(teste);
  
    printf("Digite o valor máximo que pode ser sorteado(Inclusive):\n");
    do{
        teste=1;
        scanf(" %d", &x);
        while(getchar()!='\n');
        teste = x<=0? 1 : 0; 
        if(teste) 
            printf("O valor tem que ser maior que 0!\n");
    }while(x<=0);

    //Preenchendo o vetor com números aleatórios e mostrando ele
    printf("Vetor antes de organizado: \n");
    int vetor[n];
    for(int i=0; i<n; i++){
        vetor[i]=rand()%(x)+1; 
        printf("[%02d]: ", vetor[i]);
        for(int j=0; j<vetor[i]; j++)
            printf("-");
        printf("\n");
    }
    
    setbuf(stdin, NULL);
    system("sleep 0.7");
    system("clear");

    //Organizando: 
    printf("Organizando os valores:\n");
    int guarda, valorTrocado, trocando[n-1];
    for(int i=1; i<n; i++){
        guarda=vetor[i]; 
        
        //Mostrando os valores guardados e onde vão trocar
        for(int k=0; k<n; k++){
            printf("[%02d]: ", vetor[k]);
            //Colorindo
            if(k==i)
                printf("\33[33m");
            for(int l=0; l<vetor[k]; l++)
                printf("-");           
            if(k==i)
                printf("\33[39m   <--- Pegando esse valor aqui!");
            printf("\n");
        }

        setbuf(stdin, NULL);
        system("sleep 0.7");
        system("clear");

        int col=0;
        for(int j=(i-1); j>(-1); j--){
            if(guarda<=vetor[j]){
                vetor[j+1] = vetor[j];
                trocando[col++]=j;
            }else{
                vetor[j+1] = guarda;
                valorTrocado=(j+1); 
                break;
            }
            if(j==0){
                vetor[j]=guarda;
                valorTrocado=j;
            }
        }

        //Mostrando onde foram parar os valores
        for(int k=0; k<n; k++){
            printf("[%02d]: ", vetor[k]);
            //Colorindo
            if(k==valorTrocado)
                printf("\33[32m");
            for(int l=0; l<vetor[k]; l++)
                printf("-");           
            if(k==valorTrocado)
                printf("\33[39m   <--- E trocando com esse!");
            printf("\n");
        }
        setbuf(stdin, NULL);
        system("sleep 0.7");
        system("clear");
    }  


    /* Organização funcional
    //Organizando: 
    int guarda;
    for(int i=1; i<n; i++){
        guarda=vetor[i]; 
        for(int j=(i-1); j>(-1); j--){
            if(guarda<=vetor[j]){
                vetor[j+1] = vetor[j];
            }else{
                vetor[j+1] = guarda;
                break;
            }
            if(j==0)
                vetor[j]=guarda;
        }
    }  
    */

    printf("\n\nVetor organizado:\n\n");
    for(int i=0; i<n; i++){
        printf("[%02d]: ", vetor[i]);
        for(int j=0; j<vetor[i]; j++)
            printf("-");
        printf("\n");
    }

    return 0; 
}
