#pragma once
#include "../../hyperOS.h"
#define VGA_MEMORY (char*)0xB8000
#define VGA_WIDTH 80

class CursorPosition {
public:
    int x = 0;
    int y = 0;
    int RawPosition = 0;
    int rawPosition(){
        RawPosition = y * VGA_WIDTH + x;
        return y * VGA_WIDTH + x;
    }
};


class VGA{
public: 
    void SetCursorPosRaw(uint16_t pos){
        if(pos < 2000) {
            Communucation::outb(0x3d4, 0x0f);
            Communucation::outb(0x3d5, (uint8_t)(pos & 0xff));
            Communucation::outb(0x3d4, 0x0e);
            Communucation::outb(0x3d5, (uint8_t)((pos >> 8) & 0xff));
            cursorPosition.RawPosition = pos;
        }
	    return;
    }   


    void printf(const char* _text){
        uint8_t* data = (uint8_t*)_text; 
        for(int i = 0; *data != 0; i++){
            if(*data == '\n'){
                cursorPosition.x = 0;
                cursorPosition.y++;
                SetCursorPosRaw(cursorPosition.rawPosition());
                break;
            } else{
                print_char(*data);
                data++;  
            }
        }
    }
    void print_char(char s)
    {
        cursorPosition.x++;
        *(VGA_MEMORY + cursorPosition.rawPosition() *2) = s;
        *(VGA_MEMORY + cursorPosition.rawPosition() *2 + 1) = 7;
        SetCursorPosRaw(cursorPosition.rawPosition());
    }
private:
    CursorPosition cursorPosition;
};