#include "acpi/acpi.h"
#include "memory/memory.h"
#include "../lib/iostream.h"
#include "process/process.h"


class Kernel{
public:
	Acpi* acpi;
	std::vector<Process*> processes;
};



extern "C"{
	int _HSTATUS_MAIN(){
		Kernel* kernel = (Kernel*)malloc(sizeof(Kernel));
		Process* console = (Process*)malloc(sizeof(console));
		kernel->processes.push_back(console);
		kernel->acpi = (Acpi*)malloc(sizeof(Acpi*));
		kernel->acpi->Reboot();
		return 123;
	}
}
