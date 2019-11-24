#
#  File            :   ihex2tcl.py
#  Autor           :   Vlasov D.V.
#  Data            :   2019.11.23
#  Language        :   Python
#  Description     :   This is script for converting ihex format to hex
#  Copyright(c)    :   2019 Vlasov D.V.
#

import sys

print(sys.argv[1])

pars_file  = open(sys.argv[1] , "r")

tcl_out    = open(sys.argv[2] + ".tcl",   "w")    # tcl

tcl_out.write('''
proc get_default_master {} {
	return [ lindex [ get_service_paths master ] 0 ]
}
 
set p0 [ get_default_master ]

set m0 [claim_service master $p0 ""]

''')

hi_addr = 0

for lines in pars_file:
    # find checksum
    checksum = lines[-3:-1]
    lines = lines[0:-3]
    # break if end of record
    if( lines[7:9] == "01"):
        break
    # update high address of linear record
    elif( lines[7:9] == "04"):
        hi_addr = int('0x'+lines[9:13],16)
    # record data
    elif( lines[7:9] == "00" ):
        # delete ':'
        lines = lines[1:]
        # find lenght
        lenght = int('0x'+lines[0:2],16)
        lines = lines[2:]
        # find addr
        lo_addr = int('0x'+lines[0:4],16)
        lines = lines[4:]
        # find type
        type_ = lines[0:2]
        lines = lines[2:]
        i = 0
        # write addr
        st_addr = str("@{:s}\n".format( hex( ( ( hi_addr << 16 ) + lo_addr ) >> 2 )[2:] ))
        tcl_out.write("master_write_memory $m0 0x{:s} ".format( hex( ( ( hi_addr << 16 ) + lo_addr + i ) )[2:] ))
        while(1):
            # write data
            tcl_out.write("0x{:s} ".format(lines[0:2]))
            lines = lines[2:]
            i += 1
            if( i >= lenght ):
                tcl_out.write("\n")
                break

tcl_out.write('''
close_service master $m0'''
)

print("Conversion comlete!")
