
init:

GEN_OP = --family=MAX10 --part=10M50DAF484C6GES --synthesis=VERILOG --simulation=VERILOG
SYSTEM = rtl/system/system.qsys
	
generate_qsys:
	qsys-generate $(SYSTEM) $(GEN_OP)

PROG_DIR = sw
OUT_DIR = sw_out
BSP_DIR = $(OUT_DIR)/bsp
APP_DIR = $(OUT_DIR)/app
SOPCINFO_DIR = rtl/system/system.sopcinfo
BSP_TYPE = hal

comp_prog:
	mkdir -p $(OUT_DIR)
	nios2-bsp $(BSP_TYPE) $(OUT_DIR)/bsp $(SOPCINFO_DIR)
	nios2-app-generate-makefile --bsp-dir $(BSP_DIR) --elf-name $(OUT_DIR)/main.elf --app-dir $(APP_DIR) --src-dir $(PROG_DIR)
	make -C $(APP_DIR)
	make -C $(APP_DIR) mem_init_generate
	nios2-elf-objdump -M no-aliases -S -w --disasseble-zeroes $(OUT_DIR)/main.elf > $(OUT_DIR)/main.lst

prog_dev:
