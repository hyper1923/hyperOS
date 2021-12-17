#include "../hyperOS.h"

void InitKernel(){
	initializeMemory();
	Kernel* kernel = (Kernel*)malloc(sizeof(Kernel));
	kernel->init();
}


extern "C"{
	int _HSTATUS_MAIN(){
		InitKernel();
		return 0;
	}
}
