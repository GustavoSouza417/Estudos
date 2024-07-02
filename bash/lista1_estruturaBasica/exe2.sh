#!/bin/bash
#2) Ler três números quaisquer e mostrar o resultado da soma destes números.

#declaração de variáveis
declare numero1;
declare numero2;
declare numero3;
declare soma;

echo -e "\n\n\nPROGRAMA QUE SOMA TRÊS NÚMEROS\n\n";

#entrada de dados
read -p "A seguir, digite o primeiro número: " numero1;
read -p "A seguir, digite o segundo número: " numero2;
read -p "A seguir, digite o terceiro número: " numero3;

let soma=numero1+numero2+numero3;

echo -e "\nResultado da soma: $soma";
