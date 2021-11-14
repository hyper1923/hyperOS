#pragma once
#include "../hyperOS.h"
#include "../kernel/memory/memory.h"


#define nullptr 0
#define NULL 0



namespace std{
    template <typename T>
    class vector{
    public:
        void push_back(T element){
            _size++;
            T* copy = elements;
            elements = (T*)malloc(sizeof(T));
            elements[_size-1] = element;
            for(int i = 0; i < _size - 1; i++){
                elements[i-1] = copy[i];
            } 
            return;
        }

        T& operator[](int _a){
                return elements[_a];
        }

        int size(){
            return _size -1;
        }

    private:
        int _size = 0;
        T* elements;
    }; 
}

