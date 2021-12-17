#pragma once
#include "../hyperOS.h"


class Kernel{
public:
	Acpi* acpi;
	std::vector<Process*> processes;
	void init(){
		std::printf("Kernel init. \n");
		std::printf("r/osdev\n");
		std::printf("r/turkey\n");
		std::printf("r/svihs\n");
		std::printf("r/akagas\n");
		std::printf("r/kgbtr\n");
		std::printf("r/ateistturk\n"); 
		while(true){
			int output = Communucation::inb(0x60);
			switch (output)
			{
			case 0x2a:
				acpi->Reboot();
			default:
				break;
			}
		}
	}
};

