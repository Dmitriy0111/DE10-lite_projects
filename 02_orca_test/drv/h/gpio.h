/*
*  File            :   gpio.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.21
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with gpio
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "risc_v_types.h"

#define GPIO_BASE   0x00010000
#define GPIO_0_BASE ( GPIO_BASE + 0x00 )

typedef struct{
    volatile    uint32_t    gpio_i;         // GPIO input register
    volatile    uint32_t    gpio_o;         // GPIO output register
    volatile    uint32_t    gpio_d;         // GPIO direction register
    volatile    uint32_t    gpio_irq_m;     // GPIO interrupt mask register
    volatile    uint32_t    gpio_cap;       // GPIO capture register
    volatile    uint32_t    gpio_irq_v;     // GPIO interrupt register
} gpio_typedef;

#define GPIO_0  ( (gpio_typedef *) GPIO_0_BASE)

// defining functions
void gpio_set_port_bit(gpio_typedef* GPIO_, uint32_t bit);
void gpio_clr_port_bit(gpio_typedef* GPIO_, uint32_t bit);
void gpio_toggle_port_bit(gpio_typedef* GPIO_, uint32_t bit);
