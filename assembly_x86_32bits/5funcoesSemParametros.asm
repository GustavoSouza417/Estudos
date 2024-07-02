section .data
  ; esse 0x0D, 0x0A, 0 serve para efetuar quebra de linha
  msg db "Algum texto executado pela função", 0x0D, 0x0A, 0
  msgSize equ $ - msg

section .text
  global _start

_start:
  call exibirMsg
  call exibirMsg
  call exibirMsg
  call exibirMsg
  call exibirMsg

  call encerrarPrograma



; sessão de funções

exibirMsg:
  mov eax, 4
  mov ebx, 1
  mov ecx, msg
  mov edx, msgSize
  int 0x80
  ret ; retorna à linha do código onde a função tinha sido invocada

encerrarPrograma:
mov eax, 1
xor ebx, ebx
int 0x80
