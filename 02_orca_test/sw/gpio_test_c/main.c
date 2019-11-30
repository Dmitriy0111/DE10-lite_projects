/*
*  File            :   main.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.21
*  Language        :   C
*  Description     :   This is examples for working with GPIO with orca riscv core
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "..\system.h"
#include "..\..\drv\h\gpio.h"
#include "..\..\drv\h\delay.h"

#define SYNTH   1
#define SIM     0
#define RUNTYPE SYNTH

#if   RUNTYPE == SIM
    #define delay_value 10
#elif RUNTYPE == SYNTH
    #define delay_value 10000
#endif

void main (void)
{
    GPIO_0->gpio_o = 0;
    while(1)
    {
        delay(delay_value);
        GPIO_0->gpio_o ++;
    }
}
