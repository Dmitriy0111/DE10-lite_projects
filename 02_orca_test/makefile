
PROG_NAME ?= gpio_test_c

-include sw/$(PROG_NAME)/subdir.mk

ORCA_URL = https://github.com/VectorBlox/orca

clone_ip:
	git clone $(ORCA_URL) rtl/orca_system/orca

init: \
	clone_ip

GEN_OP = --family=MAX10 --part=10M50DAF484C6GES --synthesis=VERILOG --simulation=VERILOG
CLK_BUF = rtl/clk_buf/clk_buf.qsys
ORCA_SYSTEMS = rtl/orca_system/orca_systems.qsys
	
generate_qsys:
	qsys-generate $(CLK_BUF) $(GEN_OP)
	qsys-generate $(ORCA_SYSTEMS) $(GEN_OP)

LDF	= -T sw/prog.ld -b elf32-littleriscv
OCF_BIN = -O binary
ODF = -M no-aliases -S -w --disassemble-all --syms
TOOL = riscv-none-embed
PY = python

AS = $(TOOL)-as
CC = $(TOOL)-gcc
LD = $(TOOL)-ld
OBJDUMP = $(TOOL)-objdump
OBJCOPY = $(TOOL)-objcopy

OUT_DIR = sw_out
EXEC = $(OUT_DIR)/main.elf
LST = $(OUT_DIR)/main.lst
BIN = $(OUT_DIR)/main.bin
HEX = $(OUT_DIR)/prog_mem.hex
PROG_TCL = $(OUT_DIR)/prog_dev.tcl

BIN2HEX = sw/bin2hex.py
IHEX2TCL = sw/ihex2tcl.py

MM_RESET_ADDR ?= 0x00040000

create_out_dir:
	mkdir -p $(OUT_DIR)

prog_comp: create_out_dir get_git_rev $(EXEC)

prog_clean: 
	rm -rfd $(OUT_DIR)

prog_dev:
	system-console --script=$(PROG_TCL)

PROG_REV ?= 0

get_git_rev:
	$(eval PROG_REV := $(shell git rev-list --count HEAD))
	echo "#ifndef __VERSION_H" >  sw/version.h
	echo "#define __VERSION_H" >> sw/version.h
	echo "" >> sw/version.h
	echo "    char first_msg[] = \"$(PROG_NAME) Rev=$(PROG_REV)\n\r\";" >> sw/version.h
	echo "" >> sw/version.h
	echo "#endif // __VERSION_H" >> sw/version.h

$(EXEC): $(OBJS)
	$(LD) $(LDF) $(OBJS) -o $(EXEC)
	$(OBJDUMP) $(ODF) $(EXEC) > $(LST)
	$(OBJCOPY) $(EXEC) $(BIN) $(OCF_BIN)
	$(PY) $(BIN2HEX) $(BIN) $(HEX)
	$(PY) $(IHEX2TCL) $(HEX) $(PROG_TCL) $(MM_RESET_ADDR)
