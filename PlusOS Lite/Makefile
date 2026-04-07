BUILD = build

ASM = nasm
CC = gcc
LD = ld

ASM_FLAGS = -f elf32
C_FLAGS = -m32 -ffreestanding -c
LD_FLAGS = -m elf_i386 -T linker.ld

BOOT = boot/boot.asm
KERNEL = kernel/kernel.c

BOOT_OBJ = $(BUILD)/boot.o
KERNEL_OBJ = $(BUILD)/kernel.o
IMAGE = $(BUILD)/os.bin

all: $(IMAGE)

$(BUILD):
	mkdir -p $(BUILD)

$(BOOT_OBJ): $(BOOT) | $(BUILD)
	$(ASM) $(ASM_FLAGS) $< -o $@

$(KERNEL_OBJ): $(KERNEL) | $(BUILD)
	$(CC) $(C_FLAGS) $< -o $@

$(IMAGE): $(BOOT_OBJ) $(KERNEL_OBJ)
	$(LD) $(LD_FLAGS) -o $@ $^

clean:
	rm -rf $(BUILD)
