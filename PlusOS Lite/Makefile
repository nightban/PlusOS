BUILD = build

ASM = nasm
CC = gcc
LD = ld

# флаги
ASM_FLAGS = -f elf32
C_FLAGS = -m32 -ffreestanding -c -Ikernel
LD_FLAGS = -m elf_i386 -T linker.ld

# файлы
BOOT = boot/boot.asm
KERNEL = kernel/kernel.c
SCREEN = kernel/screen.c
KEYBOARD = kernel/keyboard.c

# объекты
BOOT_OBJ = $(BUILD)/boot.o
KERNEL_OBJ = $(BUILD)/kernel.o
SCREEN_OBJ = $(BUILD)/screen.o
KEYBOARD_OBJ = $(BUILD)/keyboard.o

# итоговый образ
IMAGE = $(BUILD)/os.bin

all: $(IMAGE)

# создаём папку build
$(BUILD):
	mkdir -p $(BUILD)

# сборка boot
$(BOOT_OBJ): $(BOOT) | $(BUILD)
	$(ASM) $(ASM_FLAGS) $< -o $@

# сборка kernel
$(KERNEL_OBJ): $(KERNEL) | $(BUILD)
	$(CC) $(C_FLAGS) $< -o $@

# сборка screen
$(SCREEN_OBJ): $(SCREEN) | $(BUILD)
	$(CC) $(C_FLAGS) $< -o $@

# сборка keyboard
$(KEYBOARD_OBJ): $(KEYBOARD) | $(BUILD)
	$(CC) $(C_FLAGS) $< -o $@

# линковка
$(IMAGE): $(BOOT_OBJ) $(KERNEL_OBJ) $(SCREEN_OBJ) $(KEYBOARD_OBJ)
	$(LD) $(LD_FLAGS) -o $@ $^

# очистка
clean:
	rm -rf $(BUILD)

.PHONY: all clean
