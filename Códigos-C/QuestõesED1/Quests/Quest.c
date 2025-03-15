#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <string.h> 

void lernomes (int val){
    if(val==1){
        char nome1[20], nome2[20], nome3[20]; 
        printf("Digite os três nomes:\n"); 
        //Lendo os nomes
        scanf(" %19[^\n]s", nome1); 
        while(getchar()!='\n'); 
        scanf(" %19[^\n]s", nome2);
        while(getchar()!='\n');
        scanf(" %19[^\n]s", nome3);
        while(getchar()!='\n');

        //Printando os nomes
        printf("%s\n%s\n%s", nome1, nome2, nome3);
    }
}

void matricula(int val) {
    if (val==21){
        int ano, dig=0; 
        char sano[5];
        printf("Digite o seu ano de matrícula:\n"); 
        scanf(" %d", &ano); 
        sprintf(sano, "%d", ano);        
        printf("Ano da matrícula em string é: %s\n", sano); 
    }
}

void bin(int val) {
    if(val==22){
        char bina[40];
        int valido=1, bi[40], tam, resul=0, count=0;
        printf("Digite o número em binário:\n"); 
        scanf(" %39[^\n]s", bina); 
        tam=strlen(bina); 
        //Vendo se o número digitado é binário
        for(int i=(tam-1); i>=0; i--){
            int pow=2;
            if(bina[i]>'1' || bina[i]<'0'){
                valido=0;
                break;
            }

            bi[i]=(bina[i]-'0'); 
            if(bi[i]==1){
                if(count==0)
                    resul+=1;
                if(count==1)
                    resul+=2;
                if(count>1){
                    for(int j=1; j<count; j++)
                        pow=pow*2;
                    resul+=pow;
                }
            }
            count++;
        }
        //Mostrando resultados
        if(!valido){
            printf("O número %s não é binário!\n", bina); 
        }else{
            printf("O número binário %s corresponde a: %d", bina, resul); 
        }
    }
}

