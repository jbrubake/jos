; A boot sector that enters 32-bit protected mode
[org 0x7c00] ; MBR offset

KERNEL_OFFSET equ 0x1000

    mov     [BOOT_DRIVE], dl

    mov     bp, 0x9000      ; set the stack
    mov     sp, bp

    mov     si, MSG_REAL_MODE
    call    printstr16

    call    load_kernel

    call    switch_to_pm    ; never returns

    jmp     $               ; just in case

%include "printstr16.asm"
%include "diskload.asm"
%include "gdt.asm"
%include "switch_to_pm.asm"

[bits 16]

load_kernel:
    mov     si, MSG_LOAD_KERNEL
    call    printstr16

    mov     bx, KERNEL_OFFSET
    mov     dh, 15
    mov     dl, [BOOT_DRIVE]
    call    diskload

    ret

[bits 32]

BEGIN_PM:
    call    KERNEL_OFFSET

    jmp     $

; Global variables
BOOT_DRIVE      db 0
MSG_REAL_MODE:  db "Started in 16-bit Real Mode", 0x0a, 0x0d, 0
MSG_PROT_MODE:  db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL: db "Loading kernel...", 0

; MBR padding
    times   510-($-$$) db 0
    dw      0xaa55
