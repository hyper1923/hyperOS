#pragma once
#include "../hyperOS.h"
#include "../kernel/memory/memory.h"

template <typename T>
class vector{
public:
    void push_back(T element){
        size++;
        T* copy = elements;
        elements = (T*)malloc(sizeof(T));
        elements[size-1] = element;
        for(int i = 0; i < size - 1; i++){
            elements[i-1] = copy[i];
        } 
        return;
    }

    T* operator[](int _a){
        return elements[_a]; 
    }

private:
    unsigned int size = 0;
    T* elements;
};