void romano(int qual){
    if (qual==23){
        char leitura[25], letrasValidas[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int resultado=0;
        while(1){
            int sair=0;
            printf("Digite o número decimal em número romano:\n"); 
            scanf(" %24[^\n]s", leitura); 
            //Comando para sair acabar a leitura
            if(!(strcmp(leitura, "exit")))
                break;
            //Vendo se as letras são válidas e armazenando qual letra esta em cada posição
            int max=strlen(leitura); 
            int valor[max];
            for(int i=0; i<max; i++){
                int valido=0;
                for(int j=0; j<7; j++){
                    if(leitura[i]==letrasValidas[j]){
                        valor[i]=j;
                        valido=1;
                        break;
                    }
                }
                if(!valido){
                    printf("O que foi digitado não é um número romano!\n");
                    sair=1;
                    break;
                }
            }
            //Evitando de fazer todos os calculos se for invalido
            if(sair)
                continue;
            //Colocando os valores
            for(int i=0; i<max; i++){
                switch (valor[i]){
                    case 0: 
                        valor[i]=1;
                        break; 
                    case 1: 
                        valor[i]=5;
                        break;
                    case 2: 
                        valor[i]=10;
                        break; 
                    case 3: 
                        valor[i]=50; 
                        break; 
                    case 4: 
                        valor[i]=100; 
                        break; 
                    case 5: 
                        valor[i]=500; 
                        break;
                    case 6: 
                        valor[i]=1000; 
                        break; 
                }
            }
            //Somando os valores corretamente
            for(int i=0; i<max; i++){
                if((i+1)<max){
                    if(valor[i]>valor[i+1])
                        resultado+=valor[i]; 

                    if(valor[i]<valor[i+1]){
                        resultado+=(valor[i+1]-valor[i]);
                        if((i+1)<max)
                            i++;
                    }
                    if(valor[i]==valor[i+1])
                        resultado+=valor[i];
                }else{
                    resultado+=valor[i];
                }   

                printf("Resultado até agora: %d[%d]\n", resultado, i);
            }
            //Mostrando o resultado
            printf("O valor em decimal do número romano é: %d\n", resultado);
            resultado=0;
        }
    }
}

void frases(){
    
}

void vetorxy() {
    int x, y; 
    printf("Digite os valores de \"x\" e \"y\"(sendo eles maiores que 0): \n"); 
    int erro=1;
    //validação de x
    do{
        printf("Digite o valor de x:\n"); 
        scanf(" %d", &x);
        //while para evitar de characteres entrarem no buffer
        while(getchar()!='\n');
        erro = x<=0? 1 : 0; 
        if(erro)
            printf("X tem que ser maior que 0!, digite novamente:\n");
    }while(erro);
    //validação de y
    do{
        printf("Digite o valor de y:\n"); 
        scanf(" %d", &y); 
        //o while(getchar) também evita de letras de entrarem nas variaveis inteiras! basta iniciar erro como 1
        while(getchar()!='\n'); 
        erro = y<=0? 1 : 0; 
        if(erro)
            printf("Y tem que ser maior que 0!, digite novamente:\n");
    }while(erro);
    //vetores principais
    int ve1[x],  ve2[y]; 
    //Preenchendo os vetores com números aleatórios não repetidos
    int col=0; 
    //vetor x 
    while(1){
        erro=0;
        ve1[col]=rand()%(x+y+1);
        //for para verificar se existem números iguais no vetor
        for(int i=0; i<col; i++){
            if(ve1[col]==ve1[i]){
                erro=1;
                break;
            }
        }
        col = erro? col : (col+1);
        if(col==x)
            break;
    }
    //vetor y 
    col=0;
    while(1){
        erro=0;
        ve2[col]=rand()%(x+y+1); 
        for(int i=0; i<col; i++) 
            if(ve2[i]==ve2[col]){
                erro=1; 
                break; 
            }
        col = erro? col : (col+1);
        if(col==y)
            break; 

    }
    //Mostrando vetores
    printf("\nVetor x:\n"); 
    for(int i=0; i<x; i++)
        printf("[%d] ", ve1[i]);
    printf("\nVetor y:\n"); 
    for(int i=0; i<y; i++)
        printf("[%d] ", ve2[i]);

    //descobrindo números exclusivos do vetor x e os simaleres entre x e y
    int exX[x], igual; 
    int tam; 
    tam = x>y? y : x; 
    int sim[tam], cont=0; 
    col=0;

    for(int i=0; i<x; i++){
        igual=0;
        for(int j=0; j<y; j++)
            if(ve1[i]==ve2[j]){
                igual=1;
                sim[cont]=ve1[i];
                cont++;
                break; 
            }
        if(!igual){
            exX[col]=ve1[i]; 
            col++; 
        }
    }

    printf("\nValores exclusivos do vetor x:\n"); 
    for(int i=0; i<(col); i++)
        printf("[%d] ", exX[i]); 

    //exclusivos em y 
    int exY[y];
    col=0;
    for(int i=0; i<y; i++){
        igual=0;
        for(int j=0; j<cont; j++)
            if(ve2[i]==sim[j]){
                igual=1;
                break;
            }
        if(!igual){
            exY[col]=ve2[i];
            col++;
        }
    }
    printf("\nValores exclusivos do vetor y:\n"); 
    for(int i=0; i<(col); i++)
        printf("[%d] ", exY[i]); 
    printf("\nValores comuns nos dois:\n");
    for(int i=0; i<cont; i++)
        printf("[%d] ", sim[i]); 

}


int main () {
    //srand comentada até o codigo funcionar!!!
    //srand(time(NULL)); 
    int qual=4;
    //Ler 3 nomes e devolver esses tres nomes na ordem certa 
    //qual=1
    lernomes(qual);
    //Questões strings (21-46)
    //qual=21
    matricula(qual);
    //qual=22
    bin(qual);
    //qual=23
    romano(qual); 
    //qual=24
    if(qual==24)
        frases();
    //Questão 4
    /*
    Ler do usuário dois valores inteiros "x", "y" alimentando dois vetores de 
    tamanho "x" e "y" com números inteiros aleatórios, não repetitivos, sorteados
    no intervalo de 0 e x+y(inclusive)
    faça a impressão das seguintes informações: 
    a) Vetores x e y
    b) Todos os números exclusivos do vetor x
    c) Números exclusivos do vetor y
    d) Números comuns nos dois vetores 
    */ 
    if (qual==4)
        vetorxy(); 
    
    return 0;
}