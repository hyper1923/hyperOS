#pragma once
#include "../hyperOS.h"



class ProcessManager{
public:

    bool Init(){
        std::printLine("Process Manager has started.");
        return true;
    }

    std::vector<Process*> processList;
    bool debugMode = false;
    template <typename T>
    void AddProcess(T t){
        processList.push_back(&t);
        t.SetProcessId(processList.size());
        if(debugMode == true){
            std::printIntegerDataLine("Process added by SYSTEM: ", t.GetProcessId());
            std::printIntegerDataLine("Free Memory: ", freeMemory);
        }
        t.Init();
    }

    void Loop(){
        for(int i = 0 ; i < processList.size(); i++){
            processList[i]->Loop();
        }
    }
};