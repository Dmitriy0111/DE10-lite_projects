#
#  File            :   ihex2tcl.py
#  Autor           :   Vlasov D.V.
#  Data            :   2019.11.23
#  Language        :   Python
#  Description     :   This is script for converting ihex format to hex
#  Copyright(c)    :   2019 Vlasov D.V.
#

import sys
import datetime

def ihex2tcl(ihex_file, tcl_file):
    for lines in ihex_file:
        lines = lines[0:-3]
        # break if end of record
        if( lines[7:9] == "01"):
            break
        # record data
        elif( lines[7:9] == "00" ):
            # delete ':' and lenght
            lines = lines[3:]
            # find addr
            address = int('0x'+(lines[0:4]),16) 
            lines = lines[4:]
            # delete type
            lines = lines[2:]
            # write addr
            tcl_file.write("master_write_memory $m0 0x{:s} ".format( hex( address )[2:] ))
            # write data
            tcl_file.write("0x{:s} 0x{:s} 0x{:s} 0x{:s}\n".format(lines[6:8],lines[4:6],lines[2:4],lines[0:2]))

def array_tcl(ihex_file, tcl_file):
    tcl_file.write("array set prog_mem {\n")
    row = 0
    for lines in ihex_file:
        # break if end of record
        if( lines[7:9] == "01"):
            break
        # record data
        elif( lines[7:9] == "00" ):
            # delete ':' and lenght
            lines = lines[3:]
            # find addr
            address = int('0x'+lines[0:4],16)
            address = address << 2
            lines = lines[4:]
            # delete type
            lines = lines[2:]
            # write addr
            tcl_file.write("    ")
            tcl_file.write("{:d},0 0x{:s} ".format(row,hex( address )[2:]))
            tcl_file.write("{:d},1 0x{:s}{:s}{:s}{:s}\n".format(row,lines[0:2],lines[2:4],lines[4:6],lines[6:8]))
        row += 1
    tcl_file.write("}\n\n")
    tcl_file.write("set max_row {:d}\n".format(row))

print("ihex2tcl start conversion!")

time_now = datetime.datetime.now()

ihex_file = open(sys.argv[1], "r")

tcl_file = open(sys.argv[2], "w")

tcl_file.write('''
#
# File          :   prog_dev.tcl
# Autor         :   Vlasov D.V.
# Data          :   {:d}.{:d}.{:d} (This file is generated automatically using script ihex2tcl.py)
# Language      :   tcl
# Description   :   This is script for programming Altera/Intel CPLD/FPGA with system-console.
# Copyright(c)  :   {:d} Vlasov D.V.
#

'''.format(time_now.year,time_now.month,time_now.day,time_now.year))

array_tcl(ihex_file, tcl_file)

tcl_file.write('''
proc load_mem { master mem_array max_row } {
    upvar $mem_array mem_array_
	for {set row 0} {$row < $max_row} {incr row} {
        puts $mem_array_($row,1)
        master_write_32 $master $mem_array_($row,0) $mem_array_($row,1)
    }
}

proc ver_mem { master mem_array max_row } {
    upvar $mem_array mem_array_
    array set test_mem {}
    
    for {set row 0} {$row < $max_row} {incr row} {
        set mem_str_1 $mem_array_($row,1)
        set mem_str_2 [ master_read_32 $master $mem_array_($row,0) 1 ]
        if {$mem_str_1 != $mem_str_2} {
            puts [format "Error at addr %s, expected values = %s, reading values = %s" $mem_array_($row,0) $mem_str_1 $mem_str_2]
        }
    }
}

proc get_default_master {} {
	return [ lindex [ get_service_paths master ] 0 ]
}
 
set p0 [get_default_master]

set m0 [claim_service master $p0 ""]

puts "Start program device"

''')

#ihex2tcl(ihex_file, tcl_file)

#tcl_file.write("master_write_32 $m0 {:s} 0x00000000\n".format(sys.argv[3]))

tcl_file.write('''
puts "Loading memory"
load_mem $m0 prog_mem $max_row
puts "Verifying memory"
ver_mem $m0 prog_mem $max_row
''')

#tcl_file.write("\nmaster_write_32 $m0 {:s} 0x00000001\n".format(sys.argv[3]))
tcl_file.write('''
puts "End program device"

close_service master $m0
''')

print("ihex2tcl conversion comlete!")
