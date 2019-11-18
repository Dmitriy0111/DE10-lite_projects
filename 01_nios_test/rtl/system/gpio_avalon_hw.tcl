# TCL File Generated by Component Editor 18.1
# Mon Nov 18 20:46:13 KRAT 2019
# DO NOT MODIFY


# 
# gpio_avalon "gpio_avalon" v1.0
# Dmitriy0111(Vlasov D.V,) 2019.11.18.20:46:13
# gpio module with avalon interface
# 

# 
# request TCL package from ACDS 16.1
# 
package require -exact qsys 16.1


# 
# module gpio_avalon
# 
set_module_property DESCRIPTION "gpio module with avalon interface"
set_module_property NAME gpio_avalon
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property GROUP "Processors and Peripherals/Peripherals"
set_module_property AUTHOR "Dmitriy0111(Vlasov D.V,)"
set_module_property DISPLAY_NAME gpio_avalon
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL gpio_avalon
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE false
add_fileset_file gpio.sv SYSTEM_VERILOG PATH ../gpio_avalon/gpio.sv
add_fileset_file registers.sv SYSTEM_VERILOG PATH ../common/registers.sv
add_fileset_file gpio.svh OTHER PATH ../gpio_avalon/gpio.svh
add_fileset_file gpio_avalon.sv SYSTEM_VERILOG PATH ../gpio_avalon/gpio_avalon.sv TOP_LEVEL_FILE

add_fileset SIM_VERILOG SIM_VERILOG "" ""
set_fileset_property SIM_VERILOG TOP_LEVEL gpio_avalon
set_fileset_property SIM_VERILOG ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property SIM_VERILOG ENABLE_FILE_OVERWRITE_MODE true
add_fileset_file gpio.sv SYSTEM_VERILOG PATH ../gpio_avalon/gpio.sv
add_fileset_file registers.sv SYSTEM_VERILOG PATH ../common/registers.sv
add_fileset_file gpio.svh OTHER PATH ../gpio_avalon/gpio.svh
add_fileset_file gpio_avalon.sv SYSTEM_VERILOG PATH ../gpio_avalon/gpio_avalon.sv


# 
# parameters
# 
add_parameter gpio_w INTEGER 8
set_parameter_property gpio_w DEFAULT_VALUE 8
set_parameter_property gpio_w DISPLAY_NAME gpio_w
set_parameter_property gpio_w TYPE INTEGER
set_parameter_property gpio_w UNITS None
set_parameter_property gpio_w ALLOWED_RANGES -2147483648:2147483647
set_parameter_property gpio_w HDL_PARAMETER true


# 
# display items
# 


# 
# connection point irq
# 
add_interface irq interrupt end
set_interface_property irq associatedAddressablePoint ""
set_interface_property irq associatedClock clk
set_interface_property irq bridgedReceiverOffset ""
set_interface_property irq bridgesToReceiver ""
set_interface_property irq ENABLED true
set_interface_property irq EXPORT_OF ""
set_interface_property irq PORT_NAME_MAP ""
set_interface_property irq CMSIS_SVD_VARIABLES ""
set_interface_property irq SVD_ADDRESS_GROUP ""

add_interface_port irq irq irq Output 1


# 
# connection point reset_n
# 
add_interface reset_n reset end
set_interface_property reset_n associatedClock clk
set_interface_property reset_n synchronousEdges DEASSERT
set_interface_property reset_n ENABLED true
set_interface_property reset_n EXPORT_OF ""
set_interface_property reset_n PORT_NAME_MAP ""
set_interface_property reset_n CMSIS_SVD_VARIABLES ""
set_interface_property reset_n SVD_ADDRESS_GROUP ""

add_interface_port reset_n rstn reset_n Input 1


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
set_interface_property s_0 associatedReset reset_n
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

add_interface_port s_0 address address Input 3
add_interface_port s_0 writedata writedata Input 32
add_interface_port s_0 readdata readdata Output 32
add_interface_port s_0 write write Input 1
add_interface_port s_0 read read Input 1
add_interface_port s_0 chipselect chipselect Input 1
add_interface_port s_0 readdatavalid readdatavalid Output 1
set_interface_assignment s_0 embeddedsw.configuration.isFlash 0
set_interface_assignment s_0 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment s_0 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment s_0 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point gpio
# 
add_interface gpio conduit end
set_interface_property gpio associatedClock clk
set_interface_property gpio associatedReset reset_n
set_interface_property gpio ENABLED true
set_interface_property gpio EXPORT_OF ""
set_interface_property gpio PORT_NAME_MAP ""
set_interface_property gpio CMSIS_SVD_VARIABLES ""
set_interface_property gpio SVD_ADDRESS_GROUP ""

add_interface_port gpio gpd gpd Output gpio_w
add_interface_port gpio gpi gpi Input gpio_w
add_interface_port gpio gpo gpo Output gpio_w
