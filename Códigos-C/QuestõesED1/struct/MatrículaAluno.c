/*
    PROJETO SISTEMA ACADEMICO
FACA UM PROGRAMA QUE IMPLEMENTE DUAS STRUCTS:
	DISCENTE: NOME:S, MATRICULA:I, NOTAS:A, COEF.RENDIMENTO:F
	DISCIPLINAS: COD:I, NOME:S, CH:I, DISCENTES:A
OPÇÕES NA INTERFACE:
	1 - CADASTRAR DISCIPLINA
	2 - CADASTRAR ALUNO
	3 - MATRICULAR ALUNO
	4 - LANÇAR NOTAS
	5 - DIARIO DA DISCIPLINA
	6 - HISTORICO DO ALUNO
	7 - RANKING DE CR
REQUISITOS:
	MATRICULA(DISCENTE) E COD(DISCIPLINA) SÃO CAMPOS CHAVE.
	MATRICULA EM CADA DISCIPLINA DEVE SER UNICA.
	NOTA EM CADA DISCIPLINA DEVE SER UNICA.
	DIARIO DA DISCIPLINA DEVE IMPRIMIR TODOS OS ALUNOS 
		MATRICULADOS E SUAS RESPECTIVAS NOTAS
	HISTORICO DO ALUNO DEVE IMPRIMIR TODOS SUAS DISCIPLINAS 
		 SUAS RESPECTIVAS NOTAS
	RANKING DE CR, RELATORIO DE ALUNOS
		ORDENADO DE FORMA DECRESCENTE POR CR
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Defines:

#define STR " %[^\n]s"
#define INT " %d"
#define CHAR " %c"
#define FLOAT " %f"


//structs:

typedef struct{
    char nome[100];
    int mat, notas[100][2], qtdnot;
    float cof;
}Discente;

typedef struct{
    char nome[100];
    int cod, ch, alunos[40], qtdAl;
}Disciplina;


//signs:

//Evita de "letras" entrarem nos "int":
void ov();
//Escreve uma frase desejada e atribui um valor para um variável:
void input(char *inst, void *var, char *tipo);
//Interface:
int interface();
//Cadastra uma disciplina:
void cadastDiss(Disciplina *diss, int qtdDiss);
//Cadastra um aluno:
void cadastAl(Discente *aluno, int qtdAl);



//funcs:

void ov(){
    while(getchar()!='\n');
}

int interface(){
    int esc;
    printf("1.CADASTRAR DISCIPLINA\n");
    printf("2.CADASTRAR ALUNO\n");
    printf("-------------------------------\n");
    printf("0.Sair\n");
    scanf(" %d", &esc);
    ov();
    return esc;
}

void cadastDiss(Disciplina *diss, int qtdDiss){
    input("Digite o nome da disciplina:\n", diss[qtdDiss].nome, STR);
    input("Carga horária da disciplina:\n", &diss[qtdDiss].ch, INT);
    ov();
    diss[qtdDiss].cod = qtdDiss+1;
    diss[qtdDiss].qtdAl = 0;
}

void input(char *inst, void *var, char *tipo){
    printf("%s", inst);
    scanf(tipo, var);
}

void cadastAl(Discente *aluno, int qtdAl){

}

void repetir(void func){
    
}

int main(){
    Disciplina diss[100];
    Discente alunos[100];
    int qtdDiss=0, qtdAl=0;
    do{
        switch(interface()){
            case 0:
                return 0;

            case 1:
                char opo;
                while(opo=='s'){    
                    cadastDiss(diss, qtdDiss);
                    qtdDiss++;
                    printf("Deseja cadastrar mais um aluno?(s/n):\n");
                    scanf(" %c", &opo);
                    ov();
                }
                break;
            
            case 2:

            default: 
                printf("Opção inválida!\n");
        }
    }while(1);
    return 0;
}