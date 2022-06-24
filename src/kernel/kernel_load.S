global loader
extern _HSTATUS_MAIN
program:
    incbin "./program.elf"

loader:
call _HSTATUS_MAIN    
cli

