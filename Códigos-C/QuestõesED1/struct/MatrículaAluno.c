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

//Retorna a posição de onde se encontra a nota daquela matéria ou -1 se não for encontrado:
int desclocal(Discente alunos, int cod);
//lança as notas:
int lancarNotas(Disciplina diss, Discente *alunos);
//busca se esse aluno já foi cadastrado na disciplina:
int buscAl(Disciplina diss, int mat);
//Desenha uma linha:
void linha(char dese, int qtdVz);
//espera o input da tecla ENTER:
void esp();
//Mostrar disciplinas:
void mostDiss(Disciplina *diss, int qtdDiss);
//Mostra os Alunos:
void mostAl(Discente *alunos, int qtdAl);
//pergunta se deve continuar uma operação:
char continuar();
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
//Busca um aluno e retorna o número de matrícula dele:
int busca(Discente *alunos, int qtdAl);
//Matrícula um aluno em uma disciplina e retorna 1 se o aluno já estiver cadastrado:
int matAl(Discente *alunos, Disciplina *diss, int qtdDiss);
//busca o código de uma disciplina e retorna o local dela:
int buscaDiss(Disciplina *diss, int qtdAl, int alvo);
//Verifica se existem alunos e disciplinas e retorna 1 se !qtdAl, 2 se !qtdDiss e 0 se tiver tudo certo:
int ver(int qtdAl, int qtdDiss);


//funcs:

int desclocal(Discente alunos, int cod){
    system("clear");
    for(int i=0; i<alunos.qtdnot; i++){
        if(alunos.notas[i][0]==cod)
            return i;
    }
    return -1;
}

int lancarNotas(Disciplina diss, Discente *alunos){
    system("clear");

    printf("Alunos matrículados nessa disciplina:\n\n");
    for(int i=0; i<diss.qtdAl; i++){
        printf("Nome: %s\nNúmero de matrícula: %d\n", alunos[diss.alunos[i]-1].nome, diss.alunos[i]);
        linha('.', 50);
    }
    printf("\n");
 
    int op;
    input("Digite o número de matrícula do aluno que deseja lançar nota:\n", &op, INT);
    ov();
    if(!op)
        return 0;
    if(!buscAl(diss, op))
        printf("Esse código não existe!\n");
    else{
        op--;
        int on = desclocal(alunos[op], diss.cod);
        if(on<0){
            printf("\nERRO!\n");
            return 0;
        }
        printf("Digite a nota do aluno %s:\n", alunos[op].nome);
        scanf(" %d", &op);
        alunos[op].notas[on][1] = op;
    }
    return 0;
}

int buscAl(Disciplina diss, int mat){
    int inic=0, fim = diss.qtdAl; 
    do{
        int mei = (fim-inic)/2 + inic;
        if(mat == diss.alunos[mei])
            return 1;
        inic = diss.alunos[mei]<mat? mei+1 : inic;
        fim = diss.alunos[mei]>mat? mei-1 : fim;
    }while(fim>=inic);
    return 0;
}

void linha(char dese, int qtdVz){
    for(int i=0; i<qtdVz; i++){
        printf("%c", dese);
    }
    printf("\n");
}

void esp(){
    setbuf(stdin, NULL);
    printf("Aperte ENTER para continuar...\n");
    getchar();
}

int ver(int qtdAl, int qtdDiss){
    
    if(!qtdAl){
   	 printf("Não existem alunos cadastrados!\n");
   	 esp();
   	 return 1;
    }
    if(!qtdDiss){
   	 printf("Não existem Disciplinas cadastradas!\n");
   	 esp();
   	 return 2;
    }
    return 0;
}

int buscaDiss(Disciplina *diss, int qtdAl, int alvo){
    int fim=qtdAl-1, inic = 0, cod=-1;
    do{
   	    int mei = (fim-inic)/2 + inic;
   	    if(alvo == diss[mei].cod){
   		    cod = mei;
   		    return cod;
        }
   	    fim = alvo<diss[mei].cod? mei-1 : fim;
   	    inic = alvo>diss[mei].cod? mei+1 : inic; 
    }while(fim>=inic);
    return cod;
}

