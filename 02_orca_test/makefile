
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

LDF	= -b elf32-littleriscv
OCF_BIN = -O binary
ODF = -M no-aliases -S -w --disassemble-all
TOOL = riscv-none-embed

AS = $(TOOL)-as
CC = $(TOOL)-gcc
LD = $(TOOL)-ld
OBJDUMP = $(TOOL)-objdump
OBJCOPY = $(TOOL)-objcopy

OUT_DIR = sw_out
EXEC = $(OUT_DIR)/main.elf
LST = $(OUT_DIR)/main.lst
BIN = $(OUT_DIR)/main.bin
HEX = $(OUT_DIR)/main.hex
PROG_TCL = $(OUT_DIR)/prog_dev.tcl

MM_RESET_ADDR ?= 0x00040000

create_out_dir:
	mkdir -p $(OUT_DIR)

comp_prog: create_out_dir $(EXEC)

clean_prog: 
	rm -rfd $(OUT_DIR)

prog_dev:
	system-console --script=$(PROG_TCL)

$(EXEC): $(OBJS)
	$(LD) -T sw/prog.ld $(OBJS) -o $(EXEC) $(LDF)
	$(OBJDUMP) $(ODF) $(EXEC) > $(LST)
	$(OBJCOPY) $(EXEC) $(BIN) $(OCF_BIN)
	python sw/bin2hex.py $(BIN) $(HEX)
	python sw/ihex2tcl.py $(HEX) $(PROG_TCL) $(MM_RESET_ADDR)
