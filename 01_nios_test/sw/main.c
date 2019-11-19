#include "../drv/h/gpio.h"

void main(){
    GPIO_0->gpio_o = 0x32;
    while(1){
        gpio_clr_port_bit(GPIO_0,1);
    }
}
