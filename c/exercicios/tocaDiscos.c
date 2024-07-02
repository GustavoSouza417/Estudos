//sessão de bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>



//sessão de structs
typedef struct
{
	char discos[5][30];
	int quantidade;
} Pilha;



//sessão de prototipação
void push(Pilha *, char[]);
void pop(Pilha *);
char proximoDisco(Pilha *);
bool pilhaEstaCheia(Pilha *);
bool pilhaEstaVazia(Pilha *);



//função principal
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
	
	push(&pilha, "Ministério Águas Vivas");
	push(&pilha, "Nívea Soares");
	push(&pilha, "Valesca Mayssa");
}



//sessão de funções
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
		puts("Não há discos para remover!");
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
