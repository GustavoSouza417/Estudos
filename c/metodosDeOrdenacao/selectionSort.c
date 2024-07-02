/*
	Name: selectionSort.c
	Author: Gustavo Silva Souza
	Date: 08/05/24 10:09
	Description: implementa��o do algoritmo "Selection Sort" em C
*/



//sess�o de bibliotecas
#include <stdio.h>
#include <stdlib.h> //biblioteca para as fun��es "rand()" e "srand()"
#include <time.h>   //biblioteca para a fun��o "time"
#include <locale.h>



//fun��o principal
void main()
{
	setlocale(LC_ALL, "Portuguese");


	//declara��o de vari�veis	
//	int vetor[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
	int vetor[10];
	int tamanhoVetor, i, j, auxiliarDeTrocaDeValores, menorElemento, numeroDeComparacoes, numeroDeTrocas;

	
	//atribui��o de vari�veis
	tamanhoVetor = sizeof(vetor) / sizeof(int);
	numeroDeComparacoes = numeroDeTrocas = 0;
	//plantando a semente de aleatoriedade a partir do tempo
	srand(time(NULL));

	
	//populando o vetor com n�meros aleat�rios
	for(i = 0; i < tamanhoVetor; i++)
		vetor[i] = rand() % 100;

	
	//exibindo o vetor desordenado, antes da ordena��o
	puts("Vetor antes da ordena��o:");
	for(i = 0; i < tamanhoVetor; i++)
		printf("%d | ", vetor[i]);

		
	//efetuando a ordena��o do vetor
	for(i = 0; i < tamanhoVetor; i++)
	{
		menorElemento = i;
		
		for(j = (i + 1); j < tamanhoVetor; j++)
		{
			numeroDeComparacoes++;
			
			//se voc� muda para o operador relacional de "maior do que", ele deixa do maior para o menor
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

	
	//exibindo o vetor ordenado, ap�s a ordena��o
	puts("\n\nVetor depois da ordena��o:");
	for(i = 0; i < tamanhoVetor; i++)
		printf("%d | ", vetor[i]);

	
	//exibindo a quantidade de compara��es e trocas efetuadas pelo algoritmo
	printf("\n\nN�mero de compara��es: %d", numeroDeComparacoes);	
	printf("\nN�mero de trocas: %d", numeroDeTrocas);
}
