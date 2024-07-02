section .data
  msg1 db "Primeira mensagem", 0x0D, 0x0A, 0
  msg1_size equ $ - msg1

  msg2 db "Segunda mensagem",  0x0D, 0x0A, 0
  msg2_size equ $ - msg2

  msg3 db "Terceira mensagem", 0x0D, 0x0A, 0
  msg3_size equ $ - msg3

  msg4 db "Quarta mensagem",   0x0D, 0x0A, 0
  msg4_size equ $ - msg4

  msg5 db "Quinta mensagem",   0x0D, 0x0A, 0
  msg5_size equ $ - msg5



section .text
  global _start



_start:
  ; essa forma de passagem de parâmetros não é exatamente uma passagem de parâmetros
  ; basicamente, você dá um valor para o registrador antes de entrar na função

  mov ecx, msg1
  mov edx, msg1_size
  call exibirMensagem

  mov ecx, msg2
  mov edx, msg2_size
  call exibirMensagem

  mov ecx, msg3
  mov edx, msg3_size
  call exibirMensagem

  mov ecx, msg4
  mov edx, msg4_size
  call exibirMensagem

  mov ecx, msg5
  mov edx, msg5_size
  call exibirMensagem

  call encerrarPrograma



; sessão de funções

exibirMensagem:
  mov eax, 4
  mov ebx, 1
  int 0x80
  ret

encerrarPrograma:
  mov eax, 1
  xor ebx, ebx
  int 0x80
