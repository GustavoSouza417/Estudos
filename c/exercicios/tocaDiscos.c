//sess�o de bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>



//sess�o de structs
typedef struct
{
	char discos[5][30];
	int quantidade;
} Pilha;



//sess�o de prototipa��o
void push(Pilha *, char[]);
void pop(Pilha *);
char proximoDisco(Pilha *);
bool pilhaEstaCheia(Pilha *);
bool pilhaEstaVazia(Pilha *);



//fun��o principal
main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Pilha pilha;
	pilha.quantidade = 0;
	
	push(&pilha, "FHOP");
	push(&pilha, "Gabriel Guedes");
	push(&pilha, "Gabriela Rocha");
	push(&pilha, "Laura Souguellis");
	push(&pilha, "Morada");
	
	pop(&pilha);
	pop(&pilha);
	
	push(&pilha, "Minist�rio �guas Vivas");
	push(&pilha, "N�vea Soares");
	push(&pilha, "Valesca Mayssa");
}



//sess�o de fun��es
void push(Pilha *pilha, char nomeDisco[])
{
	if(pilhaEstaCheia(pilha))
		puts("Limite de discos atingido!");
	else
	{
		strcpy(pilha -> discos[pilha -> quantidade], nomeDisco);
		printf("Disco inserido: %s\n", pilha -> discos[pilha -> quantidade++]);
	}
}

void pop(Pilha *pilha)
{
	if(pilhaEstaVazia(pilha))
		puts("N�o h� discos para remover!");
	else
		printf("Disco removido: %s\n", pilha -> discos[pilha -> quantidade--]);
}

bool pilhaEstaCheia(Pilha *pilha)
{
	return pilha -> quantidade == 5;
}

bool pilhaEstaVazia(Pilha *pilha)
{
	return pilha -> quantidade == 0;
}
