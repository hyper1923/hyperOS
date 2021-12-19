#pragma once
#define KB 1000

class VFS{
public:
    bool InitVFS(){
        files = (char*)malloc(KB * 10);
        std::printLine("Virtual File System init.");
        return true;
    }


    bool AddFile(char* data){
        __size++;
        if(files[__size] == 0){
            *(files + __size) = *data;
            return true;
        }
        return false;
    }

protected:
    char* files;
    uint32_t size = 0;
    int __size = 0;

};