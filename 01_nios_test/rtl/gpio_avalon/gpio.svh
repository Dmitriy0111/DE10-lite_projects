/*
*  File            :   gpio.svh
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.18
*  Language        :   SystemVerilog
*  Description     :   This is GPIO constants
*  Copyright(c)    :   2019 Vlasov D.V.
*/

`ifndef SVH__GPIO
`define SVH__GPIO

typedef enum logic [2 : 0]
{
    GPIO_GPI   = 3'h0,
    GPIO_GPO   = 3'h1,
    GPIO_GPD   = 3'h2,
    GPIO_IRQ_M = 3'h3,
    GPIO_CAP   = 3'h4,
    GPIO_IRQ_V = 3'h5
} gpio_reg_addr;

`endif // SVH__GPIO
