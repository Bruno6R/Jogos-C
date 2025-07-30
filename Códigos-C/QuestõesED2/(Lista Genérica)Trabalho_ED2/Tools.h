void preencherVetor(int *vetor, int tam){
	for(int i=0; i<tam; i++)
		vetor[i] = rand()%100; 
}

void mostrarVetor(int *vetor, int tam){
	for(int i=0; i<tam; i++)
		printf("[%d] ", vetor[i]);
	printf("\n");
}

void ov(){
	while(getchar()!='\n'); 
}

void enter(){
	setbuf(stdin, NULL); 
	printf("Aperte ENTER para continuar...\n");
	ov();
}

void linha(char sim, int qtd){
	for(int i=0; i<qtd; i++)
		printf("%c", sim); 
	printf("\n");
}

int confirma(char* msg){
	int esco;
	while(1){
		
		printf("%s\n", msg);
		printf("1.Sim\n");
		printf("2.Não\n");  
		
		scanf(" %d", &esco);
		ov();
		switch(esco){
			case 1: 
				return 1;
			case 2:
				printf("Ação cancelada!\n");
				return 0;
			default:
				printf("Opção inválida!\n");
				enter();
		}
	}
}
