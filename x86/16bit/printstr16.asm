%ifndef PRINTSTR16_ASM
    %define PRINTSTR16_ASM

printstr16:
; print the null-terminated string located at si

    push    si
.nextch:
    cmp     byte [si], 0
    jz      .end
    mov     al, byte [si]
    mov     ah, 0x0e
    int     0x10
    lea     si, [si+1]
    jmp     .nextch
.end:
    pop     si
    ret

%endif
