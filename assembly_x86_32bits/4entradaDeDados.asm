; sessão utilizada para alocar dados a rótulos que não possuem inicialização de valores
section .bss
  ; resb: reserva um número especificado de bytes
  buffer resb 100
  BUFFER_SIZE equ $ - buffer

section .data
  prompt db 0x10, "A seguir, digite um texto: ", 0x00
  PROMPT_SIZE equ $ - prompt - 1

section .text
  global _start

_start:
  ; imprimir prompt
  mov eax, 4
  mov ebx, 1
  mov ecx, prompt
  mov edx, BUFFER_SIZE
  int 0x80

  ; receber entrada
  mov eax, 3
  mov ebx, 0
  mov ecx, buffer
  mov edx, BUFFER_SIZE
  int 0x80

  ; encerrar programa
  mov eax, 1
  xor ebx, ebx
  int 0x80
