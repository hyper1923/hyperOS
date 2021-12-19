#pragma once
#include "../../hyperOS.h"

#define VGA_MEMORY (char*)0xB8000
#define VGA_WIDTH 80


class ScreenInfo{
public:
    ScreenInfo(){
        
    }
    int SCREEN_X;
    int SCREEN_Y;
}; 


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

    void printInteger(int _data){  
        int rem;
        int ones;
        int tens;
        int hundreds;
        int thousands;
        int tensThousands;

        int size;
        int sizeTester = (int)_data;
        while(sizeTester / 10 > 0){
            sizeTester /= 10;
            size++;
        }
        for (int i = 0; i < 5; i++) 
        {
            rem = _data %10;
            _data = _data /10;

            if(i == 0)
                ones = rem;
            else if(i == 1)
                tens = rem;
            else if(i == 2)
                hundreds = rem;
            else if(i == 3)
                thousands = rem;
            else if(i == 4)
                tensThousands = rem;
        }

        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
                print_char('0' + tensThousands);
                break;
            case 1:
                print_char('0' + thousands);
                break;
            case 2:
                print_char('0' + hundreds);
                break;
            case 3:
                print_char('0' + tens);
                break;
            case 4:
                print_char('0' + ones);
                break;
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