#!bin/bash

echo -e "\n";
sudo apt update;

echo -e "\n";
sudo apt install nasm;

echo -e "\n";
sudo apt install binutils;

echo -e "\n";
nasm -v;

echo -e "\n";
ld -v;

echo -e "\n";
