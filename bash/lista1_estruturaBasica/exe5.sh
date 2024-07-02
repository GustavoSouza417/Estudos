#!/bin/bash
#5) Calcular a área de um círculo

#declaração de variáveis
declare raio;
declare area;

echo -e "\n\n\nPROGRAMA QUE CALCULA A ÁREA DE UM CÍRCULO\n\n";

#entrada de dados
read -p "A seguir, digite o valor do raio do círculo: " raio;

area=$(echo "scale=2; 3.14 * ($raio * $raio)" | bc);

echo -e "\nÁrea: $area";


