/*
*  File            :   gpio.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.21
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with gpio
*  Copyright(c)    :   2019 Vlasov D.V.
*/

//#include "sys_cfg.h"

#define GPIO_BASE   0x00010000
#define GPIO_0_BASE ( GPIO_BASE + 0x00 )

#define GPIO_GPI    0x00
#define GPIO_GPO    0x04
#define GPIO_GPD    0x08
#define GPIO_IRQ_M  0x0C
#define GPIO_CAP    0x10
#define GPIO_IRQ_V  0x14

#define GPIO_0_GPI      (* (volatile unsigned *) ( GPIO_0_BASE + GPIO_GPI   ) )
#define GPIO_0_GPO      (* (volatile unsigned *) ( GPIO_0_BASE + GPIO_GPO   ) )
#define GPIO_0_GPD      (* (volatile unsigned *) ( GPIO_0_BASE + GPIO_GPD   ) )
#define GPIO_0_IRQ_M    (* (volatile unsigned *) ( GPIO_0_BASE + GPIO_IRQ_M ) )
#define GPIO_0_CAP      (* (volatile unsigned *) ( GPIO_0_BASE + GPIO_CAP   ) )
#define GPIO_0_IRQ_V    (* (volatile unsigned *) ( GPIO_0_BASE + GPIO_IRQ_V ) )

typedef struct{
    volatile    unsigned    gpio_i;         // GPIO input register
    volatile    unsigned    gpio_o;         // GPIO output register
    volatile    unsigned    gpio_d;         // GPIO direction register
    volatile    unsigned    gpio_irq_m;     // GPIO interrupt mask register
    volatile    unsigned    gpio_cap;       // GPIO capture register
    volatile    unsigned    gpio_irq_v;     // GPIO interrupt register
} gpio_typedef;

#define GPIO_0  ( (gpio_typedef *) GPIO_0_BASE)

// defining functions
void gpio_set_port_bit(gpio_typedef* GPIO_, unsigned bit);
void gpio_clr_port_bit(gpio_typedef* GPIO_, unsigned bit);
void gpio_toggle_port_bit(gpio_typedef* GPIO_, unsigned bit);
