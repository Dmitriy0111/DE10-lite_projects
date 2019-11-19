/*
*  File            :   gpio.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.18
*  Language        :   C
*  Description     :   This is source file for gpio.h
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "../h/gpio.h"

// defining functions
void gpio_set_port_bit(GPIO_typedef* GPIO_, unsigned bit){
    GPIO_->gpio_o = GPIO_->gpio_o | ( 1 << bit );
}

void gpio_clr_port_bit(GPIO_typedef* GPIO_, unsigned bit){
    GPIO_->gpio_o = GPIO_->gpio_o & ~( 1 << bit );
}

void gpio_toggle_port_bit(GPIO_typedef* GPIO_, unsigned bit){
    GPIO_->gpio_o = GPIO_->gpio_o ^ ( 1 << bit );
}
