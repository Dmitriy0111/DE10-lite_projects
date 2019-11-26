#
#  File            :   boot.S
#  Autor           :   Vlasov D.V.
#  Data            :   2019.11.21
#  Language        :   Assembler
#  Description     :   This is Assembler file for first initialization
#  Copyright(c)    :   2019 Vlasov D.V.
#

.equ    _stack_start,   0x0000FFFC  # end of onchip memory

.equ    GPIO_0_BASE,    0x00010000
.equ    GPIO_GPO,       0x04
.equ    EXCEP_MCLR,     0xFD
.equ    EXCEP_MSET,     0x02

reset_vec:
    j       _main               # 0x00  vector  ( reset vector )
exception:
    lui     a3, %hi(GPIO_0_BASE)
    sw      a4, GPIO_GPO(a3)
    ori     a4, a4, EXCEP_MSET
    lw      a4, GPIO_GPO(a3)
dead_hook:
    j       dead_hook

_main:
    la      t0, exception
    csrw    mtvec, t0
    lui     a3, %hi(GPIO_0_BASE)
    sw      a4, GPIO_GPO(a3)
    ori     a4, a4, EXCEP_MCLR
    lw      a4, GPIO_GPO(a3)
    la      sp, _stack_start    # load stack pointer value
    j       main                # jump to main program
    