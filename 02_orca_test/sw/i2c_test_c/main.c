/*
*  File            :   main.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is examples for working with GPIO, UART, I2C with orca riscv core
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "..\system.h"
#include "..\..\drv\h\gpio.h"
#include "..\..\drv\h\delay.h"
#include "..\..\drv\h\uart.h"
#include "..\..\drv\h\i2c.h"

#define SYNTH   1
#define SIM     0
#define RUNTYPE SYNTH

#if   RUNTYPE == SIM
    #define delay_value 10
#elif RUNTYPE == SYNTH
    #define delay_value 10000000
#endif

#define DEVID_ADDR  0x00
#define DEVID_VAL   0xE5

#define ADXL345         0x3A
#define ADXL345_ALT     0xA6

uint8_t hex2ascii(uint32_t hex_v, uint8_t num);

uint8_t chip_addr;

char con_msg[19] = "Connected device = ";
char devid_msg[6] = "0x00\n\r";
uint8_t i2c_buf[2] = {DEVID_ADDR, 0x00};

void main (void)
{
    // settings for i2c interface
    I2C_0->i2c_ctrl = 0x0D;
    I2C_0->i2c_scl_low = 2000;
    I2C_0->i2c_scl_high = 2000;
    I2C_0->i2c_sda_hold = 1000;
    GPIO_0->gpio_o = 0x00;

    chip_addr = ADXL345;

    while(1)
    {
        delay(delay_value);
        uart_send_msg(UART_0, con_msg, sizeof(con_msg));
        i2c_buf[0] = DEVID_ADDR;
        if( GPIO_0->gpio_o = i2c_read(I2C_0,chip_addr,i2c_buf,1,i2c_buf,2) )
            GPIO_0->gpio_o = GPIO_0->gpio_o | 0x01;
        else
            GPIO_0->gpio_o = GPIO_0->gpio_o & ~0x01;
        devid_msg[2] = hex2ascii(i2c_buf[1],1);
        devid_msg[3] = hex2ascii(i2c_buf[1],0);
        uart_send_msg(UART_0, devid_msg, sizeof(devid_msg));
    }
}

uint8_t hex2ascii(uint32_t hex_v, uint8_t num){
    hex_v = hex_v >> (num << 2);
    hex_v = 0x0F & hex_v;
    hex_v = hex_v <= 0x09 ? hex_v + 0x30 : hex_v + 0x41 - 0x0A;
    return hex_v;
}
