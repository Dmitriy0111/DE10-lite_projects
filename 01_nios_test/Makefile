-include sources.mk
-include subdir.mk

TOOL = nios2-elf-

LD = $(TOOL)ld
OBJDUMP = $(TOOL)objdump
OBJCOPY = $(TOOL)objcopy
CCF = -O1 -c -o

EXEC = sw_out/main.hex

all: $(EXEC)
	
$(EXEC): $(OBJS)
	nios2-elf-ld -T sw/prog.ld $(OBJS) -o sw_out/main.elf
	nios2-elf-objdump -M no-aliases -S -w --disassemble-zeroes sw_out/main.elf > sw_out/main.lst
	nios2-elf-objcopy sw_out/main.elf sw_out/main.ihex -O ihex

clean:
	rm -rfd sw_out
