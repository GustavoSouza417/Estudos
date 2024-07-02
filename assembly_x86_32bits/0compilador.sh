#!bin/bash

declare nomeArquivo;
read -p "Nome: " nomeArquivo;

if [ -f $nomeArquivo.o ]; then
  rm $nomeArquivo.o;
fi;

if [ -f $nomeArquivo ]; then
  rm $nomeArquivo;
fi;

nasm -f elf64 -o $nomeArquivo.o $nomeArquivo.asm;
ld $nomeArquivo.o -o $nomeArquivo;

clear;
./$nomeArquivo;
echo -e "\n";