int matAl(Discente *alunos, Disciplina *diss, int qtdDiss){
    system("clear");
    mostDiss(diss, qtdDiss);
    int local;
    input("Em qual disciplina quer cadastrar esse aluno?(escreva o código dessa disciplina):\n", &local, INT);
    local = buscaDiss(diss, qtdDiss, local);
    if(local<0)
   	    printf("Matéria não encontrada!\n");
    else{
        if(!buscAl(diss[local], alunos->mat)){
   	        diss[local].alunos[diss[local].qtdAl++] = alunos->mat;
            alunos->notas[alunos->qtdnot][0] = diss[local].cod;
            alunos->qtdnot+=1;
   	        printf("Aluno %s cadastrado em %s\n", alunos->nome, diss[local].nome);
            return 0;
        }
        return 1;
    }
    return 0;
}

int busca(Discente *alunos, int qtdAl){
    int alvo;
    
    printf("Qual é o número de matrícula do aluno que deseja cadastrar?:\n");
    scanf(" %d", &alvo);
    ov();
    int fim=qtdAl-1, inic = 0, cod=-1;
    do{
   	    int mei = (fim-inic)/2 + inic;
   	    if(alvo == alunos[mei].mat){
   	        cod = mei;
   	    	return cod;
        }
   	    fim = alvo<alunos[mei].mat? mei-1 : fim;
   	    inic = alvo>alunos[mei].mat? mei+1 : inic;
    }while(fim>=inic);
    return cod;
}

void mostDiss(Disciplina *diss, int qtdDiss){
    for(int i=0; i<qtdDiss; i++){
   	printf("Disciplina: %s\nCódigo de %s: %d\nCH: %d\n",
   		diss[i].nome,
   		diss[i].nome,
   		diss[i].cod,
   		diss[i].ch);
    linha('-', 20);
    }
    
}

void mostAl(Discente *alunos, int qtdAl){
    for(int i=0; i<qtdAl; i++){
   	    printf("Aluno: %s\nnúmero de matrícula de %s: %d\n",
   	        alunos[i].nome,
   		    alunos[i].nome,
   		    alunos[i].mat);
        linha('/', 20);
    }
    
}

char continuar(char *nome){
    char op;
    printf("Deseja continuar a %s?(s/n)\n", nome);
    scanf(" %c", &op);
    ov();
    return op;
}

void ov(){
	while(getchar()!='\n');
}

int interface(){
    system("clear");
	int esc=-1;
	printf("1.CADASTRAR DISCIPLINA\n");
	printf("2.CADASTRAR ALUNO\n");
	printf("3.MATRICULAR ALUNO\n");
    printf("4.LANÇAR NOTAS\n");
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
    input("Digite o nome do Aluno:\n", aluno[qtdAl].nome, STR);
    aluno[qtdAl].mat = qtdAl+1;
    aluno[qtdAl].qtdnot = 0;
}


int main(){
	Disciplina diss[100];
	Discente alunos[100];
	int qtdDiss=0, qtdAl=0, codAl;
	do{
    	switch(interface()){
        	case 0:
            	return 0;

        	case 1:
   			    do{
   				    cadastDiss(diss, qtdDiss);
   				    qtdDiss++;
                    printf("O código da disciplina é: %d\n", diss[qtdDiss-1].cod);
   			    }while(continuar("Cadastrar Disciplina") == 's');
            	break;

        	case 2:
   			    do{
   				    cadastAl(alunos, qtdAl);
   				    printf("O número de matrícula de %s é: %d\n", alunos[qtdAl].nome, alunos[qtdAl].mat);
   				    qtdAl++;
   			    }while(continuar("Cadastrar Aluno") == 's');
   			    break;

   		    case 3:
                if(ver(qtdAl, qtdDiss))
                    break;
                do{
                    system("clear");
                    mostAl(alunos, qtdAl);
                    codAl = busca(alunos, qtdAl);
                    if(codAl>=0){
                        if(matAl(&alunos[codAl], diss, qtdDiss))
                            printf("Aluno já cadastrado nessa disciplina!\n");
                    }else
                        printf("Número de matrícula não encontrado!\n");
                }while(continuar("Matricular Aluno") == 's');
                break;

        case 4:
            do{
                system("clear");
                if(ver(qtdAl, qtdDiss))
                    break;
                printf("Disciplinas:\n");
                mostDiss(diss, qtdDiss);
                int op;
                input("Digite o código da disciplina que deseja lançar notas:\n", &op, INT);
                ov();
                op = buscaDiss(diss, qtdDiss, op);
                if(op>=0 && diss[op].qtdAl)
                    lancarNotas(diss[op], alunos);
                else{
                    printf("Disciplina não encontrada! ou não existem alunos nessa disciplina!\n");
                    esp();
                }
            }while(continuar("Lançar notas")=='s');
            break;
            
        	default:
            	printf("Opção inválida!\n");
                esp();
    	}
	}while(1);
	return 0;
}