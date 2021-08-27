%ifndef SWITCH_TO_PM_ASM
    %define SWITCH_TO_PM_ASM

[bits 16]

switch_to_pm:
    cli                         ; disable interrupts
    lgdt    [gdt_descriptor]    ; load GDT

    mov     eax, cr0            ; set first bit of cr0 to enter protected mode
    or      eax, 0x1
    mov     cr0, eax

    jmp     CODE_SEG:init_pm    ; far jump forces CPU to flush cache

[bits 32]

init_pm:
    mov     ax, DATA_SEG        ; Set all segment registers to protected mode segment
    mov     ds, ax
    mov     ss, ax
    mov     es, ax
    mov     fs, ax
    mov     gs, ax

    mov     ebp, 0x90000        ; Put stack in correct spot
    mov     esp, ebp

    call    BEGIN_PM            ; Start 32-bit code

%endif
