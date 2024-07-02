#!/bin/bash
#3) Script que obtém o nome de um diretório e verifica se ele existe. Caso o diretório já exista, o script retorna uma mensagem de erro. Caso contrário, cria um diretório com tal nome com um arquivo dentro, com um nome a ser definido entre quatro opções que o script fornece

#declaração de variáveis
declare nomeDoDiretorio;
declare nomeDoArquivo;
declare opcao;

#entrada de dados
read -p "A seguir, digite o nome do diretório: " nomeDoDiretorio;

if [ -d $nomeDoDiretorio ]; then
  echo "Esse diretório já existe!";
else
  mkdir $nomeDoDiretorio;
  echo -e "Diretório criado com sucesso!\n";

  echo -e "Digite o número correspondente ao nome do arquivo que será criado dentro do diretório criado por você\n";

  echo "1) a.txt";
  echo "2) b.txt";
  echo "3) c.txt";
  echo -e "4) d.txt\n";

  read -p "Opção: " opcao;

  case $opcao in
    1)
      echo "" > a.txt;
      mv a.txt $nomeDoDiretorio;
      echo "Arquivo a.txt criado com sucesso!";
    ;;

    2)
      echo "" > b.txt;
      mv b.txt $nomeDoDiretorio;
      echo "Arquivo b.txt criado com sucesso!";
    ;;

    3)
      echo "" > c.txt;
      mv c.txt $nomeDoDiretorio;
      echo "Arquivo c.txt criado com sucesso!";
    ;;

    4)
      echo "" > d.txt;
      mv d.txt $nomeDoDiretorio;
      echo "Arquivo d.txt criado com sucesso!";
    ;;

    *)
      echo "Valor inválido!";
    ;;
  esac;
fi;
