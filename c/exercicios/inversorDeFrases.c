/*
	Descrição: programa que recebe uma frase e a inverte ao contrário
	Autor:     Gustavo Silva Souza
	Data:      15/11/2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

//sub-rotinas
void inversorFrases(char *frase, char **fraseInvertida)
{
	short a = 0;

	(*fraseInvertida) = (char *) malloc(strlen(frase) + 1 * sizeof(char));

	for(short i = strlen(frase); i != 0; i--)
	{
		(*fraseInvertida)[a] = frase[i - 1];
		a++; 
	}
};

void liberadorMemoria(char *frase, char *fraseInvertida)
{
	free(frase);
	free(fraseInvertida);
};

int main()
{
	setlocale(LC_ALL, "Portuguese");

	char *frase, *fraseInvertida;
	size_t bufferSize;

	printf("A seguir, digite alguma frase: ");
	scanf("%zu", &bufferSize);
	frase = (char *) malloc(bufferSize + 1);
	scanf(" %[^\n]", frase);

	inversorFrases(frase, &fraseInvertida);

	printf("%s", fraseInvertida);

	liberadorMemoria(frase, fraseInvertida);

	return 0;
};
