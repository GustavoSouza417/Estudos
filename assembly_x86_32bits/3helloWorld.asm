; serve para dizer qual é a arquitetura
bits 32

section .data
    saida db "Hello, World!", 0x00
    SAIDA_TAMANHO equ $ - saida - 1

section .text
    global _start

_start:
    ; exibe mensagem na tela
    mov eax, 4
    mov ebx, 1
    mov ecx, saida
    mov edx, SAIDA_TAMANHO
    int 0x80

    ; finaliza o código
    mov eax, 1
    xor ebx, ebx
    int 0x80