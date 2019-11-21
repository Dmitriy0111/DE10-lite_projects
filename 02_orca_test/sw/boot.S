#
#  File            :   boot.S
#  Autor           :   Vlasov D.V.
#  Data            :   2019.11.21
#  Language        :   Assembler
#  Description     :   This is Assembler file for first initialization
#  Copyright(c)    :   2019 Vlasov D.V.
#

.equ    _stack_start,   0x0000f00  # 3C0 << 2

vectors:
    j   _main               # 0x00  vector  ( reset vector )

_main:
    la  sp, _stack_start    # load stack pointer value
    j   main                # jump to main program
    