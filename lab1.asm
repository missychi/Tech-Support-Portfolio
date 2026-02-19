section .data
    sum dd 0

section .text
    global _start

_start:
    mov eax, 20
    mov ebx, 10
    mov ecx, 5
    mov edx, 2
    add eax, ebx
    add ecx, edx
    sub eax, ecx
    mov [sum], eax

    
    mov eax, 60
    xor edi, edi
    syscall