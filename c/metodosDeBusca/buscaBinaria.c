/*
	Name: buscaBinaria.c
	Author: Gustavo Silva Souza
	Date: 15/05/24 10:21
	Description: implementação do algoritmo de busca binária/logaritmica em linguagem C
*/

//seção de bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>



//seção de prototipação
void popularVetor(int *, int);
void exibirVetor(int *, int);
void shellSort(int *, int);
void buscaBinaria(int *, int, int, int);



//função principal
void main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
//	int vetor[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
	int vetor[10];
	int tamanho, i, elementoBuscaBinaria;
	tamanho = sizeof(vetor) / sizeof(int);
	
	//populando vetor com números aleatórios
	popularVetor(vetor, tamanho);
	
	//exibindo vetor desordenado
	puts("VETOR DESORDENADO:");
	exibirVetor(vetor, tamanho);
	
	//ordenando o vetor com o algoritmo de Shell Sort
	shellSort(vetor, tamanho);
	
	//exibindo o vetor ordenado
	puts("\n\nVETOR ORDENADO:");
	exibirVetor(vetor, tamanho);
	
	//realizando a busca binária
	puts("\n\nBUSCA BINÁRIA/LOGARITMICA:");
	printf("Elemento: ");
	scanf("%d", &elementoBuscaBinaria);
	buscaBinaria(vetor, 0, tamanho - 1, elementoBuscaBinaria);
}



//seção de funções
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
			
			while(j > (h - 1) && chave <= vetor[j - h])
			{
				vetor[j] = vetor[j - h];
				j -= h;
			}
			
			vetor[j] = chave;
		}
		
		h /= 2;
	}
}

void buscaBinaria(int vetor[], int inicio, int fim, int elemento)
{
	int meio = 0;
	int qtdBuscas = 0;
	bool achouElemento = false;
	
	while(inicio <= fim)
	{
		meio = (inicio + fim) / 2;
		qtdBuscas++;
		
		if(elemento == vetor[meio])
		{
			achouElemento = true;
			break;	
		}
			
		else if(elemento < vetor[meio])
			fim = meio - 1;
		
		else
			inicio = meio + 1;
	}
	
	if(achouElemento)
		printf("\nO elemento existe e está na posição %d do vetor", meio);
	else
		printf("\nO elemento não existe");
		
	printf("\n\nQuantidade de buscas: %d", qtdBuscas);
}
