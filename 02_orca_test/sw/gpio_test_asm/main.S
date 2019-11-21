# 
#  File            :   main.S
#  Autor           :   Vlasov D.V.
#  Data            :   2018.12.05
#  Language        :   Assembler
#  Description     :   This is example for working with GPIO
#  Copyright(c)    :   2018 - 2019 Vlasov D.V.
# 

.equ GPIO_ADDR,     0x00010

.section    .text


_start:     lui     t1, GPIO_ADDR           # load upper bytes of addr GPIO;
gpio_inc:
            addi    t0, t0, 1               # t0 = t0 + 1;
            sw      t0, 0x04 (t1)           # mem[ 0x04 + t1 ] = t0;      
            beq     zero, zero, gpio_inc    # go to gpio_inc;
            