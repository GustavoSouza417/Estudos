//sessão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//sessão de structs
typedef struct No
{
	int valor;
	struct No *anterior, *proximo;
} No;

typedef struct
{
	int tamanho;
	struct No *inicio, *fim;
} Lista;



//sessão de prototipação
void inserirNoInicio(Lista *, int);
void inserirNoFim(Lista *, int);
void removerNoInicio(Lista *);
void removerNoFim(Lista *);
void listarOrdemCrescente(Lista *);
void listarOrdemDecrescente(Lista *);



//função principal
main()
{
	setlocale(LC_ALL, "Portuguese");	
	
	Lista lista;
	lista.tamanho = 0;
	lista.inicio = lista.fim = NULL;
	
	inserirNoInicio(&lista, 10);
	inserirNoInicio(&lista, 20);
	inserirNoInicio(&lista, 30);
	inserirNoFim(&lista, 60);
	inserirNoFim(&lista, 50);
	inserirNoFim(&lista, 40);
	removerNoInicio(&lista);
	removerNoFim(&lista);
	
	listarOrdemCrescente(&lista);
//	listarOrdemDecrescente(&lista);
}



//sessão de funções
void inserirNoInicio(Lista *lista, int elemento)
{
	No *no = (No *) malloc(sizeof(No));
	no -> valor = elemento;
	
	if(lista -> inicio == NULL)
	{
		no -> anterior = NULL;
		no -> proximo  = NULL;
		lista -> inicio = no;
		lista -> fim    = no;
	}
	else
	{
		no -> anterior = NULL;
		no -> proximo = lista -> inicio;
		lista -> inicio -> anterior = no;
		lista -> inicio = no;
	}
	
	lista -> tamanho++;
}

void inserirNoFim(Lista *lista, int elemento)
{
	No *no = (No *) malloc(sizeof(No));
	no -> valor = elemento;
	
	if(lista -> inicio == NULL)
	{
		no -> anterior = NULL;
		no -> proximo  = NULL;
		lista -> inicio = no;
		lista -> fim    = no;
	}
	else
	{
		no -> anterior = lista -> fim;
		no -> proximo  = NULL;
		lista -> fim -> proximo = no;
		lista -> fim = no;
	}
	
	lista -> tamanho++;
}

void removerNoInicio(Lista *lista)
{
	if(lista -> tamanho == 0)
		puts("Não há elementos para remover");
	else if(lista -> tamanho == 1)
	{
		lista -> inicio = NULL;
		lista -> fim    = NULL;	
	}
	else
	{
		No *no = (No *) malloc(sizeof(No));
		no = lista -> inicio -> proximo;
		
		lista -> inicio == NULL;
		no -> anterior = NULL;
		lista -> inicio = no;
	}
}

void removerNoFim(Lista *lista)
{
	if(lista -> tamanho == 0)
		puts("Não há elementos para remover");
	else if(lista -> tamanho == 1)
	{
		lista -> inicio = NULL;
		lista -> fim    = NULL;
	}
	else 
	{
		No *no = (No *) malloc(sizeof(No));
		no = lista -> fim -> anterior;
		
		lista -> fim = NULL;
		no -> proximo = NULL;
		no = lista -> fim;
	}
}

void listarOrdemCrescente(Lista *lista)
{
	No *no = (No *) malloc(sizeof(No));
	no = lista -> inicio;
	int i;
	
	for(i = 0; i < lista -> tamanho; i++)
	{
		printf("%dº: %d\n", i + 1, no -> valor);
		no = no -> proximo;
	}
}

void listarOrdemDecrescente(Lista *lista)
{
	No *no = (No *) malloc(sizeof(No));
	no = lista -> fim;
	int i;
	
	for(i = 0; i < lista -> tamanho; i++)
	{
		printf("%dº: %d\n", i + 1, no -> valor);
		no = no -> anterior;
	}
}
