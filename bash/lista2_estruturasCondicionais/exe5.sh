#!bin/bash
#5) - Recebe o nome de um arquivo;
### - Se o arquivo já existir e o usuário tiver permissão de gravação, renomeia o arquivo para a extensão .bak;
### - Se o arquivo com a extensão .bak já existir, o delete e crie um novo;
### - Abra o arquivo com o Nano;
### - Verificar se há conteúdo no arquivo;
### - Se não houver conteúdo no arquivo, pergunte ao usuário se ele quer recuperar o arquivo;
### - Se o usuário quiser recuperar o arquivo, renomeio novamente.

#declaração de variáveis
declare nomeOriginalDoArquivo;
declare nomeDoArquivoPuro;
declare usuarioAtual;
declare opcao;

#atribuição de variável
usuarioAtual=$(whoami);

#entrada de dados e outra atribuição de variável
read -p "A seguir, digite o nome do arquivo: " nomeOriginalDoArquivo;
nomeDoArquivoPuro=$(basename $nomeOriginalDoArquivo | awk -F. '{print $1}');

#verificando se o arquivo existe
if [ -f $nomeOriginalDoArquivo ]; then
  echo "Esse arquivo existe";

  #verificando se o arquivo permite gravação
  if [ -w $nomeOriginalDoArquivo ]; then
    echo "Esse arquivo permite gravação de dados";

    #verificando se o usuário tem permissão de gravação neste arquivo
    if [ $(stat -c %U $nomeOriginalDoArquivo) = $usuarioAtual ]; then
      echo "Você tem permissão para gravar dados nesse arquivo";

      #verificando se o .bak já existe
      if [ -f "$nomeDoArquivoPuro.bak" ]; then
        echo "O arquivo .bak já existe!";
        rm "$nomeDoArquivoPuro.bak";
      else
        echo "O arquivo .bak não existe!";
      fi;
    else
      echo "Você não tem permissão para gravar dados neste arquivo!";
      exit;
    fi;
  else
    echo "O arquivo descrito não tem permissão de gravação!";
    exit;
  fi;
else
  echo "Este arquivo não existe!";
  exit;
fi;

mv $nomeOriginalDoArquivo "$nomeDoArquivoPuro.bak";
echo -e "\nAbrindo arquivo... Aguarde...";
sleep 3;
nano "$nomeDoArquivoPuro.bak";

if [ -s "$nomeDoArquivoPuro.bak" ]; then
   echo -e "\nO arquivo contém conteúdo";
else
  read -p -e "\nO arquivo está vazio. Você quer recuperar o arquivo? (y/n)" opcao;

  if [ $opcao = "y" ]; then
    echo -e "\nDigite um nome, que também contenha a extensão, para renomear o arquivo";
    read -p "Nome: " $nomeOriginalDoArquivo;
    mv "$nomeDoArquivoPuro.bak" $nomeOriginalDoArquivo;
    echo -e "\nArquivo renomeado com sucesso!";

  elif [ $opcao = "n" ]; then
    echo -e "\nEstá bem. O arquivo não será recuperado";

  else
    echo -e "\nValor inválido!";
  fi;
fi;
