CC := gcc
AS := nasm
DISAS := disasm
QEMU := qemu-system-x86_64

C_FLAGS := --freestanding -I.. -I.
LD_FLAGS := -Ttext 0x1000 --oformat binary
AS_OFLAGS := -f elf64
AS_BINFLAGS := -f bin -I '16bit'
QEMU_FLAGS := -curses

C_SRC := $(wildcard kernel/*.c drivers/*.c)
HEADERS := $(wildcard kernel/*.h drivers/*.h)
OBJ := $(C_SRC:.c=.o)

OSIMG := os-image

all: $(OSIMG)

run: all
	$(QEMU) $(QEMU_FLAGS) -fda $(OSIMG)

$(OSIMG): boot/boot_sect.bin kernel/kernel.bin
	cat $^ > $@

kernel/kernel.bin: kernel/kernel_entry.o $(OBJ)
	ld $(LD_FLAGS) $^ -o $@

%.o : %.c
	$(CC) $(C_FLAGS) -c $< -o $@

%.o : %.asm
	$(AS) $< $(AS_OFLAGS) -o $@

%.bin : %.asm
	$(AS) $< $(AS_BINFLAGS) -o $@

clean:
	rm $(OSIMG) kernel.dis kernel/*.o kernel/*.bin boot/*.bin drivers/*.o

kernel.dis: kernel/kernel.bin
	$(DISAS) -b 32 $< > $@

