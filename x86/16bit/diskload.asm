%ifndef DISKLOAD_ASM
    %define DISKLOAD_ASM

diskload:
; load dh sectors to es:bx from drive dl

    push    ax
    push    cx

    push    dx          ; store dx on stack so later we can recall
                        ; how many sectors were request to be read,
                        ; even if it is altered in the meantime

    mov     ah, 0x02    ; BIOS read sector function
    mov     al, dh      ; read dh sectors
    mov     ch, 0x00    ; select cylinder 0
    mov     dh, 0x00    ; select head 0
    mov     cl, 0x02    ; start reading from second sector (i.e. after the boot sector)
    int     0x13        ; BIOS interrupt

    jc      .error      ; jump if error (i.e. carry flag set)
    pop     dx          ; restore dx from the stack
    cmp     dh, al      ; if al (sectors read) != dh (sectors expected)
    jne     .error      ;  display error message

    pop     cx
    pop     ax
    ret

.error:
    mov     si, DISK_ERROR_MSG
    call    printstr16
    jmp     $


DISK_ERROR_MSG: db "Disk read error!", 0x0a, 0x0d, 0

%endif
