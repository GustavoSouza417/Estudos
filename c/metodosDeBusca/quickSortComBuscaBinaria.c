/*
	Name: quickSort&BinarySearch.c
	Author: Gustavo Silva Souza
	Date: 29/05/24 09:50
	Description: implementação dos algoritmos Quick Sort e busca binária
*/



//seção de bibliotecas
#include <stdio.h>



//seção de #defines
#define tam(x) sizeof(x)/sizeof(x[0])



//seção de prototipação
void quicksort(int *, int, int);
int separe(int *, int, int);
int binarySearch(int *, int, int, int);



//função principal
int main()
{
	int corpus[10] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
	int i, size, elem;
	size = tam(corpus);
	
	puts("VETOR DESORDENADO");
	for(i = 0; i < size; i++)
		printf("%d | ", corpus[i]);
		
	quickSort(corpus, 0, size - 1);
		
	puts("\nVETOR ORDENADO");
	for(i = 0; i < size; i++)
		printf("%d | ", corpus[i]);
		
	puts("\nElemento a ser buscado: ");
	scanf("%d", &elem);
	
	puts("\nResultado da busca sequencial: ");
//	printf("%d", binarySearch(corpus, 0, size-1, elem));
	binarySearch(corpus, 0, size - 1, elem);
}

void quickSort(int *vet, int ini, int end)
{
	int pivot, i;
	
	if(end > ini)
	{
		pivot = separe(vet, ini, end);
		quickSort(vet, ini, pivot-1);
		quickSort(vet, pivot+1, end);
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
	}
	
	vet[ini] = vet[dir];
	vet[dir] = pivo;
	
	return dir;
}

int binarySearch(int *arr, int begin, int end, int elmnt)
{
	int i, half, foundElmnt;
	foundElmnt = 0;
	
	while(begin <= end)
	{
		half = (begin + end) / 2;
		
		if(elmnt == arr[half])
		{
			foundElmnt = 1;
			break;
		}
		else if(elmnt < arr[half])
			end = half - 1;
		else
			begin = half + 1;
	}
	
	if(foundElmnt == 1)
	{
		printf("Elemento '%d' localizado no índice '%d'", arr[half], half);
		return arr[half];
	}
	else
	{
		printf("Elemento '%d' não localizado.");
		return 0;
	}
}
