/*
	Name: shellSort.c
	Author: Gustavo Silva Souza
	Date: 15/05/24 10:21
	Description: implementação do algoritmo Shell Sort em linguagem C
*/

//sessão de bibliotecas
#include <stdio.h>
#include <locale.h>



//sessão de prototipação
void popularVetor(int *, int);
void exibirVetor(int *, int);
void shellSort(int *, int);



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
	
	//ordenando o vetor com o algoritmo de Shell Sort
	shellSort(vetor, tamanho);
	
	//exibindo o vetor ordenado
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

void shellSort(int vetor[], int tamanho)
{
	int i, j, chave;
	int h = 1;
	
	while(h < tamanho)
	{
		h = h * 3 + 1;
	}
	
	while(h > 0)
	{
		for(i = h; i < tamanho; i++)
		{
			chave = vetor[i];
			j = i;
			
//			comparacoes++;
			while(j > (h - 1) && chave <= vetor[j - h])
			{
//				comparacoes++;
//				trocas++;
				vetor[j] = vetor[j - h];
				j -= h;
			}
			
			vetor[j] = chave;
		}
		
		h /= 2;
	}
}
