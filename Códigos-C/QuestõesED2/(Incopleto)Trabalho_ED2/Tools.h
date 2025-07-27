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
