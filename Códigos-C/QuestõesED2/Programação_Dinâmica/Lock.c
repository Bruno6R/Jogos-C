#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Tools.h"

#define IMPRESSORA_S "Impressora"
#define TELA_S "Tela"
#define TAMNOME 4

int idProc=0;

typedef enum TipoRecurso{
	IMPRESSORA, 
	TELA,
	TAMREC
}TipoRecurso;

typedef struct Processo{
	int tempoExec;
	int pid;
	TipoRecurso recursoNecessario;
	char* nomeProc;
	struct Processo* next; 
	struct Processo* prev; 
}Processo;

typedef struct Recurso{
	TipoRecurso tipo; 
	int lock;
	Processo* processoUsando;
}Recurso;

void nomearProcesso(Processo* p){
	char* nomesProcess[(TAMNOME)] = {"Task.exe", "NotAVirus.exe", "SMB3.msi", "FunnyProcess.33"};	
	
	p->nomeProc=nomesProcess[rand()%TAMNOME];
}

Processo* new_processo(){
	Processo* new = malloc(sizeof(Processo)); 
	new->tempoExec = rand()%5 + 6;
	nomearProcesso(new);
	new->recursoNecessario = rand()%TAMREC;
	new->next=NULL;
	new->prev=NULL;
	new->pid=idProc++;
	return new;
}

void processoPush(Processo **pilha, Processo* p){
	if(!(*pilha)){
		*pilha=p;
		return;
	}
	
	p->next = *pilha; 
	(*pilha)->prev=p;
	*pilha=p;
}

void showProcess(Processo* p){
	char* tipo;
	if(p->recursoNecessario == IMPRESSORA)
		tipo = IMPRESSORA_S; 
	if(p->recursoNecessario == TELA) 
		tipo = TELA_S;	

	printf("Nome do processo: %s\nPID: %d\nTempo de execução: %d\nTipo de recurso: %s\n",
	p->nomeProc, p->pid, p->tempoExec, tipo);
	linha('-', 35);
}

void listarProcessos(Processo* pilha){
	Processo* aux=pilha;
	while(aux){
		showProcess(aux);
		aux=aux->next;
	}
}

Processo* criarProc(int qtd){
	Processo* pilha = NULL; 
	for(int p=0; p<qtd; p++){
		Processo* novo = new_processo();
		processoPush(&pilha, novo);
	}
	return pilha;
}

Recurso new_recurso(TipoRecurso tipo){
	Recurso new; 
	new.lock=0;
	new.tipo=tipo;
	new.processoUsando=NULL;
	return new;
}

void verificarRecurso(Recurso* rec, Processo *pilha){
	Processo* p = pilha;
	
	while(p){
		if(p->recursoNecessario==rec->tipo && !rec->lock){
			rec->lock=1;
			rec->processoUsando = p;
			return;
		}
		p=p->next;
	}
}

void mostrarRecurso(Recurso rec){
	char* tipo;
	if(rec.tipo == IMPRESSORA)
		tipo = IMPRESSORA_S; 
	if(rec.tipo == TELA) 
		tipo = TELA_S;	
	printf("Nome do recurso: %s\nO recruso está trancado?: %s\n", tipo, rec.lock? "sim":"não");
	if(rec.processoUsando){
		printf("Nome do processo utilizando o recurso: %s\n", rec.processoUsando->nomeProc);
		printf("PID do processo: %d\n", rec.processoUsando->pid);
		printf("Tempo restante para a finalização do processo: %d\n", rec.processoUsando->tempoExec);
	}else
		printf("Nome do processo utilizando o recurso: nenhum\n");
	linha('-', 35);
}

Processo* listaPull(Processo* p, Processo* pilha){
	
	if(p->prev)
		p->prev->next=p->next;
	if(p->next)
		p->next->prev=p->prev;
	
	Processo* prox=p->next;
	p->next=NULL;
	p->prev=NULL;
	
	if(p==pilha)
		return prox;
	return pilha;
}

Processo* deletarProcess(Processo* p, Processo* pilha){
	Processo* aux = listaPull(p, pilha);
	free(p);
	return aux;
}

Processo* executar(Recurso *rec, Processo* pilha){
	Processo* p = rec->processoUsando;
	if(p)
		(p->tempoExec)--;
	else
		return pilha;
	
	if(!p->tempoExec){
		rec->processoUsando = NULL;
		rec->lock=0;
		pilha = deletarProcess(p, pilha);
	}
	return pilha;
}

int main(){
	srand(time(NULL));
	Processo* pilha=NULL;
	Recurso tela=new_recurso(TELA);
	Recurso impressora=new_recurso(IMPRESSORA);
	
	int tempoGlobal=0;
	
	pilha = criarProc(5);
	
	printf("Processos criados:\n\n");
	listarProcessos(pilha);
	enter();
	clear();
	
	while(1){
		printf("\nRecursos:\n");
		mostrarRecurso(impressora);		
		mostrarRecurso(tela);	
		
		verificarRecurso(&tela,pilha);
		verificarRecurso(&impressora, pilha);
		
		printf("\nPilha de processos:\n");
		listarProcessos(pilha);
		enter();
		clear();
		
		pilha = executar(&tela, pilha);
		pilha = executar(&impressora, pilha);
		
		if(!pilha)
			break;
	
		tempoGlobal++;
	}
	
	printf("Processos finalizados!\n");
	return 0;
}

