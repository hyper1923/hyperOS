echo DEBUGGING:
    nasm -f elf32 -o objects/kernel_load.o ../src/kernel/kernel_load.asm; 
    nasm -f elf32 -o objects/multiboot.o ../src/boot/multiboot.asm; 
    gcc -c ../src/kernel/kernel.cpp -o objects/kernel.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -m32
    gcc -c ../src/kernel/fs/vfs.cpp -o objects/vfs.o -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -m32
echo LINKER:
    ld -T linker.ld -m elf_i386
echo GRUB ISO CREATOR:
    grub-mkrescue /usr/lib/grub/i386-pc -o x86/iso/hyperOS.iso ../isodir
echo RUNNING.;
    qemu-system-i386 x86/iso/hyperOS.iso
