; esse ponto e vírgula indica "comentário"

; sessão responsável pela declaração de variáveis e constantes
section .data

; sessão responsável por indicar que "_start" é onde o programa inicia
section .text
    global _start

; sessão responsável pelo código em si do programa
_start:
    ; são as três linhas que finalizam qualquer código Assembly (NASM)
    mov eax, 1
    xor ebx, ebx
    int 0x80