
PROG_NAME ?= gpio_test_asm

-include sw/$(PROG_NAME)/subdir.mk

ORCA_URL = https://github.com/VectorBlox/orca

clone_ip:
	git clone $(ORCA_URL) rtl/orca_system/orca

init: \
	clone_ip

CCF	= -march=rv32i -mabi=ilp32
LDF	= -b elf32-littleriscv
CPF = ihex -O ihex
OBJDUMPF = -M no-aliases -S -w --disassemble-zeroes
TOOL = riscv-none-embed

AS = $(TOOL)-as
CC = $(TOOL)-gcc
LD = $(TOOL)-ld
OBJDUMP = $(TOOL)-objdump
OBJCOPY = $(TOOL)-objcopy

EXEC = sw_out/main.elf
LST = sw_out/main.lst

comp_prog: $(EXEC)

$(EXEC): $(OBJS)
	$(LD) -T sw/prog.ld $(OBJS) -o $(EXEC) $(LDF)
	$(OBJDUMP) $(OBJDUMPF) $(EXEC) > $(LST)
