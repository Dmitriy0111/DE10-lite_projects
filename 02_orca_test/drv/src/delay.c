/*
*  File            :   delay.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.21
*  Language        :   C
*  Description     :   This is source file for delay.h
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "..\h\delay.h"

void delay(uint32_t delay_c)
{
    uint32_t delay_v = 0;
    delay_v = delay_c;
    while(delay_v)
        delay_v--;
}
