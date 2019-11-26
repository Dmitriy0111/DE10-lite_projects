
PROG_NAME ?= gpio_test_c

-include sw/$(PROG_NAME)/subdir.mk

ORCA_URL = https://github.com/VectorBlox/orca

clone_ip:
	git clone $(ORCA_URL) rtl/orca_system/orca

init: \
	clone_ip
	
generate_qsys:
	qsys-generate rtl/clk_buf/clk_buf.qsys --family=MAX10 --part=10M50DAF484C6GES --synthesis=VERILOG --simulation=VERILOG
	qsys-generate rtl/orca_system/orca_systems.qsys --family=MAX10 --part=10M50DAF484C6GES --synthesis=VERILOG --simulation=VERILOG

LDF	= -b elf32-littleriscv
CPF = -O ihex
OBJDUMPF = -M no-aliases -S -w --disassemble-all
TOOL = riscv-none-embed

AS = $(TOOL)-as
CC = $(TOOL)-gcc
LD = $(TOOL)-ld
OBJDUMP = $(TOOL)-objdump
OBJCOPY = $(TOOL)-objcopy

EXEC = sw_out/main.elf
LST = sw_out/main.lst
IHEX = sw_out/main.ihex
HEX = sw_out/main
PROG_TCL = sw_out/main.tcl

comp_prog: $(EXEC)

prog_dev:
	system-console --script=$(PROG_TCL)

$(EXEC): $(OBJS)
	$(LD) -T sw/prog.ld $(OBJS) -o $(EXEC) $(LDF)
	$(OBJDUMP) $(OBJDUMPF) $(EXEC) > $(LST)
	$(OBJCOPY) $(EXEC) $(IHEX) $(CPF)
	python sw/ihex2hex.py $(IHEX) $(HEX)
	python sw/ihex2tcl.py $(IHEX) $(HEX)

