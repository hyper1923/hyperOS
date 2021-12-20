ENTRY(loader)

INPUT(
	objects/kernel_load.o
	objects/multiboot.o
	objects/kernel.o
	objects/vfs.o
)

OUTPUT(
	../isodir/boot/kernel.elf
)


SECTIONS{


	. = 0x8000;

	.boot : ALIGN(0x1000)
	{
		KEEP(*(.multiboot_header))
	}
	.text : ALIGN(0x1000){
		*(.text)
	}


}