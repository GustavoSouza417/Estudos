/*
	Name: pilhas.c
	Author: Gustavo Silva Souza
	Date: 10/04/24 09:49
	Description: programa de implementação de pilhas em C
*/



//sessão de bibliotecas
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>



//sessão de variáveis globais
int stack[10];
int top = -1;



//sessão de prototipação
void pushStack(int);
void popStack();
void listStack();
int  stackTopElement();
bool stackIsFull();
bool stackIsEmpty();

int binaryConvertion(int);



//função principal
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
		
		printf("Opção: ");
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
				puts("Valor inválido!");
				puts("");
				system("pause");
				break;
		}
	}

//	printf("Binário: %d", binaryConvertion(3));
}



//sessão de funções
void pushStack(int element)
{
	if(stackIsFull())
		puts("A pilha está cheia");
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
		puts("A pilha está vazia");
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
		puts("Não há elementos na pilha para serem listados");	
	else
	{
		int i;
		
		for(i = 0; i <= top; i++)
			printf("%dº elemento: %d\n", i + 1, stack[i]);		
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
