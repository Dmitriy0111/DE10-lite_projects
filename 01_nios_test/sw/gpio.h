/*
*  File            :   gpio.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.18
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with gpio
*  Copyright(c)    :   2019 Vlasov D.V.
*/

//#include "sys_cfg.h"

#define GPIO_BASE   0x00010000
#define GPIO_0_BASE GPIO_BASE

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

// defining gpio typedef
typedef struct{
    volatile    unsigned    gpio_i;         // GPIO input register
    volatile    unsigned    gpio_o;         // GPIO output register
    volatile    unsigned    gpio_d;         // GPIO direction register
    volatile    unsigned    gpio_irq_m;     // GPIO IRQ mask
    volatile    unsigned    gpio_cap;       // GPIO capture posedge/negedge interrupt generate
    volatile    unsigned    gpio_irq_v;     // GPIO IRQ register
} GPIO_typedef;

// defining GPIO PORTs
#define GPIO_0  ( (GPIO_typedef *) GPIO_0_BASE )

// defining GPIO macros
#define gpio_get_in(GPIO_)        GPIO_->gpio_i

#define gpio_set_out(GPIO_,VAL)   GPIO_->gpio_o = VAL
#define gpio_get_out(GPIO_)       GPIO_->gpio_o

#define gpio_set_dir(GPIO_,VAL)   GPIO_->gpio_d = VAL
#define gpio_get_dir(GPIO_)       GPIO_->gpio_d

#define gpio_set_irq_m(GPIO_,VAL) GPIO_->gpio_irq_m = VAL
#define gpio_get_irq_m(GPIO_)     GPIO_->gpio_irq_m

#define gpio_set_cap(GPIO_,VAL)   GPIO_->gpio_cap = VAL
#define gpio_get_cap(GPIO_)       GPIO_->gpio_cap

#define gpio_set_irq_v(GPIO_,VAL) GPIO_->gpio_irq_v = VAL
#define gpio_get_irq_v(GPIO_)     GPIO_->gpio_irq_v

// defining functions
inline void gpio_set_port_bit(GPIO_typedef* GPIO_, unsigned bit){
    GPIO_->gpio_o = GPIO_->gpio_o | ( 1 << bit );
}

inline void gpio_clr_port_bit(GPIO_typedef* GPIO_, unsigned bit){
    GPIO_->gpio_o = GPIO_->gpio_o & ~( 1 << bit );
}

inline void gpio_toggle_port_bit(GPIO_typedef* GPIO_, unsigned bit){
    GPIO_->gpio_o = GPIO_->gpio_o ^ ( 1 << bit );
}
