#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define TAM 10

FILE *arq;
int x, y, aux=0, start, end, qtde_trocas;
int vetorprincipal2[TAM], vetorprincipal[TAM], vetorBubble[TAM], vetorInsertion[TAM], vetorSelection[TAM], vetorSemiOrd[TAM], vetorordenado[TAM];

preencherVetor()
{
		
	printf ("\nGerando um vetor com %d inteiros aleatorios", TAM);
	getchar();
	
	for (x=0;x<TAM;x++)
	{
		vetorprincipal[x]=rand()%TAM;
		
		//carregando vetor principal nos secundários
		vetorBubble[x]=vetorprincipal[x];
		vetorInsertion[x]=vetorprincipal[x];
		vetorSelection[x]=vetorprincipal[x];
		
		printf ("%d\t",vetorprincipal[x]);
	}
	
}

bubble ()
{
qtde_trocas=0;

	for (x=0;x<TAM;x++)
	{
		for (y=x+1;y<TAM;y++)
		{
			if (vetorBubble[x]>vetorBubble[y])
			{
				aux=vetorBubble[x];
				vetorBubble[x]=vetorBubble[y];
				vetorBubble[y]=aux;
				qtde_trocas++;
			}
		}
	}

}

insertion ()
{
	qtde_trocas=0;
	
	int chave;
	
	for (x=1;x<TAM;x++)
	{
		chave = vetorInsertion[x];
		y=x-1;
		while((y>=0) && (vetorInsertion[y]>chave))
		{
			vetorInsertion[y+1]=vetorInsertion[y];
			y=y-1;
			
		}
	vetorInsertion[y+1]=chave;
	qtde_trocas++;

	}
	
}

selection ()
{
	
	qtde_trocas=0;
	
	int menor;
	
	for(x=0;x<TAM-1;x++)
	{
		menor=x;
		for (y=x+1;y<TAM;y++)
		{
			if (vetorSelection[y]<vetorSelection[menor])
			{
				menor=y;
				
			}
			
			aux = vetorSelection[menor];
			vetorSelection[menor] = vetorSelection[x];
			vetorSelection[x] = aux;
			qtde_trocas++;
		}
	}
}

inicio ()
{
	
	start = GetTickCount();
	printf("\nInicio: %d",start);
	
}

final ()
{
	
	end = GetTickCount();
	printf("\nFim: %d",end);
	
}

 clone(){
 	for(x=0;x<TAM;x++){
 		vetorprincipal2[x]=vetorInsertion[x];
 	}
 	arq = fopen ("dados2.txt", "a+");
 	
 	for(x=0;x<TAM;x++){
		fprintf(arq, "%d \t", vetorInsertion[x]);
	}
	
	fclose(arq);
	printf("\nArquivo clonado com sucesso! \n \n");
 	
 	
 }
 
 abrirclone(){
 	arq=fopen("dados2.txt", "r");
 	x=0;
	while(!feof(arq))
	{
		fscanf(arq, "%d \t",&vetorordenado[x]);
		x++;
	}
	
	fclose(arq);
	
	for(x=0;x<TAM;x++){
		printf("%d \t", vetorordenado[x]);
	}
 }
 
 
 
 ordenar(){
 	system("cls");
 	
 	int tempo_decorrido;
		
	printf("\nOrdenacao com 3 metodos :\n");

	//ordenando: BUBBLE

	printf("\nOrdenacao: BUBBLE desordenado\n");
	
	inicio(start);
	bubble();
	final(end);

	tempo_decorrido = end - start;

	printf ("\nTempo de Ordenacao em segundos: %d milisegundos",tempo_decorrido);
	printf("\nQuantidade de trocas: %d",qtde_trocas);
	getchar();

	//ordenando: INSERTION
	
	printf("\nOrdenacao: INSERTION desordenado\n");
	
	inicio(start);
	insertion();
	final(end);
	
	tempo_decorrido = end - start;
	
	printf ("\nTempo de Ordenacao em segundos: %d milisegundos",tempo_decorrido);
	printf("\nQuantidade de trocas: %d",qtde_trocas);
	getchar();

	//ordenando: SELECTION

	printf("\nOrdenacao: SELECTION desordenado\n");
	
	inicio(start);
	selection();
	final(end);

	tempo_decorrido = end - start;
	
	printf ("\nTempo de Ordenacao em segundos: %d milisegundos",tempo_decorrido);
	printf("\nQuantidade de trocas: %d",qtde_trocas);
	getchar();	
 }
 
 
 ordenarclone(){
 	vetorBubble[x]=vetorordenado[x];
	vetorInsertion[x]=vetorordenado[x];
	vetorSelection[x]=vetorordenado[x];
	
	ordenar();
 }

main()
{
	
	
	
	//gerando vetor
	
	preencherVetor();
	getchar();
	
	ordenar();
	
	//GRAVANDO EM ARQUIVO
	
	arq = fopen ("dados.txt", "a+");
	
	for(x=0;x<5;x++){
		vetorInsertion[x]=rand()%TAM;
	}
	
	for(x=0;x<TAM;x++){
		fprintf(arq, "%d \t", vetorInsertion[x]);
	}
	
	fclose(arq);
	printf("\nArquivo gravado com sucesso! \n \n");
	
	x=0;
	arq=fopen("dados.txt", "r");
	while(!feof(arq))
	{
		fscanf(arq, "%d \t",&vetorSemiOrd[x]);
		x++;
	}
	
	fclose(arq);
	
	for(x=0;x<TAM;x++){
		printf("%d \t", vetorSemiOrd[x]);
	}
	
	clone();
	abrirclone();
	ordenarclone();
	
	for(x=0;x<TAM;x++){
		printf("%d \t", vetorInsertion[x]);
	}
}



