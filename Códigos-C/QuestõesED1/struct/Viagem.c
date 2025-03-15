#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define INT  " %d"
#define STR   " %[^\n]s"
#define CHAR  " %c"
#define FLOAT  " %f"

//Structs:
typedef struct{
	int codVei, qtdPass, man, via;
	char placa[20]; 
}VeiFro;

typedef struct{
	char citOri[30], citDes[30];
	int codVei, pol[100], qtdMax, qtdAt;
	float valor;
}Viagem; 

//signs: 

void mostVei(VeiFro veiculos);

int buscarVei(VeiFro *veiculo, int qtdVei, int cod);

void mostVia(Viagem viagem);

void input(char *inst, void *lid, char *tipo);

void esp();

//funcs: 

void trocar(VeiFro *veiculo, Viagem *viagem){
	viagem->codVei = veiculo->codVei;
	viagem->qtdMax = veiculo->qtdPass;
	veiculo->via = 1;
}

int verificaTro(VeiFro veiculos[], int qtdVei, VeiFro preTro){

	for(int i=0; i<qtdVei; i++){
		if((veiculos[i].qtdPass >= preTro.qtdPass) && !veiculos[i].man && !veiculos[i].via)
			return i;
	}

	return -1;
}

int mandarMan(VeiFro *veiculo, int qtdVei, Viagem viagem[], int qtdVia){
	int op=0;
	do{
		input("\nQual desses veículos deseja mandar para a manutenção?(Digite um valor negativo para cancelar): ", &op, INT);
		if(op<0){
			printf("Operação cancelada!\n");
			esp();
			return 1;
		}
		op = buscarVei(veiculo, qtdVei, op);
		if(op<0 || veiculo[op].man){
			printf("Veículo não enconotrado ou já está em manutenção!\nTente novamente:\n");
			esp();
		}else{
			break;
		}
		printf("Veículo agendado para a manutenção!\n");
		esp();
	}while(1);

	//Procurando por viagens com esse veículo
	for(int i=0; i<qtdVia; i++){
		if(viagem[i].codVei == veiculo[op].codVei){
			int troca = verificaTro(veiculo, qtdVei, veiculo[op]);
			if(troca>=0){
				trocar(&veiculo[troca], &viagem[i]);
				veiculo[op].man = 1;
			}else{
				printf("Não é possível mandar esse veículo para a manutenção pois não é possível substitui-lo na viagem designada a ele!\n");
				esp();
				return 1;
			}
		}
	}

	return 0;
}

void relVia(Viagem viagem[], int qtdVia){
	for(int i=0; i<qtdVia; i++){
		mostVia(viagem[i]);
		printf("\n\nTotal arrecadado: %.2f\n", viagem[i].qtdAt*viagem[i].valor);
	}
}

void relVei(VeiFro *veiculo, int qtdVei, Viagem *viagem, int qtdVia){
	for(int i=0; i<qtdVei; i++){
		mostVei(veiculo[i]);

		printf("Viagem(s) cadastradas: \n\n");
		int exi=0;
		for(int j=0; j<qtdVia; j++)
			if(viagem[j].codVei == veiculo[i].codVei){
				mostVia(viagem[j]);
				printf("\n------------------------------------------------\n");
				exi=1;
			}
		if(!exi)
			printf("Nenhuma\n");
		printf(".............................................................\n\n");
	}
}

int buscarVia(char *origem, char *destino, Viagem viagem[], int qtdVia){

	for(int i=0; i<qtdVia; i++){
		if(!strcmp(origem, viagem[i].citOri))
			if(!strcmp(destino, viagem[i].citDes))
				return i;
	}

	return -1;
}

