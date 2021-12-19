#pragma once


class Process{
public:
    virtual void Init() {}
    virtual void Loop() {}

    void SetProcessId(int Id){
        processId = Id;
    }

    uint32_t GetProcessId(){
        return processId;
    }
private:
    uint32_t processId = 0;
}; 