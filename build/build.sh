echo DEBUGGING:
    nasm -f elf32 -o objects/loader.o ../src/kernel/loader.asm; 
    nasm -f elf32 -o objects/multiboot.o ../src/kernel/multiboot.asm; 
    gcc -m32 -o objects/kernel.o -c ../src/kernel/kernel.c -nostdlib -nostartfiles -nodefaultlibs;
echo LINKER:
    ld -T linker.ld -m elf_i386 -o ../isodir/boot/kernel.bin multiboot.o loader.o kernel.o;
echo GRUB ISO CREATOR:
    grub-mkrescue /usr/lib/grub/i386-pc -o x86/iso/hyperOS.iso ../isodir
echo BUILD HAS FINISHED.;
