echo COMPILING:
    gcc -c ./main.c -o objects/main.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -m32
echo LINKER:
    ld -T linker.ld -m elf_i386

