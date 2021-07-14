#pragma once
#include "../drivers/vga.h"
#include "../drivers/keyboard.h"
#include "../etc/typedef.h"





void Listen_Keyboard(){
    int out = inb(KEYBOARD_PORT);
    const char output = ""; 
    char output2 = "A";

    if(out == KEY_Q) print("Q");
    if (out == KEY_E) print("E");
    if (out == KEY_R) print("R");
    if(out == KEY_T) print("T");
    if(out == KEY_Y) print("Y");
    if(out == KEY_U) print("U");
    if(out == KEY_O) print("O");
    if(out == KEY_A) print("A");
    if(out == KEY_S) print("S");
    if (out == KEY_D) print("D");
    if(out == KEY_F) print("F");
    if(out == KEY_P) print("P");
    if(out == KEY_G) print("G");
    if(out == KEY_H) print("H");
    if(out == KEY_J) print("J");
    if(out == KEY_K)print("K");
    if(out == KEY_L)print("L");
    if(out == KEY_I)print("I");
    if(out == KEY_Z)print("Z");
    if(out == KEY_X)print("X");
    if(out == KEY_C)print("C");
    if(out == KEY_V)print("V");
    if(out == KEY_B)print("B");
    if(out == KEY_N)print("N");
    if(out == KEY_M)print("M");
    if(out == KEY_SPACE)print(" ");


    if(out == KEY_ENTER){
        cls();
        FillScreen(0x0F);
        ColLine(0,0X1F);
        SetCursorPos(0,0);
        print("HyperDOS");
        ColLine(24,0X1F);
        SetCursorPos(0,24);
        print("Insert Command: ");
    }


}


void SYSTEM(){
    cls();
    FillScreen(0x0F);
    ColLine(0,0X1F);
    SetCursorPos(0,0);
    print("HyperDOS");
    ColLine(24,0X1F);
    SetCursorPos(0,24);
    print("Insert Command: ");


    while (1)
    {
        Sleep(50);
        Listen_Keyboard();
    }
    
}
