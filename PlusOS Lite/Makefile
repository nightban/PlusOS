all:
	nasm -f elf32 boot/boot.asm -o build/boot.o
	gcc -m32 -ffreestanding -c kernel/kernel.c -o build/kernel.o

	ld -m elf_i386 -Ttext 0x1000 -o build/kernel.bin build/boot.o build/kernel.o

	cat build/kernel.bin > build/os.img
