/*
	Name: filas.cpp
	Author: Gustavo Silva Souza
	Date: 03/04/24 09:52
	Description: programa de implementação de filas (FIFO) em C
*/



//sessão de bibliotecas
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>



//sessão de declaração de struts
struct Filas
{
	int inicio, fim, total;
};



//sessão de variáveis globais
Filas fila;
int senhas[5];



//sessão de prototipação
void inserirElementoNaFila(void);
void removerElementoDaFila(void);
void imprimirFila(void);
bool filaEstaCheia(void);
bool filaEstaVazia(void);



//função principal
int main(void)
{
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	int opcao = 0;
	fila.inicio = fila.fim = fila.total = 0;
	
	puts("OPÇÕES\n");
	puts("(1) Inserir elemento");
	puts("(2) Remover elemento");
	puts("(3) Imprimir fila");
	puts("(4) Sair");
	
	printf("\nOpção: ");
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
				puts("\nDigite apenas números válidos!");
				Sleep(3000);
		}
		
		main();
	}
}



//sessão de funções
void inserirElementoNaFila()
{
	int elemento = 0;
	printf("Elemento: ");
	scanf("%i", &elemento);
	
	if(filaEstaCheia())
		puts("A fila está cheia e novos elementos não serão inseridos");
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
		puts("A fila está vazia e não é possível remover elementos");
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
	
	puts("Conteúdo da fila:");
	
//	na condição, não pode ser o total. Precisa ser a quantidade de elementos do array (strlen)
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
