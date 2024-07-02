section .data
    ; em Assembly, não existem variáveis/constantes, mas existem os "rótulos", que servem para fazer coisas semelhantes
    ; minhaMensagem (msg) e tamanhoDaMensagem (len) são rótulos
    ; "db" é o indicador de que uma certa quantidade de bytes não definida será alocada para alguma coisa
    ; "0x00" indica espaço nulo, ou seja, um espaço vazio está sendo definido no final da mensagem
    ; "equ" é a mesma coisa que o "#define" da linguagem C (quando ler "tamanhoDaMensagem", substitui isso pelo valor a frente de "equ")
    ; o "$" é um operador utilizado para definir endereços de memória
    ; o "-", em conjunto com o "minhaMensagem" e o "$" calculam o tamanho da mensagem

    ; declara o rótulo "minhaMensagem" e lhe dá um valor (Alguma mensagem aí)
    minhaMensagem db 'Alguma mensagem aí', 0x00
    
    ; declara o rótulo "tamanhoDaMensagem" e lhe dá o valor equivalente ao comprimento da string "minhaMensagem"
    tamanhoDaMensagem equ $ - minhaMensagem

section .text
    global _start

_start:
    ; fim
    mov eax, 1
    xor ebx, ebx
    int 0x80