#!/bin/bash
#1) Calcular e mostar a metade de um número qualquer informado pelo usuário.

#declaração de variáveis
declare numero;

echo -e "\n\n\nATENÇÃO! Este programa não funcionará se você não tiver o BC instalado!\n\n";
echo -e "PROGRAMA QUE CALCULA A METADE DE UM NÚMERO\n";

#entrada de dados
read -p "A seguir, digite um número: " numero;

numero=$(echo "scale=2; $numero / 2" | bc);
echo -e "\nResultado: $numero";
