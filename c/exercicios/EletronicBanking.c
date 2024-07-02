/*
 - Author: @AsherRen
 - Description: simulation of an eletronic banking in terminal
 - Date: 21/03/2024
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>


struct User
{
    char *email;
    char *senha;
    float saldo;
};


void pegarDados();
void verificarUsuario();
void imprimeCabecalho();
void escolherOperacao();
void verSaldo();
void sacarDinheiros();
void depositarDinheiros();
void trocarSenha();
void encerrarSessao();


struct User bdQuery;
struct User person;

int main()
{
	setlocale(LC_ALL, "portuguese");
	
    bdQuery.email = (char *) calloc(20, sizeof(char));
	strcpy(bdQuery.email, "aopa@gmail.com");
    
	bdQuery.senha = (char *) calloc(10, sizeof(char));
    strcpy(bdQuery.senha, "12345678");
	
    bdQuery.saldo = 0.0f;
    
    
    imprimeCabecalho();
    
    
    pegarDados();
    
    escolherOperacao();
    
    return 0;
}

void imprimeCabecalho()
{
    puts("= = = = = = = = = = = = = = =");
    puts("= ELETRONIC BANKING SYSTEM  =");
    puts("= = = = = = = = = = = = = = =\n");
}

void pegarDados()
{
	person.email = (char *) calloc(10, sizeof(char));
    while(true)
    {
        printf("\nInsira seu email: \n - - > ");
        scanf("%s", person.email);
        
        if(strcmp(person.email, bdQuery.email) == 0)
            break;
        else
            printf("\nEmail incorreto, insira novamente!\n");
    }
    
    person.senha = (char *) calloc(10, sizeof(char));
    while(true)
    {
		printf("\nInsira sua senha: \n - - > ");
        scanf("%s", person.senha);
        
        if(strcmp(person.senha, bdQuery.senha) == 0)
            break;
        else
            printf("\nSenha incorreta, insira novamente!");
    }
    
    person.saldo = 0.0f;
    
    printf("Usuário logado!\n\n");
    system("pause");
}

void escolherOperacao()
{
	system("cls");
    imprimeCabecalho();
	printf("Bem vindo, %s \n\n", person.email);
    
    int opt = 0;
    while(true)
    {
        printf("ESCOLHA UMA OPÇÃO\n");
        printf(
		" 1 - VER SALDO     \n"
		" 2 - SACAR         \n"
		" 3 - DEPOSITAR     \n"
		" 4 - TROCAR SENHA  \n"
		" 5 - SAIR          \n");
        scanf("%d", &opt);
        
        switch(opt)
        {
        	case 1:
        		verSaldo();
        		break;
        		
        	case 2: 
        		sacarDinheiros();
        		break;
        	
        	case 3:
        		depositarDinheiros();
        		break;
        		
        	case 4:
        		trocarSenha();
        		break;
        	
        	case 5: 
        		encerrarSessao();
        		break;
        	
        	default: 
        		escolherOperacao();
        		continue;
		}
    }  
}

void verSaldo()
{
	
	escolherOperacao();
}

void sacarDinheiros()
{
	
	escolherOperacao();
}

void depositarDinheiros()
{
	
	escolherOperacao();
}

void trocarSenha()
{
	
	escolherOperacao();
}

void encerrarSessao()
{
	
	escolherOperacao();
}
