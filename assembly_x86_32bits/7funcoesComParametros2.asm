; este código só funciona em 32 bits, pois a diretiva 'pop' é incompatível com 64 bits



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
  ; nesta segunda forma, você adiciona os parâmetros na pilha stack
  ; sempre que a função for finalizada, você deve remover os rótulos da stack para não causar stack overflow
  ; o push adiciona os 'parãmetros' na pilha
  ; o pop remove eles da pilha
  ; detalhe: pop só consegue remover registradores (não consegue remover rótulos)

  ; exibindo a primeira mensagem
  push msg1
  push msg1_size
  call exibirMensagem
  pop edx ; remove msg1_size
  pop ecx ; remove msg1

  ; exibindo a segunda mensagem
  push msg2
  push msg2_size
  call exibirMensagem
  pop edx ; remove msg2_size
  pop ecx ; remove msg2

  ; exibindo a terceira mensagem
  push msg3
  push msg3_size
  call exibirMensagem
  pop edx ; remove msg3_size
  pop ecx ; remove msg3

  ; exibindo a quarta mensagem
  push msg4
  push msg4_size
  call exibirMensagem
  pop edx ; remove msg4_size
  pop ecx ; remove msg4

  ; exibindo a quinta mensagem
  push msg5
  push msg5_size
  call exibirMensagem
  pop edx ; remove msg5_size
  pop ecx ; remove msg5

  call encerrarPrograma



; sessão de funções
  exibirMensagem:
    ; o registrador 'esp' serve para acessar valores na pilha
    ; ele sempre contém o endereço do valor que está no topo da pilha
    ; utilizei o +4 com 'esp' para acessar o próximo elemento da pilha sem remover o topo

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
