#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

int embaralha(int cartas[7], int qual, int ultC, int ultZ) {
    int alea=rand()%4 + 2;
    while(alea){
        if(qual==1)
            for(int i=0; i<ultC; i++){
                int prov=0, ind=0;
                prov=cartas[i]; 
                ind=rand()%(ultC+1);
                cartas[i] = cartas[ind]; 
                cartas[ind] = prov; 
            }
        if(qual==2)
            for(int i=ultZ; i<6; i++){
                int prov=0, ind=0;
                prov=cartas[i]; 
                ind=rand()%(7-ultZ); 
                cartas[i] = cartas[ind]; 
                cartas[ind] = prov; 
            }
        alea--;
    }
    return cartas[7]; 
}

int main () {
    int cartasz[7], cartasc[7], validac[7], validaz[7], mostraZ=0, mostraC=0; 
    int ultC=6; 
    int ultZ=0, fim=0;
    srand(time(NULL)); 

    //Colocando valores de cartas aleatórios nas cartas de zeca e chico e valida como 1
    for(int i=0; i<7; i++){
        cartasz[i] = rand()%10 + 1; 
        validac[i] = 1; 
        validaz[i] = 1; 
        cartasc[i] = rand()%10 + 1; 
    }

    //Desenhar as cartas de zeca e chico (viradas de cabeça pra baixo)
    printf("Cartas Zeca: "); 
   for(int i=0; i<7; i++) 
        printf("[] ");
    printf("\n\n\n\n\n"); 
    printf("Cartas Chico: "); 
    for(int i=0; i<7; i++) 
        printf("[] "); 


    //Repetição principal
    do{
        
        printf("\nAperte ENTER para continuar...\n"); 
        getchar(); 
        system("clear");
        //Virando as cartas Zeca
        printf("Cartas Zeca: ");
        for(int i=0; i<7; i++){
            if(ultZ==i){
                printf("[%02d] ", cartasz[i]);
                mostraZ = cartasz[i];   
                continue; 
            }
            if(validaz[i]){
                printf("[] "); 
            }else{
                printf("X "); 
            }
        }
        printf("\n\n\n\n");
        //Virando as cartas Chico
        printf("Cartas Chico: ");
        for(int i=0; i<7; i++){
            if(ultC==i){
                printf("[%02d] ", cartasc[i]); 
                mostraC = cartasc[i];    
                continue; 
            }
            if(validac[i]){
                printf("[] "); 
            }else{
                printf("X "); 
            }
        }

        //Comparando quem venceu e fazendo as coisas 
        printf("\nZeca: %d vs Chico: %d", mostraZ, mostraC); 
        if(mostraZ>mostraC){
            printf("\nZeca Venceu a rodada!\n"); 
            validaz[ultZ]=0; 
            ultZ++;
            embaralha(cartasc, 1, ultC, ultZ); 
        }else{
            if(mostraZ==mostraC){
                printf("\nDeu empate!"); 
                validac[ultC]=0;
                validaz[ultZ]=0; 
                ultC--; 
                ultZ++;
            }else{
                printf("\nChico Venceu a rodada!\n");
                validac[ultC]=0; 
                ultC--; 
                embaralha(cartasz, 2, ultC, ultZ); 
            }
        }
        if(ultC<0 && ultZ>6){
            printf("O jogo acabou em empate!"); 
            break; 
        }

        if(ultC<0){
            printf("Chico ganhou o jogo!"); 
            break;
        } 
        if(ultZ>6){
            printf("Zeca ganhou o jogo!"); 
            break;
        }

    }while(1); 


    return 0;
}
