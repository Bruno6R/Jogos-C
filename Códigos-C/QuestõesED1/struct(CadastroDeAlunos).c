/*Ta faltando nos números aleatórios: 
    -Fazer eles não se repetirem;
  Ta faltando no preenchimento normal: 
    -Não permitir números de matrículas identicos;
    -Parte 2 e 3 do problema;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Definindo Aluno
typedef struct{
    char nome[70], nomeCurso[70];
    int numMat; 
    float medNotas;
}Aluno;


int main() {
    srand(time(NULL));
    int debug=0;
    printf("É um código significativamente extenso, deseja usar valores aleatórios?(digite \"1\" para sim e \"0\" para não)\n");
    printf("(Caso os valores aleatórios forem habilitados estarão disponíveis para ver apenas o número de matrícula e a média de notas\nalém disso serão feitos apenas 10 cadastros):");
    scanf(" %d", &debug);
    system("clear");
    //1)Fazer o cadastro de estudandes
    Aluno cadastro[100];
    int qtdAl=0;
    //Lendo os dados:
    do{
        printf("Digite o nome(escreva \"exit\" para finalizar a leitura):\n");
        scanf(" %[^\n]s", cadastro[qtdAl].nome);
        //While para pegar os characteres extras:
        while(getchar()!='\n');
        //Condição de parada nome==exit
        if(!strcmp(cadastro[qtdAl].nome, "exit"))
            break;

        printf("Nome do curso:\n");
        scanf(" %[^\n]s", cadastro[qtdAl].nomeCurso);
        while(getchar()!='\n');
        printf("Número de matrícula:\n");
        scanf(" %d", &cadastro[qtdAl].numMat);
        printf("Média de notas:\n");
        scanf(" %f", &cadastro[qtdAl].medNotas); 

        qtdAl++;
    }while(qtdAl<100);

    if(debug){
        qtdAl=10;
        //colocando números aleatórios
        for(int i=0; i<10; i++){
            sprintf(cadastro[i].nome, "Teste da Silva"); 
            cadastro[i].numMat=rand()%55 + 5;
            cadastro[i].medNotas= (rand()%90) + (rand()%98 + 1)/100; 
        }
    }
    system("clear");
    printf("Mostrando os números de matrícula desorganizados:\n");
    for(int i=0; i<(qtdAl); i++){
        printf(" %-5s: [%02d]\n", cadastro[i].nome,cadastro[i].numMat);
    }
    

    //Organizando pelo número de matrícula com insertion sort:
    Aluno guarda;
    for(int i=1; i<(qtdAl); i++){
        guarda=cadastro[i]; 
        for(int j=(i-1); j>(-1); j--){
            if(guarda.numMat<=cadastro[j].numMat){
                cadastro[j+1]=cadastro[j]; 
            }else{
                cadastro[j+1]=guarda;
                break;
            }
            if(!j){
                cadastro[j]=guarda;
            }
        }
    }

    //Perguntando se tem algum para ser procurado 
    char perg;
    int resul, erro;
    printf("Existe algum aluno para ser procurado?(s/n):\n");
    do{
        erro=0;
        scanf(" %c", &perg);
        switch(perg){
            case 's': 
                resul=1;
                break;
            case 'n':
                resul=0;
                break;
            default: 
                printf("Opção inválida!\n");
                erro=1;
        }
    }while(erro);

    //Caso tenha um aluno, fazendo a busca binária:
    if(resul){
        resul=0;
        //repetição para repetir a ação caso não for encontrado: 
        do{
            int fim=(qtdAl-1), inic=0, alvo, encontrado=-1;
            printf("Qual é o número de matrícula a ser procurado?:\n");
            scanf(" %d", &alvo);        
            //Binary search: 
            do{
                int mei=(fim-inic)/2 + inic; 
                if(cadastro[mei].numMat>alvo)
                    fim=(mei-1); 
                else{
                    if(cadastro[mei].numMat==alvo){
                        encontrado=mei; 
                        break;
                    }
                    inic=(mei+1); 
                }
            }while(fim>=inic);

            //Mostrando os resultados ou pedindo para pesquisar de novo:
            if(encontrado>=0){
                if(!debug)
                    printf("Informações de \"%s\" número de matrícula: %d {\nNome do curso: %s\nMédia de notas: %.2f\n}", 
                        cadastro[encontrado].nome, 
                        cadastro[encontrado].numMat,
                        cadastro[encontrado].nomeCurso, 
                        cadastro[encontrado].medNotas);
                else 
                    printf("Informações de \"%s\" número de matrícula: %d {\nMédia de notas: %.2f\n}", 
                        cadastro[encontrado].nome, 
                        cadastro[encontrado].numMat, 
                        cadastro[encontrado].medNotas);
            }else
                printf("Número de matrícula não encontrado!\n");
            printf("Deseja procurar outro número de matrícula?(s/n):\n");
            do{
                erro=0;
                scanf(" %c", &perg);
                switch(perg){
                    case 's': 
                        resul=1;
                        break;
                    case 'n':
                        resul=0;
                        break;
                    default: 
                        printf("Opção inválida!\n");
                        erro=1;
                }
            }while(erro);
        }while(resul);
    }

    //Mostrando 
    /*
    printf("Mostrando os números de matrícula organizados:\n");
    for(int i=0; i<(qtdAl); i++){
        printf(" %-5s: [%02d]\n", cadastro[i].nome,cadastro[i].numMat);
    }
    */
    return 0;
}