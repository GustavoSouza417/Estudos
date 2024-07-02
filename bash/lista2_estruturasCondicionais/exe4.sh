#!bin/bash
#4) É igual ao exercício anterior, contudo utiliza SELECT

#declaração de variáveis
declare nomeDoDiretorio;
declare nomeDoArquivo;

#entrada de dados
read -p "A seguir, digite o nome de um diretório: " nomeDoDiretorio;

if [ -d $nomeDoDiretorio ]; then
  echo "O diretório informado já existe!";
else
  mkdir $nomeDoDiretorio;
  echo "Diretório criado com sucesso!";

  echo -e "\nAgora, a seguir, digite o número que representa o nome do arquivo que você quer inserir dentro do diretório: ";

  select nomeDoArquivo in "a.txt" "b.txt" "c.txt" "d.txt"
    do
      echo "" > $nomeDoArquivo;
      break;
    done

  mv $nomeDoArquivo $nomeDoDiretorio;
  echo -e "\nArquivo criado com sucesso!";
fi;
