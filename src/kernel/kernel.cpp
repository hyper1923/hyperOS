#include "kernel.h"


extern "C"{
    int _HSTATUS_MAIN(){
        Kernel *kernel = (Kernel*)malloc(sizeof(Kernel));
        kernel->init();
        return 0;
    }
}