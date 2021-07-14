#pragma once



void Sleep(int milliseconds){
    milliseconds = milliseconds * 100000;
    for(int i = 0; i < milliseconds; i++){
        if(i == milliseconds){
            break;
        }
    }
}