/*

	Descri��o: programa que recebe duas strings e que gera uma terceira string a partir da uni�o das duas anteriores
	Autor:     Gustavo Silva Souza
	Data:      15/11/2023	

*/
 
//se��o de bibliotecas
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <locale.h>
 
 
 
//se��o de sub-rotinas
void geraStringsJuntas(char *strings[3])
{

	strings[2] = (char *) malloc(strlen(strings[0]) + strlen(strings[1]) + 1 * sizeof(char));
	strcpy(strings[2], strings[0]);
	strcat(strings[2], strings[1]);
};
 
void liberadorMemoria(char *strings[3])
{
	for(int i = 0; i < 3; i++)
		free(strings[i]);
};
 
 
 
//fun��o principal
int main()
{
	setlocale(LC_ALL, "Portuguese");
 
	char *strings[3];
	size_t bufferSize;
 
	for(int i = 0; i < 2; i++)
	{
		printf("A seguir, digite o %i� texto: ", i + 1);
		scanf("%zu", &bufferSize);
		strings[i] = (char *) malloc(bufferSize);
		scanf("%s", strings[i]);
	}
 
	geraStringsJuntas(strings);
	printf("-----------------\n\n%s", strings[2]);
	liberadorMemoria(strings);
 
	return 0;
}
 