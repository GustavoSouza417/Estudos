/*
	Name: quickSort.c
	Author: Gustavo Silva Souza
	Date: 29/05/24 09:50
	Description: implementação do algoritmo Quick Sort em linguagem C
*/



//seção de bibliotecas
#include <stdio.h>



//seção de #defines
#define tam(x) sizeof(x)/sizeof(x[0])



//seção de prototipação
void quicksort(int *, int, int);
int separe(int *, int, int);



//função principal
int main()
{
	int corpus[10] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
	int i, size;
	size = tam(corpus);
	
	puts("VETOR DESORDENADO");
	for(i = 0; i < size; i++)
		printf("%d | ", corpus[i]);
		
	quickSort(corpus, 0, size-1);
		
	puts("\nVETOR ORDENADO");
	for(i = 0; i < size; i++)
		printf("%d | ", corpus[i]);
}



//seção de funções
void quickSort(int *vet, int ini, int end)
{
	int pivot, i;
	
	if(end > ini)
	{
		pivot = separe(vet, ini, end);
		quickSort(vet, ini, pivot - 1);
		quickSort(vet, pivot + 1, end);
	}
}

int separe(int *vet, int ini, int end)
{
	int esq, dir, pivo, aux;
	esq = ini;
	dir = end;
	pivo = vet[ini];
	
	while(esq < dir)
	{
		while(vet[esq] <= pivo)
			esq++;
			
		while(vet[dir] > pivo)
			dir--;
			
		if(esq < dir)
		{
			aux = vet[dir];
			vet[dir] = vet[esq];
			vet[esq] = aux;
		}
		
		printf("\n");
		
		int i;
		
		for(i = 0; i < 10; i++)
			printf("%d | ", vet[i]);
		printf("\n");
		
		getch();
	}
	vet[ini] = vet[dir];
	vet[dir] = pivo;
	
	return dir;
}
