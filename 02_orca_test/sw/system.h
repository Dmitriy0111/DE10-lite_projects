#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "..\drv\h\gpio.h"
#include "..\drv\h\uart.h"
#include "..\drv\h\i2c.h"

#define PERIPHERY_BASE      0x00010000

#define GPIO_0_BASE         ( PERIPHERY_BASE + 0x00000000 )
#define UART_0_BASE         ( PERIPHERY_BASE + 0x00000020 )
#define I2C_0_BASE          ( PERIPHERY_BASE + 0x00000040 )

#define GPIO_0              ( (gpio_typedef *) GPIO_0_BASE )
#define I2C_0               ( (i2c_typedef  *) I2C_0_BASE  )
#define UART_0              ( (uart_typedef *) UART_0_BASE )

#endif // __SYSTEM_H
