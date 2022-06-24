#pragma once
#include "../hyperOS.h"
#define nullptr 0
#define NULL 0
#define ENDL (const char*)"\n"



namespace std{

    void Sleep(int nanoseconds){
		while(nanoseconds < 1000 * 100){
			nanoseconds++;
		}
	}
    VGA vga_driver;
    void printIn(const char* data){
        vga_driver.printf(data);
    }

    void printInteger(int _data){
        vga_driver.printInteger(_data);
    }

    void printLine(const char *data){
        vga_driver.printf(data);
        vga_driver.printf(ENDL);
    }

    void printIntegerData(const char* data, int _data){
        vga_driver.printf(data);
        vga_driver.printInteger(_data);
    }
    void printIntegerDataLine(const char* data, int _data){
        vga_driver.printf(data);
        vga_driver.printInteger(_data);
        vga_driver.printf(ENDL);
    }

    void printBoolData(const char* data, bool _data){
        if(_data == 1){
            printIn(data);
            printIn("true");
        } else{
            printIn(data);
            printIn("false");
        }
    }

    void printBoolDataLine(const char* data, bool _data){
        if(_data == 1){
            printIn(data);
            printIn("true");
            printIn(ENDL);
        } else{
            printIn(data);
            printIn("false");
            printIn(ENDL);
        }
    }


    template <typename T>
    class vector{
    public:
        void push_back(T element){
            _size++;
            T* copy = elements;
            elements = (T*)kmalloc(_size * sizeof(T));
            elements[_size-1] = element;
            for(int i = 0; i < _size - 1; i++){
                elements[i] = copy[i];
            } 
            return;
        }

        T& operator[](int _a){
            return elements[_a];
        }

        int size(){
            return _size;
        }

    private:
        int _size = 0;
        T* elements = (T*)kmalloc(sizeof(T));
    }; 
}

