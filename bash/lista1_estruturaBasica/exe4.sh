#!/bin/bash
#4) Calcular a área de um retângulo.

#declaração de variáveis
declare base;
declare altura;
declare area;

echo -e "\n\n\nPROGRAMA QUE CALCULA A ÁREA DE UM RETÂNGULO\n\n";

#entrada de dado
read -p "A seguir, digite o valor da base do retângulo: " base;
read -p "A seguir, digite o valor da altura de um retângulo: " altura;

let area=base*altura;

echo -e "\nÁrea: $area";
