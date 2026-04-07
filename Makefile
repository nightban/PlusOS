# Компиляторы
AS = nasm
CC = gcc
LD = ld

# Флаги
CFLAGS = -m32 -ffreestanding -c
LDFLAGS = -m elf_i386 -T linker.ld

# Папки
BOOT = boot
KERNEL = kernel
BUILD = build

# Файлы
BOOT_SRC = $(BOOT)/boot.asm
KERNEL_SRC = $(KERNEL)/kernel.c

BOOT_OBJ = $(BUILD)/boot.o
KERNEL_OBJ = $(BUILD)/kernel.o

OUTPUT = $(BUILD)/kernel.bin
IMAGE = $(BUILD)/os.img

all: $(IMAGE)

# Ассемблер (bootloader)
$(BOOT_OBJ): $(BOOT_SRC)
	mkdir -p $(BUILD)
	$(AS) -f elf32 $< -o $@

# Компиляция ядра
$(KERNEL_OBJ): $(KERNEL_SRC)
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $< -o $@

# Линковка
$(OUTPUT): $(BOOT_OBJ) $(KERNEL_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^

# Создание образа
$(IMAGE): $(OUTPUT)
	cat $< > $@

# Очистка
clean:
	rm -rf $(BUILD)/*
