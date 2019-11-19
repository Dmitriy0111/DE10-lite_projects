
help:
	$(info make help			- show this message)
	$(info make clean			- delete synth and simulation folders)
	$(info make sim				- the same as sim_gui)
	$(info make synth_q			- clean, create the board project and run the synthesis (for default board))
	$(info make open_q			- the same as synth_gui)
	$(info make load_q			- the same as synth_load)
	$(info make sim_cmd			- run simulation in Modelsim (console mode))
	$(info make sim_gui			- run simulation in Modelsim (gui mode))
	$(info make synth_create	- create the board project)
	$(info make synth_build_q	- build the board project with quartus)
	$(info make synth_gui_q		- open the board project with quartus)
	$(info make synth_load_q	- program the FPGA board with quartus)
	$(info Open and read the Makefile for details)
	@true

PWD     := $(shell pwd)

CUR_PROJECT ?= 01_nios_test

########################################################
# common make targets

show_pwd:
	PWD

clean: \
	sim_clean \
	synth_clean

sim_all: \
	sim_cmd 

sim: sim_gui

create: synth_create

synth_q: \
	synth_clean \
	synth_create \
	synth_build_q

load_q: synth_load_q

open_q: synth_gui_q

########################################################
# simulation - Modelsim

VSIM_DIR = $(PWD)/sim
RUN_DIR = $(PWD)/$(CUR_PROJECT)/run/run.tcl

VLIB_BIN = cd $(VSIM_DIR) && vlib
VLOG_BIN = cd $(VSIM_DIR) && vlog
VSIM_BIN = cd $(VSIM_DIR) && vsim

VSIM_OPT_COMMON += -do $(RUN_DIR) -onfinish final

VSIM_OPT_CMD     = -c
VSIM_OPT_CMD    += -onfinish exit

VSIM_OPT_GUI     = -gui -onfinish stop

sim_clean:
	rm -rfd $(VSIM_DIR)

sim_dir: sim_clean
	mkdir $(VSIM_DIR)

sim_cmd: sim_dir
	$(VSIM_BIN) $(VSIM_OPT_COMMON) $(VSIM_OPT_CMD)

sim_gui: sim_dir
	$(VSIM_BIN) $(VSIM_OPT_COMMON) $(VSIM_OPT_GUI) &

########################################################
# synthesis - Quartus Prime

MAKEFILE_PATH   = $(PWD)/board
SYNTH_DIR       = $(PWD)/synth/$(CUR_PROJECT)
SYNTH_TEMPLATE  = $(PWD)/$(CUR_PROJECT)
CABLE_NAME 	   ?= "USB-Blaster"

synth_clean:
	rm -rfd synth

synth_create: synth_clean
	mkdir -p synth
	cp -r $(SYNTH_TEMPLATE) $(SYNTH_DIR)

synth_build_q:
	quartus_sh --flow compile $(SYNTH_DIR)/$(CUR_PROJECT).qpf

synth_gui_q:
	quartus $(SYNTH_DIR)/$(CUR_PROJECT).qpf &

synth_load_q:
	quartus_pgm -c $(CABLE_NAME) -m JTAG -o "p;$(SYNTH_DIR)/output_files/$(CUR_PROJECT).sof"

########################################################
# Compile program for nios ii

comp_prog:
	mkdir -p synth/$(CUR_PROJECT)/out
	nios2-elf-gcc -O1 synth/$(CUR_PROJECT)/sw/main.c -c -o synth/$(CUR_PROJECT)/out/main.o
	nios2-elf-objdump -M no-aliases -S -w --disassemble-zeroes synth/$(CUR_PROJECT)/out/main.o > synth/$(CUR_PROJECT)/out/main.lst
	nios2-elf-objcopy synth/$(CUR_PROJECT)/out/main.o synth/$(CUR_PROJECT)/system/main.hex -O ihex

comp_nios_sw:
	mkdir -p synth/$(CUR_PROJECT)/sw_out
	make -C synth/$(CUR_PROJECT) all
clean_nios_sw:
	make -C synth/$(CUR_PROJECT) clean
