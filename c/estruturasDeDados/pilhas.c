/*
	Name: pilhas.c
	Author: Gustavo Silva Souza
	Date: 10/04/24 09:49
	Description: programa de implementa��o de pilhas em C
*/



//sess�o de bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>



//sess�o de vari�veis globais
int stack[10];
int top = -1;



//sess�o de prototipa��o
void pushStack(int);
void popStack();
void listStack();
int  stackTopElement();
bool stackIsFull();
bool stackIsEmpty();

int binaryConvertion(int);



//fun��o principal
main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int option, element;
	
	while(true)
	{
		system("cls");
		
		puts("(1) Push");
		puts("(2) Pop");
		puts("(3) Listar");
		puts("(4) Encerrar programa\n");
		
		printf("Op��o: ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				printf("Elemento: ");
				scanf("%d", &element);
				pushStack(element);
				break;
			
			case 2:
				popStack();
				break;
				
			case 3:
				listStack();
				break;
				
			case 4:
				exit(0);
				break;
				
			default:
				puts("Valor inv�lido!");
				puts("");
				system("pause");
				break;
		}
	}

//	printf("Bin�rio: %d", binaryConvertion(3));
}



//sess�o de fun��es
void pushStack(int element)
{
	if(stackIsFull())
		puts("A pilha est� cheia");
	else
	{
		top++;
		stack[top] = element;
		puts("Elemento inserido com sucesso!");
	}
	
	puts("");
	system("pause");
}

void popStack()
{
	if(stackIsEmpty())
		puts("A pilha est� vazia");
	else
		top--;
		puts("Elemento removido com sucesso!");
		
	puts("");
	system("pause");
}

void listStack()
{
	int i;
	
	if(stackIsEmpty())
		puts("N�o h� elementos na pilha para serem listados");	
	else
	{
		int i;
		
		for(i = 0; i <= top; i++)
			printf("%d� elemento: %d\n", i + 1, stack[i]);		
	}
	
	puts("");
	system("pause");
}

int stackTopElement()
{
	return stack[top];
}

bool stackIsFull()
{
	return top > 9;
}

bool stackIsEmpty()
{
	return top < 0;
}

//int binaryConvertion(int element)
//{
//	int quociente, resto, total;
//	quociente = resto = total = 0;
//	
//	while(element >= 2)
//	{
//		quociente = element / 2;
//		resto = element - (quociente * 2);
//		pushStack(resto);
//		element = quociente;
//	}
//	
//	while(stackIsFull())
//	{
//		total += stack[top];
//		popStack();
//	}
//	
//	return total;
//}
