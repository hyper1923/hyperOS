global loader
extern _HSTATUS_MAIN

loader:
call _HSTATUS_MAIN    
cli

times 2048-($-$$) db 0
dw 0xAA55
