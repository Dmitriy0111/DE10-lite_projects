/*
*  File            :   gpio.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.21
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with gpio
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#ifndef __GPIO_H
#define __GPIO_H

#include "risc_v_types.h"

typedef struct{
    volatile    uint32_t    gpio_i;         // GPIO input register
    volatile    uint32_t    gpio_o;         // GPIO output register
    volatile    uint32_t    gpio_d;         // GPIO direction register
    volatile    uint32_t    gpio_irq_m;     // GPIO interrupt mask register
    volatile    uint32_t    gpio_cap;       // GPIO capture register
    volatile    uint32_t    gpio_irq_v;     // GPIO interrupt register
} gpio_typedef;

// defining functions
void gpio_set_port_bit(gpio_typedef* GPIO_, uint32_t bit);
void gpio_clr_port_bit(gpio_typedef* GPIO_, uint32_t bit);
void gpio_toggle_port_bit(gpio_typedef* GPIO_, uint32_t bit);

#endif // __GPIO_H
