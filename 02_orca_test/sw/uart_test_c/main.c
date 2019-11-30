/*
*  File            :   main.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.21
*  Language        :   C
*  Description     :   This is examples for working with GPIO, UART with orca riscv core
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "..\system.h"
#include "..\..\drv\h\gpio.h"
#include "..\..\drv\h\delay.h"
#include "..\..\drv\h\uart.h"

#define SYNTH   1
#define SIM     0
#define RUNTYPE SIM

#if   RUNTYPE == SIM
    #define delay_value 1000
#elif RUNTYPE == SYNTH
    #define delay_value 1000000
#endif

char uart_msg[14] = "Hello World!\n\r";

void main (void)
{
    GPIO_0->gpio_o = 0;
    while(1)
    {
        delay(delay_value);
        uart_send_msg(UART_0, uart_msg, sizeof(uart_msg));
        GPIO_0->gpio_o ++;
    }
}
