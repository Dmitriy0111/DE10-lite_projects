/*
*  File            :   main.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.25
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
#define TEST_CAM_FUNC 1

#if   RUNTYPE == SIM
    #define delay_value 10
#elif RUNTYPE == SYNTH
    #define delay_value 1000000
#endif

#define CHIP_VER_ADDR   0x00
#define CHIP_VER_VAL    0x1801

#define CAM_0_ADDR      0xBA
#define CAM_1_ADDR      0x90

#define RST_NUM         7
#define STB_2_NUM       6
#define STB_1_NUM       5

uint8_t hex2ascii(uint32_t hex_v, uint8_t num);

uint8_t chip_addr;
uint8_t reg_addr = 0;

char first_msg[] = "i2c_test_cam_c Rev_1.0\n\r";

char con_msg[] = "CAM_x reg 0xxx = ";
char chip_ver_msg[] = "0x0000\n\r";
uint8_t i2c_buf[3] = {CHIP_VER_ADDR, 0x00, 0x00};

#if TEST_CAM_FUNC == 1
void test_cam(uint8_t index){
    con_msg[4] = index + 0x30;
    con_msg[12] = hex2ascii(reg_addr,1);
    con_msg[13] = hex2ascii(reg_addr,0);
    uart_send_msg(UART_0, con_msg, sizeof(con_msg));
    chip_addr = index ? CAM_1_ADDR : CAM_0_ADDR;
    i2c_buf[0] = reg_addr;
    if( i2c_read( I2C_0,chip_addr,i2c_buf,1,i2c_buf,3 ) )
        GPIO_0->gpio_o = GPIO_0->gpio_o | 0x01;
    else
        GPIO_0->gpio_o = GPIO_0->gpio_o & ~0x01;
    chip_ver_msg[2] = hex2ascii(i2c_buf[0],1);
    chip_ver_msg[3] = hex2ascii(i2c_buf[0],0);
    chip_ver_msg[4] = hex2ascii(i2c_buf[1],1);
    chip_ver_msg[5] = hex2ascii(i2c_buf[1],0);
    uart_send_msg(UART_0, chip_ver_msg, sizeof(chip_ver_msg));
}
#endif

void main (void)
{
    // settings for i2c interface
    I2C_0->i2c_ctrl = 0x0D;
    I2C_0->i2c_scl_low = 2000;
    I2C_0->i2c_scl_high = 2000;
    I2C_0->i2c_sda_hold = 1000;
    GPIO_0->gpio_o = (1 << RST_NUM) | (1 << STB_2_NUM) | (1 << STB_1_NUM);
    uart_send_msg(UART_0, first_msg, sizeof(first_msg));
    delay(delay_value);
    while(1)
    {
        delay(delay_value);

        #if   TEST_CAM_FUNC == 1
            test_cam(0);
            test_cam(1);
            reg_addr++;
        #elif TEST_CAM_FUNC == 0
            con_msg[4] = '0';
            uart_send_msg(UART_0, con_msg, sizeof(con_msg));
            chip_addr = CAM_0_ADDR;
            i2c_buf[0] = CHIP_VER_ADDR;
            if( i2c_read( I2C_0,chip_addr,i2c_buf,1,i2c_buf,3 ) )
                GPIO_0->gpio_o = GPIO_0->gpio_o | 0x01;
            else
                GPIO_0->gpio_o = GPIO_0->gpio_o & ~0x01;
            chip_ver_msg[2] = hex2ascii(i2c_buf[0],1);
            chip_ver_msg[3] = hex2ascii(i2c_buf[0],0);
            chip_ver_msg[4] = hex2ascii(i2c_buf[1],1);
            chip_ver_msg[5] = hex2ascii(i2c_buf[1],0);
            uart_send_msg(UART_0, chip_ver_msg, sizeof(chip_ver_msg));
            con_msg[4] = '1';
            i2c_buf[0] = CHIP_VER_ADDR;
            uart_send_msg(UART_0, con_msg, sizeof(con_msg));
            chip_addr = CAM_1_ADDR;
            if( i2c_read( I2C_0,chip_addr,i2c_buf,1,i2c_buf,3 ) )
                GPIO_0->gpio_o = GPIO_0->gpio_o | 0x01;
            else
                GPIO_0->gpio_o = GPIO_0->gpio_o & ~0x01;
            chip_ver_msg[2] = hex2ascii(i2c_buf[0],1);
            chip_ver_msg[3] = hex2ascii(i2c_buf[0],0);
            chip_ver_msg[4] = hex2ascii(i2c_buf[1],1);
            chip_ver_msg[5] = hex2ascii(i2c_buf[1],0);
            uart_send_msg(UART_0, chip_ver_msg, sizeof(chip_ver_msg));
        #endif
    }
}

uint8_t hex2ascii(uint32_t hex_v, uint8_t num){
    hex_v = hex_v >> (num << 2);
    hex_v = 0x0F & hex_v;
    hex_v = hex_v <= 0x09 ? hex_v + 0x30 : hex_v + 0x41 - 0x0A;
    return hex_v;
}
