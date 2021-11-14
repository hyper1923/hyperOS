#include "acpi/acpi.h"
#include "memory/memory.h"
#include "../lib/iostream.h"

extern "C"{
	int _HSTATUS_MAIN(){
		Acpi* acpi = (Acpi*)malloc(-1);
		acpi->Reboot(); //Reboot the system.
		return -1;
	}

}