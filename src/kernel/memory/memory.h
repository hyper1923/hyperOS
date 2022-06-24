#pragma once
#include "../../hyperOS.h"


#define FREE_MEMORY 0x10000
int freeMemory = FREE_MEMORY;


void InitializeMemory(){
    freeMemory = FREE_MEMORY;
}

void* kmemset(void* dest, unsigned char val, int count){
    unsigned char* destC = (unsigned char*)dest;
    int i;
    for(i = 0; i< count; i++){
        destC[i] = val;
    }
    return dest;
}


void* kmalloc(int size){
    kmemset((void*)freeMemory,0,size);
    void* address = (void*)freeMemory;
    freeMemory += size;
    return address;
}

