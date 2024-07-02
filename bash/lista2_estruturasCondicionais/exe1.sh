#!bin/bash
#1) Script que recebe o nome de um arquivo e remove a sua permissão de gravação

#declaração de variáveis
declare nomeDoArquivo;

#entrada de dados
read -p "A seguir, digite o nome do arquivo: " nomeDoArquivo;

if [ -f $nomeDoArquivo ]; then
  chmod -w $nomeDoArquivo;
  echo "Permissão de gravação removida com sucesso!";
else
  echo "Esse arquivo não existe!";
fi;
