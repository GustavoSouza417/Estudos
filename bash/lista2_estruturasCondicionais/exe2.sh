#!bin/bash
#2) Script que recebe o nome de um arquivo e, caso o arquivo não tenha nenhum conteúdo, o apaga com a permissão do usuário

#declaração de variáveis
declare nomeDoArquivo;
declare boolApagarArquivo;

#entrada de dados
read -p "A seguir, digite o nome do arquivo: " nomeDoArquivo;

if [ -f $nomeDoArquivo -a -s $nomeDoArquivo ]; then
  echo -e "\nO arquivo existe e está vazio";
  read -p "Você quer apagar o arquivo? (s / n): " boolApagarArquivo;

  if [ $boolApagarArquivo == "s" ]; then
    rm $nomeDoArquivo;
    echo "Arquivo apagado com sucesso!";
  elif [ $boolApagarArquivo == "n" ]; then
    echo "Está bem. O arquivo não será apagado";
  else
    echo "Resposta inválida!";
  fi;

elif [ -f $nomeDoArquivo ]; then
  echo -e "\nO arquivo existe, mas não está vazio";
else
  echo -e "\nO arquivo não existe";
fi;