int venderPass(Viagem *viagem, int qtdVia, VeiFro *veiculo, int qtdVei){
	int op;
	char origem[30], destino[30], esc;

	printf("Digite a cidade de origem e destino desejadas: \n");
	printf("Origem: ");
	scanf(" %29[^\n]s", origem);
	printf("Destino: ");
    scanf(" %29[^\n]s", destino);    

	system("clear");

	op = buscarVia(origem, destino, viagem, qtdVia);

	Viagem *ata = &viagem[op];

	if(op<0 || ata->qtdAt == ata->qtdMax){
		printf("Essa viagem não está disponível!\n");
		esp();
		return 1;
	}

	mostVia(viagem[op]);

	input("\n\nDeseja continuar com a compra dessa passagem?(s/n): ", &esc, CHAR);
	if(esc=='n'){
		printf("Compra cancelada!\n");
		esp();
		return 1;
	}

	do{
		input("Digite o número da poltrona que deseja sentar(Digite um valor negativo para cancelar): ", &op, INT);
		if(op<0 || op>(ata->qtdMax-1) || ata->pol[op])
			printf("Poltrona não existente ou já ocupada!\n");
		if(op<0){
			printf("Compra cancelada!\n");
			esp();
			return 1;
		}
	}while(op<0 || op>(ata->qtdMax-1) || ata->pol[op]);

	//Colocando um 1 no lugar ocupado
	ata->pol[op] = 1; 
	ata->qtdAt++;
	
	printf("Passagem comprada com sucesso!\n");
	esp();
	return 0;
}

void mostVia(Viagem viagem){

	printf("Cidade origem: %s\n", viagem.citOri);
	printf("Cidade destino: %s\n", viagem.citDes);
	printf("Poltronas ocupadas: %d\n", viagem.qtdAt);
	printf("Poltronas sobrando: %d\n", viagem.qtdMax - viagem.qtdAt);
	printf("Preço da viagem: %.2f\n", viagem.valor);
	printf("Código do veículo que vai realizar a viagem: %d\n", viagem.codVei);
	printf("\n");

	//Mostrando as poltronas
	printf("Poltronas: \n");
	int tab=0, ent=0;
	for(int i=0; i<viagem.qtdMax; i++){
		if(viagem.pol[i])
			printf("%03d.[X] ", i);
		else	
			printf("%03d.[ ] ", i);

		tab++;
		if(!(tab%2)){
			if(ent)
				printf("\n");
			else 
				printf("\t");
		}

		if(tab==2){
			if(ent)
				ent=0;
			else 
				ent=1;
			
			tab=0; 
		}
	}
}

void mostVei(VeiFro veiculos){
	printf("Placa do veículo: %s\nCódigo do veículo: %d\n", veiculos.placa, veiculos.codVei);
	if(veiculos.man)
		printf("Esse veículo está marcada para manutenção!\n");
	printf("Passageiros máximos: %d\n", veiculos.qtdPass);
}

int ver(VeiFro *veiculo, int qtdVei){
	for(int i=0; i<qtdVei; i++){
		if(!veiculo[i].man)
			return 0;
	}
	printf("Não existem veículos disponíveis!\n");
	esp();
	return 1; 
}

int buscarVei(VeiFro *veiculo, int qtdVei, int cod){
	for(int i=0; i<qtdVei; i++){
		if(cod==veiculo[i].codVei)
			return i; 
	}
	return -1;
}

int cadastVia(Viagem *viagem, int qtdVia, VeiFro *veiculo, int qtdVei){
	int cod;
	char origem[30], destino[30];
	input("Qual é a cidade de origem?: ", origem, " %29[^\n]s");
	input("Qual é a cidade de destino?: ", destino, " %29[^\n]s");
	system("clear");
	if(buscarVia(origem, destino, viagem, qtdVia)>=0){
		printf("Essa viagem já existe!\n");
		esp();
		return 1;
	}

	strcpy(viagem[qtdVia].citOri, origem); 
	strcpy(viagem[qtdVia].citDes, destino);

	do{
		char op;
		printf("\n\nVeículos disponíveis: \n\n");
		for(int i=0; i<qtdVei; i++){
			if(veiculo[i].man)
				continue;
			mostVei(veiculo[i]);
			printf(".............................................................\n\n");
		}
		do{
			input("Qual é o código do veículo que vai fazer essa viagem?: ", &cod, INT);
			cod = buscarVei(veiculo, qtdVei, cod);
			if(cod < 0 || veiculo[cod].man){
				printf("Veículo não encontrado ou está em manutenção!\nDeseja tentar novamente?(s/n):");
				scanf(" %c", &op);
				if(op!='s')
					return 1;
			}
		}while(cod < 0 || veiculo[cod].man);
	}while(cod<0);	

	viagem[qtdVia].qtdMax = veiculo[cod].qtdPass; 
	viagem[qtdVia].codVei = veiculo[cod].codVei;
	viagem[qtdVia].qtdAt  = 0;
	veiculo[cod].via = 1;
	//Iniciando as poltronas
	for(int i=0; i<viagem[qtdVia].qtdMax; i++)
		viagem[qtdVia].pol[i] = 0;
	
	//Selecionando poltronas aleatorias
	int metade = viagem[qtdVia].qtdMax/2; 

	for(int i=0; i<(metade+1); i++){
		int oc = rand()%viagem[qtdVia].qtdMax;
		viagem[qtdVia].pol[oc]=1;
		viagem[qtdVia].qtdAt++;
	}

	input("Qual vai ser o valor da passagem?:\n", &viagem[qtdVia].valor, FLOAT);
	printf("Viagem cadastrada com sucesso!\n");
	esp();
	return 0;	
}

