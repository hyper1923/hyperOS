#pragma once

class Communucation{
public:
    static void outb(uint16_t port, uint8_t data){
        asm volatile("outb %0, %1" : : "a"(data), "Nd"(port));
        return;
    }

    static uint8_t inb(uint16_t port){
        uint8_t res;
        asm volatile("inb %1, %0" : "=a"(res) : "Nd"(port));
        return res;
    }
};




class Acpi{
public:
    void Reboot(){
        Communucation::outb(0x64, 0xFE);
        asm volatile("hlt");
        return;
    }

};