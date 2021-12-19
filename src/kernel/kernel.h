#pragma once
#include "../hyperOS.h"



class Windows : public Process{
public:
	void Init(){
		std::printLine("Hello World from Windows 12!");
	}

	void Loop(){
		
		std::printLine("Hello World from Windows 12!");
	}
};


class KernelPanic : public Process{
public:
	bool GiveError(int ErrorType, const char* Message){
		std::printLine("Kernel Panic!");
		while (true)
		{
			/* code */
		}
		
		return true;
	}
};

class Kernel{
public:
	Acpi* acpi;
	ProcessManager* processManager;

	void init(){
		std::SYSTEM::KernelPrint("Starting kernel...");
		LoadModules();
		processManager->AddProcess(Windows());
		processManager->AddProcess(KernelPanic());
		std::SYSTEM::KernelPrint("Started kernel.");
		sysBootedUp = true;
		std::printLine((const char*)processManager);
		while (sysBootedUp)
		{
			/* code */
			processManager->Loop();
		}
	}


	bool LoadModules(){
		std::SYSTEM::KernelPrint("Loading modules...");
		acpi = (Acpi*)malloc(sizeof(Acpi));
		processManager = (ProcessManager*)malloc(sizeof(ProcessManager));
		processManager->Init();
		std::SYSTEM::KernelPrint("Loaded modules.");
		return true;
	}

	protected:
		bool sysBootedUp = false;
};