void esp(){
	setbuf(stdin, NULL); 
	printf("Aperte ENTER para continuar...");
	while(getchar()!='\n');
	
}

void input(char *inst, void *lid, char *tipo){
	printf("%s", inst);
	scanf(tipo, lid);
}

void cadastVei(VeiFro *veiculo, int qtdVei){
	veiculo->codVei = qtdVei + 1;
	veiculo->via = 0; 
	input("Digite a quantidade de passageiros máxima: ", &veiculo->qtdPass, INT);
	input("Digite a placa do veículo: ", veiculo->placa, STR);
	input("Esse veículo está em manutenção(1 para sim e 0 para não)? ", &veiculo->man, INT);
}

int interface(){
	system("clear");
	int op;
	printf("1. CADASTRAR VEÍCULO NA FROTA\n");
	printf("2. CADASTRAR VIAGEM\n");
	printf("3. VENDER PASSAGEM\n");
	printf("4. RELATÓRIO: FROTA DE VEÍCULOS\n");
	printf("5. RELATÓRIO: VIAGENS E PASSAGENS VENDIDAS\n");
	printf("6. MANDAR UM VEÍCULO PARA A MANUTENÇÃO\n");
	printf("--------------------------------------------------\n");
	printf("0. SAIR\n");
	printf("Digite o número correspondente a opção desejada:\n");
	scanf(" %d", &op);
	return op;
}

int main(){
	srand(time(NULL));
	VeiFro veiculo[100]; 
	Viagem viagem[100]; 
	int qtdVei=0, qtdVia=0; 
	

	
	do{
		switch(interface()){
			case 0: 
				return 0; 
			case 1: 	
				cadastVei(&veiculo[qtdVei], qtdVei); 
				qtdVei++;
				esp(); 
				break; 
			case 2: 
				if(ver(veiculo, qtdVei))
					break;
					
				if(!cadastVia(viagem, qtdVia, veiculo, qtdVei)) 
					qtdVia++;
				break; 
			case 3: 	
				if(!qtdVia){
					printf("Não existem viagens disponíveis!\n");
					esp();
					break; 
				}
				venderPass(viagem, qtdVia, veiculo, qtdVei);
				break; 
			case 4: 
				if(!qtdVei){
					printf("Nenhum veículo cadastrado!\n");
					esp();
					break;
				}
				system("clear");
				relVei(veiculo, qtdVei, viagem, qtdVia);
				esp();
				break;
			case 5:
				if(!qtdVia){
					printf("Nenhuma viagem cadastrada!\n");
					esp();
					break;
				}
				relVia(viagem, qtdVia);
				esp();
				break;
			case 6:
				if(ver(veiculo, qtdVei))
					break;
				//Mostrando todos os veículos, exceto que já estão em manutenção
				for(int i=0; i<qtdVei; i++){
					if(veiculo[i].man)
						continue;
					mostVei(veiculo[i]);
					printf("\n////////////////////////////////////////////////\n");
				}				
				mandarMan(veiculo, qtdVei, viagem, qtdVia);
				break;
			default: 
				printf("Opção inválida!\n");
				esp();
			
		}
	}while(1); 
	return 0;
}