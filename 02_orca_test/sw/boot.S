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

# macro for set gpio outputs to '1' with mask
.altmacro
.macro set_gpio_o gpio_base, bit_mask
    lui     a3, %hi(gpio_base)
    lw      a4, GPIO_GPO(a3)
    ori     a4, a4, bit_mask
    sw      a4, GPIO_GPO(a3)
.endm

# macro for set gpio outputs to '0' with mask
.altmacro
.macro clr_gpio_o gpio_base, bit_mask
    lui     a3, %hi(gpio_base)
    lw      a4, GPIO_GPO(a3)
    andi    a4, a4, bit_mask
    sw      a4, GPIO_GPO(a3)
.endm

reset_vec:                                  # reset vector
    j           _main               
exception:                                  # ecxeption vector
    set_gpio_o  GPIO_0_BASE, EXCEP_MSET
dead_hook:
    j           dead_hook

_main:
    la          t0, exception
    csrw        mtvec, t0
    clr_gpio_o  GPIO_0_BASE, EXCEP_MCLR
    la          sp, _stack_start            # load stack pointer value
    j           main                        # jump to main program
    