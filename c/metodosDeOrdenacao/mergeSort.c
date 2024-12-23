/*
	Name: mergeSort.c
	Author: Gustavo Silva Souza
	Date: 22/05/24 09:43
	Description: implementa��o do m�todo de ordena��o Merge Sort
*/



//se��o de bibliotecas
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>



//se��o de prototipa��o
void mergeSort(int *, int, int); //Fun��o respons�vel pela divis�o dos vetores logicamente
void merge(int *, int, int, int); //Fun��o respons�vel por juntar novamente os vetores separados



//se��o de vari�veis globais
int vet[] = {17, 24, -5, 8, 15, 10, 1, 19, 12, 3};
int i;



//fun��o principal
int main()
{
	setlocale(LC_ALL, "Portuguese");

	int comeco, fim;
	comeco = 0;
	fim = sizeof(vet) / sizeof(int) -1;
	
	puts("Vetor Original: ");
	for(i = 0; i <= fim; i++)
		printf("%d|", vet[i]);
		
	mergeSort(vet, comeco, fim);
	
	puts("\n\nVetor ordenado pelo Merge Sort: ");
	for(i = 0; i <= fim; i++)
		printf("%d|", vet[i]);
}



//se��o de fun��es
void mergeSort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		int meio = (inicio + fim) / 2;
		
		mergeSort(vet, inicio, meio); //Quebra todos os elementos do lado esquerdo
		mergeSort(vet, meio + 1, fim); //Quebra todos os elementos do lado direito
		merge(vet, inicio, meio, fim); //Junta todos os elementos �nicos
	}
}

void merge(int vet[], int comeco, int meio, int fim)
{
	int com1 = comeco;
	int com2 = meio + 1;
	int comAux = 0;
	int tam = fim - comeco + 1;
	int vetAux[tam];
	
	while(com1 <= meio && com2 <= fim)
	{
		if(vet[com1] < vet[com2])
		{
			vetAux[comAux] = vet[com1];
			com1++;
		}
		else
		{
			vetAux[comAux] = vet[com2];
			com2++;
		}
		
		comAux++;
	}
	
	while(com1 <= meio) //Caso ainda haja elementos na primeira metade
	{
		vetAux[comAux] = vet[com1];
		com1++;
		comAux++;
	}
	
	while(com2 <= fim) //Caso ainda haja elementos na segunda metade
	{
		vetAux[comAux] = vet[com2];
		com2++;
		comAux++;
	}
	
	for(comAux = comeco; comAux <= fim; comAux++) //Migrando os valores ordenados de vetAux para vet
		vet[comAux] = vetAux[comAux - comeco];
}
