#include "kernel.h"


class data
{
    public:
        int datas;
        int datatwo;
        int datathree;
};


extern "C"{
    int _HSTATUS_MAIN(){
        Kernel kernel; kernel.init();
        data* data_class = (data*)malloc(sizeof(data));
        data_class->datas = 1;
        data_class->datatwo = 5;
        data_class->datathree = 3;
        data* bum = (data*)0x50000;
        std::printIntegerDataLine("Memory Size: ", freeMemory);
        std::printIntegerDataLine("Address of the Integer: " , bum->datas);
		std::printIntegerDataLine("Address of the Integer: " , bum->datatwo);
		std::printIntegerDataLine("Address of the Integer: " , bum->datathree); // TEST OF THE MEMORY
        return 0;
    }
}