#pragma once
#include "../hyperOS.h"
#include "fs/vfs.h"

class Kernel{
public:
	Acpi* acpi;
	VFS* vfs;

	void init(){
		std::printLine("Initializing Memory.");
		InitializeMemory();
		std::printLine("Starting kernel...");
		LoadModules();
		std::printLine("Started kernel.");
		sysBootedUp = true;
	}


	bool LoadModules(){
		std::printLine("Loading modules...");
		acpi = (Acpi*)malloc(sizeof(Acpi));
		vfs = (VFS*)malloc(sizeof(VFS));
		vfs->InitVFS();
		std::printLine("Loaded modules.");
		return true;
	}

	protected:
		bool sysBootedUp = false;
};

