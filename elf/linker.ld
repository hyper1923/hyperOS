ENTRY(_main)

INPUT(
    objects/main.o
)

OUTPUT(
	../build/program.elf
)


SECTIONS{


	. = 0x8000;

}