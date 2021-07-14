#pragma once
#include "../etc/typedef.h"
#include "sleep.h"
#include "port-io.h" 

#define VGA_TEXT_MODE 0xB8000
#define VGA_GRAPHIC_MODE 0xA8000
#define VGA_WIDTH 80


uint16_t CursorPos = 0; 

void SetCursorPosRaw(uint16_t pos){
	if(pos >= 0 && pos < 2000) {
		outb(0x3d4, 0x0f);
		outb(0x3d5, (uint8_t)(pos & 0xff));
		outb(0x3d4, 0x0e);
		outb(0x3d5, (uint8_t)((pos >> 8) & 0xff));
		CursorPos = pos;
	}
	return;
}


void SetCursorPos(int x, int y){
	uint16_t pos;

			pos = y * VGA_WIDTH + x;
			SetCursorPosRaw(pos);
	return;
}


void show_text(const char* text,int colour){
    char* mem = (char*)VGA_TEXT_MODE;
    while(*text){
        *mem++ = *text++;
        *mem++ = colour;
    }
    SetCursorPos(0,CursorPos + 1);
}


void ColLine(int line, int col){
	for(int i = (int)VGA_TEXT_MODE + VGA_WIDTH * 2 * line + 1;
	i < (int)VGA_TEXT_MODE + VGA_WIDTH * 2 * (line + 1) + 1; i += 2)  * ((char*)i) = col;
		
}

void disable_cursor()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}



void FillScreen(int vgaColor){
    cls();
	for(int i = 0; i < 25; i++){
		Sleep(5);
		ColLine(i,vgaColor);
	}	
}






void cls(){
    char* mem = (char*)VGA_TEXT_MODE;
    int i = 0;
    while(i < 88 * 25 * 2){
        mem[i++] = 0;
    }
}


void ClearOnce(){
	char* currentPos = (char*)VGA_TEXT_MODE;
	uint16_t i = CursorPos;
	*(currentPos + i * 2) = 0;
}


void print(const char* text){
	char* currentPos = (char*)VGA_TEXT_MODE;
	uint16_t i = CursorPos;
    while(*text){
        *(currentPos + i * 2) = *text++;
		//*(currentPos + i * 2 + 1) = 0;
		i++;
    }

	SetCursorPosRaw(i);

}


