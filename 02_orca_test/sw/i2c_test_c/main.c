/*
*  File            :   main.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is examples for working with GPIO, UART, I2C with orca riscv core
*  Copyright(c)    :   2019 Vlasov D.V.
*/

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

#define ADXL345         0x1D
#define ADXL345_ALT     0x53
#define ADXL345WA       ( ( ADXL345 << 1 ) | 0x00 )
#define ADXL345RA       ( ( ADXL345 << 1 ) | 0x01 )
#define ADXL345WA_ALT   ( ( ADXL345_ALT << 1 ) | 0x00 )
#define ADXL345RA_ALT   ( ( ADXL345_ALT << 1 ) | 0x01 )

uint8_t hex2ascii(uint32_t hex_v, uint8_t num);

char con_msg[19] = "Connected device = ";
char devid_msg[6] = "0x00\n\r";
uint16_t i2c_tx_msg[5] = {STA | ADXL345WA, DEVID_ADDR, STA | ADXL345RA, DEVID_ADDR, STO | 0x00};
char     i2c_rx_msg[5] = {0x00, 0x00, 0x00, 0x00, 0x00};

void main (void)
{
    // settings for i2c interface
    I2C_0->i2c_ctrl = 0x0D;
    I2C_0->i2c_scl_low = 2000;
    I2C_0->i2c_scl_high = 2000;
    I2C_0->i2c_sda_hold = 1000;
    GPIO_0->gpio_o = 0x00;

    while(1)
    {
        delay(delay_value);
        uart_send_msg(UART_0, con_msg, sizeof(con_msg));
        GPIO_0->gpio_o = i2c_read(I2C_0,i2c_tx_msg,i2c_rx_msg,sizeof(i2c_rx_msg));
        devid_msg[2] = hex2ascii(i2c_rx_msg[4],1);
        devid_msg[3] = hex2ascii(i2c_rx_msg[4],0);
        uart_send_msg(UART_0, devid_msg, sizeof(devid_msg));
    }
}

uint8_t hex2ascii(uint32_t hex_v, uint8_t num){
    hex_v = hex_v >> (num << 2);
    hex_v = 0x0F & hex_v;
    hex_v = hex_v <= 0x09 ? hex_v + 0x30 : hex_v + 0x41 - 0x0A;
    return hex_v;
}
