#include "../drv/h/gpio.h"

void main(){
    GPIO_GPO_OUT(GPIO_0_BASE,0x20);
    while(1){
        GPIO_GPO_OUT(GPIO_0_BASE,GPIO_GPI_IN(GPIO_0_BASE));
    }
}
