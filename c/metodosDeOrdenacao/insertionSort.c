/*
	Name: insertionSort.c
	Author: Gustavo Silva Souza
	Date: 15/05/24 09:49
	Description: implementação do algoritmo Insertion Sort em linguagem C
*/

//sessão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>



//sessão de prototipação
void popularVetor(int *, int);
void exibirVetor(int *, int);
void insertionSort(int *, int);



//função principal
void main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
//	int vetor[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
	int vetor[10];
	int tamanho, i, trocas, comparacoes;
	tamanho = sizeof(vetor) / sizeof(int);
	trocas = comparacoes = 0;
	
	//populando vetor
	popularVetor(vetor, tamanho);
	
	//exibindo vetor desordenado
	puts("VETOR DESORDENADO:");
	exibirVetor(vetor, tamanho);
		
	//ordenando o vetor com o algoritmo Insertion Sort
	insertionSort(vetor, tamanho);
		
	//exibindo vetor ordenado
	puts("\n\nVETOR ORDENADO:");
	exibirVetor(vetor, tamanho);
}



//sessão de funções
void popularVetor(int vetor[], int tamanho)
{
	int i;
	srand(time(NULL));
	
	for(i = 0; i < tamanho; i++)
		vetor[i] = rand() % 100;
}

void exibirVetor(int vetor[], int tamanho)
{
	int i;
	
	for(i = 0; i < tamanho; i++)
		printf("%d | ", vetor[i]);
}

void insertionSort(int vetor[], int tamanho)
{
	int i, j, chave;
	
	for(i = 1; i < tamanho; i++)		
	{
		chave = vetor[i];
		j = i - 1;
		
//		comparacoes++;
		while(j >= 0 && vetor[j] > chave)
		{
//			comparacoes++;
//			trocas++;
			vetor[j + 1] = vetor[j];
			j--;
		}	
		
		vetor[j + 1] = chave;
	}
}
