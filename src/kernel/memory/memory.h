#pragma once
#include "../../hyperOS.h"


class MemoryManager{
public:
    void* memset(void* destination , unsigned char value, int count){
        
    }
private:
    int freeMemory;
    int maxMemory;
};

#define FREE_MEMORY 0x10000
int freeMemory = FREE_MEMORY;


void InitializeMemory(){
    freeMemory = FREE_MEMORY;
}

void* memset(void* dest, unsigned char val, int count){
    unsigned char* destC = (unsigned char*)dest;
    int i;
    for(i = 0; i< count; i++){
        destC[i] = val;
    }
    return dest;
}


void* malloc(int size){
    memset((void*)freeMemory,0,size);
    void* address = (void*)freeMemory;
    freeMemory += size;
    return address;
}

