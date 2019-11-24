/*
*  File            :   main.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.2105
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

#define hex2ascii(val,num)  ( ( ( val >> ( 4 * num ) ) & 0x0F ) ) <= 0x09 ? ( ( ( val >> ( 4 * num ) ) & 0x0F ) + 0x30 ) : ( ( ( val >> ( 4 * num ) ) & 0x0F ) + 0x41 - 10 )

char con_msg[19] = "Connected device = ";
unsigned i2c_msg[5] = {STA | ADXL345WA, DEVID_ADDR, STA | ADXL345RA, DEVID_ADDR, 0x00};

void main (void)
{
    unsigned rec_val= 0x00;
    // set i2c frequency
    I2C_0->i2c_ctrl = 0x0D;
    I2C_0->i2c_scl_low = 2000;
    I2C_0->i2c_scl_high = 2000;
    I2C_0->i2c_sda_hold = 1000;
    GPIO_0->gpio_o = 0x00;

    while(1)
    {
        delay(delay_value);
        for(int i=0;i<19;i++){
            UART_0->uart_tx=con_msg[i];
            while( ( UART_0->uart_status & 0x40 ) == 0 );
        }
        GPIO_0->gpio_o = read_mem(I2C_0,i2c_msg,5,&rec_val);
        UART_0->uart_tx=hex2ascii(rec_val,1);
        while( ( UART_0->uart_status & 0x40 ) == 0 );
        UART_0->uart_tx=hex2ascii(rec_val,0);
        while( ( UART_0->uart_status & 0x40 ) == 0 );
        UART_0->uart_tx=0x0A;
        while( ( UART_0->uart_status & 0x40 ) == 0 );
        UART_0->uart_tx=0x0D;
        while( ( UART_0->uart_status & 0x40 ) == 0 );
    }
}
