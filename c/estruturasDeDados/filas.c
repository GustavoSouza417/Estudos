/*
	Name: filas.cpp
	Author: Gustavo Silva Souza
	Date: 03/04/24 09:52
	Description: programa de implementa��o de filas (FIFO) em C
*/



//sess�o de bibliotecas
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>



//sess�o de declara��o de struts
struct Filas
{
	int inicio, fim, total;
};



//sess�o de vari�veis globais
Filas fila;
int senhas[5];



//sess�o de prototipa��o
void inserirElementoNaFila(void);
void removerElementoDaFila(void);
void imprimirFila(void);
bool filaEstaCheia(void);
bool filaEstaVazia(void);



//fun��o principal
int main(void)
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	int opcao = 0;
	fila.inicio = fila.fim = fila.total = 0;
	
	puts("OP��ES\n");
	puts("(1) Inserir elemento");
	puts("(2) Remover elemento");
	puts("(3) Imprimir fila");
	puts("(4) Sair");
	
	printf("\nOp��o: ");
	scanf("%i", &opcao);
	
	while(true)
	{
		switch(opcao)
		{
			case 1:
				inserirElementoNaFila();
				break;
				
			case 2:
				removerElementoDaFila();
				break;
				
			case 3:
				imprimirFila();
				break;
				
			case 4:
				exit(1);
				break;
				
			default:
				puts("\nDigite apenas n�meros v�lidos!");
				Sleep(3000);
		}
		
		main();
	}
}



//sess�o de fun��es
void inserirElementoNaFila()
{
	int elemento = 0;
	printf("Elemento: ");
	scanf("%i", &elemento);
	
	if(filaEstaCheia())
		puts("A fila est� cheia e novos elementos n�o ser�o inseridos");
	else
	{
		senhas[fila.fim] = elemento;
		fila.fim = (fila.fim + 1) % 5;
		fila.total++;
	}
}

void removerElementoDaFila(void)
{
	if(filaEstaVazia())
		puts("A fila est� vazia e n�o � poss�vel remover elementos");
	else
	{
		int elemento = senhas[fila.inicio];
		fila.inicio = (fila.inicio + 1) % 5;
		fila.total--;
	}
}

void imprimirFila(void)
{
	int i, contador;
	
	puts("Conte�do da fila:");
	
//	na condi��o, n�o pode ser o total. Precisa ser a quantidade de elementos do array (strlen)
	for(i = 0, contador = fila.inicio; contador < fila.total; contador++)
	{
		printf("%i\n", senhas[i++]);
		
		if(i == 5)
			i = 0;	
	}
}

bool filaEstaCheia(void)
{
	return fila.total == 5;
}

bool filaEstaVazia(void)
{
	return fila.total == 0;
}
