#pragma once
#include "../hyperOS.h"
#include "fs/vfs.h"

class Windows : public Process{
public:
	void Init(){
		//NULL
	}

	void Loop(){
		//NULL
	}
};


class KernelPanic : public Process{
public:
	bool GiveError(){
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
	VFS* vfs;

	void init(){
		std::printLine("Initializing Memory.");
		InitializeMemory();
		std::printLine("Starting kernel...");
		LoadModules();
		processManager->AddProcess(Windows());
		processManager->AddProcess(KernelPanic());
		std::printLine("Started kernel.");
		sysBootedUp = true;
	}


	bool LoadModules(){
		std::printLine("Loading modules...");
		acpi = (Acpi*)malloc(sizeof(Acpi));
		vfs = (VFS*)malloc(sizeof(VFS));
		vfs->InitVFS();
		processManager = (ProcessManager*)malloc(sizeof(ProcessManager));
		processManager->Init();
		std::printLine("Loaded modules.");
		return true;
	}

	protected:
		bool sysBootedUp = false;
};

