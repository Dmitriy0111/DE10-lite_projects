
# 
# mem_map_res "mem_map_res" v1.0
# Dmitriy0111(Vlasov D.V,) 2019.11.27
# memory mapped reset with avalon interface
# 

# 
# request TCL package from ACDS 16.1
# 
package require -exact qsys 16.1

# 
# module mem_map_res
# 
set_module_property DESCRIPTION "memory mapped reset with avalon interface"
set_module_property NAME mem_map_res
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property GROUP "Processors and Peripherals/Peripherals"
set_module_property AUTHOR "Dmitriy0111(Vlasov D.V.)"
set_module_property DISPLAY_NAME mem_map_res
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false

# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL mem_map_res
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE false
add_fileset_file registers.sv SYSTEM_VERILOG PATH ../common/registers.sv
add_fileset_file mem_map_res.sv SYSTEM_VERILOG PATH ../mem_map_res/mem_map_res.sv TOP_LEVEL_FILE

add_fileset SIM_VERILOG SIM_VERILOG "" ""
set_fileset_property SIM_VERILOG TOP_LEVEL mem_map_res
set_fileset_property SIM_VERILOG ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property SIM_VERILOG ENABLE_FILE_OVERWRITE_MODE true
add_fileset_file registers.sv SYSTEM_VERILOG PATH ../common/registers.sv
add_fileset_file mem_map_res.sv SYSTEM_VERILOG PATH ../mem_map_res/mem_map_res.sv

# 
# parameters
# 

# 
# display items
# 

# 
# connection point reset_out
# 
add_interface reset_out reset start
set_interface_property reset_out associatedAddressablePoint ""
set_interface_property reset_out associatedClock clk
set_interface_property reset_out bridgedReceiverOffset ""
set_interface_property reset_out bridgesToReceiver ""
set_interface_property reset_out ENABLED true
set_interface_property reset_out EXPORT_OF ""
set_interface_property reset_out PORT_NAME_MAP ""
set_interface_property reset_out CMSIS_SVD_VARIABLES ""
set_interface_property reset_out SVD_ADDRESS_GROUP ""

add_interface_port reset_out reset_out reset_out Output 1


# 
# connection point rstn
# 
add_interface rstn reset end
set_interface_property rstn associatedClock clk
set_interface_property rstn synchronousEdges DEASSERT
set_interface_property rstn ENABLED true
set_interface_property rstn EXPORT_OF ""
set_interface_property rstn PORT_NAME_MAP ""
set_interface_property rstn CMSIS_SVD_VARIABLES ""
set_interface_property rstn SVD_ADDRESS_GROUP ""

add_interface_port rstn rstn rstn Input 1

# 
# connection point clk
# 
add_interface clk clock end
set_interface_property clk clockRate 0
set_interface_property clk ENABLED true
set_interface_property clk EXPORT_OF ""
set_interface_property clk PORT_NAME_MAP ""
set_interface_property clk CMSIS_SVD_VARIABLES ""
set_interface_property clk SVD_ADDRESS_GROUP ""

add_interface_port clk clk clk Input 1


# 
# connection point s_0
# 
add_interface s_0 avalon end
set_interface_property s_0 addressUnits WORDS
set_interface_property s_0 associatedClock clk
set_interface_property s_0 associatedReset rstn
set_interface_property s_0 bitsPerSymbol 8
set_interface_property s_0 burstOnBurstBoundariesOnly false
set_interface_property s_0 burstcountUnits WORDS
set_interface_property s_0 explicitAddressSpan 0
set_interface_property s_0 holdTime 0
set_interface_property s_0 linewrapBursts false
set_interface_property s_0 maximumPendingReadTransactions 1
set_interface_property s_0 maximumPendingWriteTransactions 0
set_interface_property s_0 readLatency 0
set_interface_property s_0 readWaitTime 1
set_interface_property s_0 setupTime 0
set_interface_property s_0 timingUnits Cycles
set_interface_property s_0 writeWaitTime 0
set_interface_property s_0 ENABLED true
set_interface_property s_0 EXPORT_OF ""
set_interface_property s_0 PORT_NAME_MAP ""
set_interface_property s_0 CMSIS_SVD_VARIABLES ""
set_interface_property s_0 SVD_ADDRESS_GROUP ""

add_interface_port s_0 address address Input 1
add_interface_port s_0 writedata writedata Input 32
add_interface_port s_0 readdata readdata Output 32
add_interface_port s_0 write write Input 1
add_interface_port s_0 chipselect chipselect Input 1
