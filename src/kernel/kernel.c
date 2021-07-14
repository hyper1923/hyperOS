#include "../drivers/port-io.h"
#include "../etc/colours.h"
#include "../drivers/keyboard.h"
#include "../drivers/vga.h"
#include "../drivers/sleep.h"
#include "../operating system/system.h"



void Test_Keyboard(){
	int recv = inb(KEYBOARD_PORT); // ;; Receive data from Keyboard Port

	switch (recv)
	{
	case KEY_A:
		show_text("A key.",BLUE);
		break;
	case KEY_B:
		show_text("B key.",BLUE);
		break;
	case KEY_ENTER:
		cls();
		show_text("Shutdown NOW!",BLUE);
		break;

	}
}



void Welcome(){
	disable_cursor();
	FillScreen(175);
	show_text("Welcome!",RED);
}

void _HSTATUS_MAIN(){
	SYSTEM();
}	