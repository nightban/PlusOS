BUILD_DIR = build

ASM = nasm
LD = ld

ASM_FLAGS = -f elf32
LD_FLAGS = -m elf_i386 -T linker.ld -o

BOOT = boot/boot.asm
KERNEL = kernel/kernel.asm

BOOT_OBJ = $(BUILD_DIR)/boot.o
KERNEL_OBJ = $(BUILD_DIR)/kernel.o

IMAGE = $(BUILD_DIR)/os.bin

all: $(IMAGE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BOOT_OBJ): $(BOOT) | $(BUILD_DIR)
	$(ASM) $(ASM_FLAGS) $< -o $@

$(KERNEL_OBJ): $(KERNEL) | $(BUILD_DIR)
	$(ASM) $(ASM_FLAGS) $< -o $@

$(IMAGE): $(BOOT_OBJ) $(KERNEL_OBJ)
	$(LD) $(LD_FLAGS) $@ $^

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
