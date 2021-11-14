global loader
extern _HSTATUS_MAIN
MAGIC equ 0x1badb002
FLAGS equ 0x3
CHECKSUM equ -(MAGIC+FLAGS)

section .text
align 4
dd MAGIC
dd FLAGS
dd CHECKSUM

loader:
call _HSTATUS_MAIN    
cli

quit:
hlt
jmp quit

times 2048-($-$$) db 0
dw 0xAA55
