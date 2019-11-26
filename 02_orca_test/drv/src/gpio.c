/*
*  File            :   gpio.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.21
*  Language        :   C
*  Description     :   This is source file for gpio.h
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "..\h\gpio.h"

void gpio_set_port_bit(gpio_typedef* GPIO_, uint32_t bit){
    GPIO_->gpio_o = GPIO_->gpio_o |  ( 1 << bit );
}

void gpio_clr_port_bit(gpio_typedef* GPIO_, uint32_t bit){
    GPIO_->gpio_o = GPIO_->gpio_o & ~( 1 << bit );
}

void gpio_toggle_port_bit(gpio_typedef* GPIO_, uint32_t bit){
    GPIO_->gpio_o = GPIO_->gpio_o ^  ( 1 << bit );
}
