/*
  Ta faltando no preenchimento normal: 
    -Parte 2 e 3 do problema;
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Definindo Aluno
typedef struct{
    char nome[70], nomeCurso[70];
    int numMat, notas[10], contNotas;
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
        //verificando se esse número de matrícula já existe:
        int existe=0;
        do{
            existe=0;
            scanf(" %d", &cadastro[qtdAl].numMat);
            for(int i=0; i<qtdAl; i++)
                if(cadastro[i].numMat==cadastro[qtdAl].numMat){
                    existe=1;
                    printf("Esse número de matrícula já está cadastrado!\nDigite novamente:\n");
                    break;
                }
        }while(existe);

        printf("Média de notas:\n");
        scanf(" %f", &cadastro[qtdAl].medNotas); 
        cadastro[qtdAl].contNotas=0;
        while(getchar()!='\n');
        system("clear");
        qtdAl++;
    }while(qtdAl<100);

    if(debug){
        qtdAl=10;
        //colocando números aleatórios não repetidos
        int colMat=0;
        while(1){
            int existeMat=0;
            sprintf(cadastro[colMat].nome, "Teste da Silva"); 
            cadastro[colMat].numMat=rand()%55 + 5;
            cadastro[colMat].medNotas= ((rand()%90) + (rand()%98 + 1)/100); //Isso aqui não ta funcionando do jeito que eu imaginei
            //verificando se já repetiram
            for(int i=0; i<colMat; i++)
                if(cadastro[i].numMat==cadastro[colMat].numMat){
                    existeMat=1; 
                    break;
                }

            if(!existeMat && colMat<10)
                colMat++;
            if(colMat==10)
                break;
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
        system("clear");
        //repetição para encontrar as informações dos alunos: 
        do{
            //Mostrando os números de matrícula para facilitar a busca
            printf("Nome dos alunos e seus Números de Matrícula:\n");
            for(int i=0; i<(qtdAl); i++){
                printf(" %-5s: [%02d]\n", cadastro[i].nome,cadastro[i].numMat);
            }

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
                if(!debug){
                    printf("Informações de \"%s\" número de matrícula: %d {\nNome do curso: %s\nMédia de notas: %.2f\n}", 
                        cadastro[encontrado].nome, 
                        cadastro[encontrado].numMat,
                        cadastro[encontrado].nomeCurso, 
                        cadastro[encontrado].medNotas);

                        printf("Notas lançadas: ");
                        for(int i=0; i<(cadastro[encontrado].contNotas); i++)
                            printf("| %02d |", cadastro[encontrado].notas[i]);
                        printf("\n");
                        
                        //Lançando novas notas:
                        printf("Deseja lançar Notas para o aluno \"%s\" (s/n)?:\n", cadastro[encontrado].nome);
                        scanf(" %c", &perg);
                        if(perg=='s'){
                            for(int i=cadastro[encontrado].contNotas; i<10;i++){
                                printf("Digite a nota(escreva um valor negativo para sair):\n");
                                scanf(" %d", &cadastro[encontrado].notas[i]);
                                if(cadastro[encontrado].notas[i]>=0)
                                    cadastro[encontrado].contNotas++;
                                else
                                    break;
                            }
                            //alertando
                            if(cadastro[encontrado].contNotas==10){
                                system("clear");
                                printf("\nTodas as notas para esse aluno foram lançadas!\n\n");
                            }                            
                        }
                }else{
                    printf("Informações de \"%s\" número de matrícula: %d {\nMédia de notas: %.2f\n}", 
                        cadastro[encontrado].nome, 
                        cadastro[encontrado].numMat, 
                        cadastro[encontrado].medNotas);
                }
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