/*
	Name: crudListas.cpp
	Author: Gustavo Silva Souza
	Date: 27/03/24 08:33
	Description: CRUD de listas em C
*/



//sess�o de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//sess�o de structs
struct No
{
	int valor;
	struct No *proximo;
	struct No *anterior;
};

struct Lista
{
	No *inicio, *fim;
	int tamanho;	
};



//sess�o de prototipa��o
void inserirElementoNoInicioDaLista(Lista *, int);
void inserirElementoNoFimDaLista(Lista *, int);
void exibirLista(Lista *);
void removerElementoNoInicioDaLista(Lista *, int);



//fun��o principal
main()
{
	setlocale(LC_ALL, "Portuguese");
	
	//instanciando lista vazia
	Lista lista;
	lista.inicio  = NULL;
	lista.fim     = NULL;
	lista.tamanho = 0;
	
	//exibe da direita para a esquerda
	//	inserirElementoNoInicioDaLista(&lista, 10);
	//	inserirElementoNoInicioDaLista(&lista, 20);
	//	inserirElementoNoInicioDaLista(&lista, 30);
	//	inserirElementoNoInicioDaLista(&lista, 40);
	
	//exibe da esquerda para a direita
	//	inserirElementoNoFimDaLista(&lista, 10);
	//	inserirElementoNoFimDaLista(&lista, 20);
	//	inserirElementoNoFimDaLista(&lista, 30);
	//	inserirElementoNoFimDaLista(&lista, 40);
	
	//mistura as duas formas
	//	inserirElementoNoInicioDaLista(&lista, 10);
	//	inserirElementoNoFimDaLista(&lista, 20);
	//	inserirElementoNoInicioDaLista(&lista, 30);
	//	inserirElementoNoFimDaLista(&lista, 40);
	
	exibirLista(&lista);
}



//sess�o de fun��es
void inserirElementoNoInicioDaLista(Lista *lista, int valor) //insere da direita para a esquerda
{
	//cria o n� e preenche seus dados
	No *no = (No *) malloc(sizeof(No));
	no -> valor = valor;
	
	if(lista -> inicio == NULL) //caso a lista esteja vazia
	{
		no    -> proximo = NULL;
		lista -> inicio  = no;
		lista -> fim     = no;
	}
	else //caso a lista j� tenha algum elemento
	{
		no    -> proximo = lista -> inicio;
		lista -> inicio = no;
	}
	
	lista -> tamanho++;
}

void inserirElementoNoFimDaLista(Lista *lista, int valor) //insere da esquerda para a direita
{
	No *no = (No *) malloc(sizeof(No));
	no -> valor   = valor;
	no -> proximo = NULL;
	
	if(lista -> inicio == NULL)
	{
		lista -> inicio  = no;
		lista -> fim     = no;
	}
	else
	{
		lista -> fim -> proximo = no; //o elemento que era o �ltimo da lista recebe, na propriedade "proximo", o endere�o do n�
		lista -> fim = no;
	}
	
	lista -> tamanho++;
}

void exibirLista(Lista *lista)
{	
	No *no = lista -> inicio;
	
	for(int i = 0; i < sizeof(lista -> tamanho); i++)
	{
		printf("V%i: %i\n", i + 1, no -> valor);
		no = no -> proximo;
	}
}

void removerElementoNoInicioDaLista(Lista *lista)
{
	
}
