#include "../hyperOS.h"

void ___Main(){
	InitializeMemory();
	Kernel kernel;
	kernel.init();
}


extern "C"{
	int _HSTATUS_MAIN(){
		___Main();
		return 0;
	}
}
