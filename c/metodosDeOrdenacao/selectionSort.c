/*
	Name: selectionSort.c
	Author: Gustavo Silva Souza
	Date: 08/05/24 10:09
	Description: implementação do algoritmo "Selection Sort" em C
*/



//sessão de bibliotecas
#include <stdio.h>
#include <stdlib.h> //biblioteca para as funções "rand()" e "srand()"
#include <time.h>   //biblioteca para a função "time"
#include <locale.h>



//função principal
void main()
{
	setlocale(LC_ALL, "Portuguese");


	//declaração de variáveis	
//	int vetor[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
	int vetor[10];
	int tamanhoVetor, i, j, auxiliarDeTrocaDeValores, menorElemento, numeroDeComparacoes, numeroDeTrocas;

	
	//atribuição de variáveis
	tamanhoVetor = sizeof(vetor) / sizeof(int);
	numeroDeComparacoes = numeroDeTrocas = 0;
	//plantando a semente de aleatoriedade a partir do tempo
	srand(time(NULL));

	
	//populando o vetor com números aleatórios
	for(i = 0; i < tamanhoVetor; i++)
		vetor[i] = rand() % 100;

	
	//exibindo o vetor desordenado, antes da ordenação
	puts("Vetor antes da ordenação:");
	for(i = 0; i < tamanhoVetor; i++)
		printf("%d | ", vetor[i]);

		
	//efetuando a ordenação do vetor
	for(i = 0; i < tamanhoVetor; i++)
	{
		menorElemento = i;
		
		for(j = (i + 1); j < tamanhoVetor; j++)
		{
			numeroDeComparacoes++;
			
			//se você muda para o operador relacional de "maior do que", ele deixa do maior para o menor
			if(vetor[j] < vetor[menorElemento])
				menorElemento = j;
		}
		
		numeroDeComparacoes++;
		if(i != menorElemento)
		{
			auxiliarDeTrocaDeValores = vetor[i];
			vetor[i] = vetor[menorElemento];
			vetor[menorElemento] = auxiliarDeTrocaDeValores;
			numeroDeTrocas++;
		}
	}

	
	//exibindo o vetor ordenado, após a ordenação
	puts("\n\nVetor depois da ordenação:");
	for(i = 0; i < tamanhoVetor; i++)
		printf("%d | ", vetor[i]);

	
	//exibindo a quantidade de comparações e trocas efetuadas pelo algoritmo
	printf("\n\nNúmero de comparações: %d", numeroDeComparacoes);	
	printf("\nNúmero de trocas: %d", numeroDeTrocas);
}
