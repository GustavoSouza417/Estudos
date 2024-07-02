//seção de bibliotecas
#include <stdio.h>
#include <pthread.h>
 

 
//seção de prototipação
void somar1(int, int, int *);
void somar2(int, int, int *);
void somar3(int, int, int *);
void execucarSemThread(int *, int *, int *);
void execucarComThread(int *, int *, int *);
 


//função principal
int main()
{
	int resultado1, resultado2, resultado3;
	resultado1 = resultado2 = resultado3 = 0;
	
	//comente alternadamente as funções abaixo e verifique a diferença de tempo de execução entre elas
	execucarSemThread(&resultado1, &resultado2, &resultado3);
	execucarComThread(&resultado1, &resultado2, &resultado3);
	
	printf("resultado1: %d\n", resultado1);
	printf("resultado2: %d\n", resultado2);
	printf("resultado3: %d", resultado3);
	
	return 0;
}
 

 
//seção de funções
void somar1(int a, int b, int *resultado1)
{
	while(*resultado1 <= 1000)
		*resultado1 += a + b;	
}
 
void somar2(int a, int b, int *resultado2)
{
	while(*resultado2 <= 1250)
		*resultado2 += a + b;
}
 
void somar3(int a, int b, int *resultado3)
{
	while(*resultado3 <= 1500)
		*resultado3 += a + b;	
}
 
void execucarSemThread(int *resultado1, int *resultado2, int *resultado3)
{
	somar1(10, 20, resultado1);
	somar2(20, 30, resultado2);
	somar3(30, 40, resultado3);
}
 
void execucarComThread(int *resultado1, int *resultado2, int *resultado3)
{
	pthread_t thread1, thread2, thread3;
	
	pthread_create(&thread1, NULL, somar1(10, 20, resultado1), NULL);
	pthread_create(&thread2, NULL, somar2(20, 30, resultado2), NULL);
	pthread_create(&thread3, NULL, somar3(30, 40, resultado3), NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	
	pthread_exit(NULL);
}
