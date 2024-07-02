#include <stdio.h>


#define tam(vet, elmnt) sizeof(vet)/sizeof(elmnt)
int corpus[10] = {17, 24, 3, 8, 15, 10, 1, 19, 12, -5};

int main()
{
	int tam = tam(corpus, corpus[0]);
	int i, j, trocas, comparacoes;
	i = j = trocas = comparacoes = 0;
	
	printf("vetor DESORDENADO\n");
	for(i = 0; i < tam; i++)
	{
		printf("| %d ", corpus[i]);
	}
	
	puts("");
	
	// Ordenação
	while(j < tam)
	{
		for(i = 0; i < tam-1; i++)
		{
			comparacoes++;
			
			if(corpus[i] > corpus[i + 1])
			{
				trocas++;
				
				int aux = corpus[i];
				corpus[i] = corpus[i + 1];
				corpus[i + 1] = aux;
				
				int k;
				for(k = 0; k < tam; k++)
				{
					printf("| %d ", corpus[k]);
				
				}
				
				puts(" ");
			}
		}
		
		tam--; //j++
	}
	
	tam = tam(corpus, corpus[0]);
	printf("\n\nvetor ORDENADO\n");
	for(i = 0; i < tam; i++)
	{
		printf("| %d ", corpus[i]);
	}
	
	printf("\nTrocas: %d", trocas);
	printf("\nComparacoes: %d", comparacoes);
}
