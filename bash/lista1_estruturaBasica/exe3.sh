#!/bin/bash
#3) Ler quatro números quaisquer e mostrar o resultado da média destes números.

#declaração de variáveis
declare numero1;
declare numero2;
declare numero3;
declare numero4;
declare mediaAritmetica;

echo -e "\n\n\nPROGRAMA PARA CALCULAR A MÉDIA ARITMÉTICA DE QUATRO NÚMEROS\n\n";

#entrada de dados
read -p "A seguir, digite o primeiro número: " numero1;
read -p "A seguir, digite o segundo número: " numero2;
read -p "A seguir, digite o terceiro número: " numero3;
read -p "A seguir, digite o quarto número: " numero4;

mediaAritmetica=$(($numero1 + $numero2 + $numero3 + $numero4));
mediaAritmetica=$(echo "scale=2; $mediaAritmetica / 2" | bc);

echo -e "\nMédia: $mediaAritmetica";
