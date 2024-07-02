/*m
	Name: listaEncadeada.c
	Author: Gustavo Silva Souza
	Date: 13/03/24 09:58
	Description: programa para implementar listas encadeadas
*/



//sess�o de bibliotecas
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>



//estruturas de dados
struct No
{
	int valor;
	struct No *proximo;
};

struct Lista
{
	No *inicio, *fim;
	int tamanho;
};



//sess�o de prototipa��o
void inserirInicio(Lista *, int);
void inserirFim(Lista *, int);
void exibirLista(Lista *);



//fun��o principal
main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Lista numeros;
	int valor;
	
	//inicializa��o da lista
	numeros.inicio  = NULL;
	numeros.fim     = NULL;
	numeros.tamanho = 0;
	
//	inserirInicio(&numeros, 33);
//	inserirInicio(&numeros, 34);
//	inserirInicio(&numeros, 35);
//	inserirInicio(&numeros, 36);
//	inserirInicio(&numeros, 37);
	
	inserirFim(&numeros, 33);
	inserirFim(&numeros, 34);
	inserirFim(&numeros, 35);
	inserirFim(&numeros, 36);
	inserirFim(&numeros, 37);
	
	exibirLista(&numeros);
}



//sess�o de fun��es

//insere um novo n� no in�cio da lista
void inserirInicio(Lista *lista, int valor)
{
	No *novo = (No*) malloc(sizeof(No));
	novo -> valor = valor;
	
	if(lista -> inicio == NULL) //se a lista estiver vazia
	{
		novo  -> proximo = NULL;
		lista -> inicio  = novo;
		lista -> fim     = novo;
	}
	else //se a lista tiver pelo menos um n�
	{
		novo  -> proximo = lista -> inicio;
		lista -> inicio  = novo;
	}
	
	lista -> tamanho++;
}

//insere um novo n� no fim da lista
void inserirFim(Lista *lista, int valor)
{
	No *novo = (No*) malloc(sizeof(No));
	novo -> valor   = valor;
	novo -> proximo = NULL;
	
	if(lista -> inicio == NULL) //se a lista estiver vazia
	{
		lista -> inicio = novo;
		lista -> fim    = novo;
	}
	else //se a lista tiver pelo menos um n�
	{
		lista -> fim -> proximo = novo;
		lista -> fim = novo;
	}
	
	lista -> tamanho++;
}

//imprime os elementos presentes na lista
void exibirLista(Lista *lista)
{
	No *inicio = lista -> inicio;
	printf("Tamanho da lista: %d\n\n", lista -> tamanho);
	
	while(inicio != NULL)
	{
		printf("%d\n", inicio -> valor);
		inicio = inicio -> proximo;
	}
}
