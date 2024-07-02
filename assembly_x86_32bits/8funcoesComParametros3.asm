section .data
  msg1 db "Um",     0x0D, 0x0A, 0
  msg1_size equ $ - msg1

  msg2 db "Dois",   0x0D, 0x0A, 0
  msg2_size equ $ - msg2

  msg3 db "Três",   0x0D, 0x0A, 0
  msg3_size equ $ - msg3

  msg4 db "Quatro", 0x0D, 0x0A, 0
  msg4_size equ $ - msg4

  msg5 db "Cinco",  0x0D, 0x0A, 0
  msg5_size equ $ - msg5



section .text
  global _start



_start:
  ; essa forma é igual a anterior, contudo ao invés de usar pop, usa outro método para remover elementos da pilha
  ; simplesmente, você não remove elementos da pilha, mas altera o endereço inicial da pilha para outro endereço
  ; assim, você pode deslocar a pilha para uma região onde não há nenhum parâmetro alocado

  ; exibe a primeira mensagem
  push msg1
  push msg1_size
  call exibirMensagem  
  add esp, 8 ; desloca a pilha 8 bytes para sair da referência dos dois parâmetros anteriores (soma 8 bytes no endereço da pilha)

  ; exibe a segunda mensagem
  push msg2
  push msg2_size
  call exibirMensagem
  add esp, 8

  ; exibe a terceira mensagem
  push msg3
  push msg3_size
  call exibirMensagem
  add esp, 8

  ; exibe a quarta mensagem
  push msg4
  push msg4_size
  call exibirMensagem
  add esp, 8

  ; exibe a quinta mensagem
  push msg5
  push msg5_size
  call exibirMensagem
  add esp, 8

  call encerrarPrograma
; fim do programa



; sessão de funções
  ; função que exibe uma mensagem passada por parâmetro
  exibirMensagem:
    mov eax, 4
    mov ebx, 1
    mov ecx, [esp + 4]
    mov edx, [esp]
    int 0x80
    ret

  encerrarPrograma:
    mov eax, 1
    xor ebx, ebx
    int 0x80