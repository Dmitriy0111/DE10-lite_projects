/*
*  File            :   i2c.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with i2c
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#ifndef __I2C_H
#define __I2C_H

#include "risc_v_types.h"

typedef struct{
    volatile    uint32_t    i2c_tfr_cmd;            // Transfer command FIFO
    volatile    uint32_t    i2c_rx_data;            // Receive data FIFO
    volatile    uint32_t    i2c_ctrl;               // Control register
    volatile    uint32_t    i2c_iser;               // Interrupt status enable register
    volatile    uint32_t    i2c_isr;                // Interrupt status register
    volatile    uint32_t    i2c_status;             // Status register
    volatile    uint32_t    i2c_tfr_cmd_fifo_lvl;   // TFR_CMD FIFO level register
    volatile    uint32_t    i2c_rx_data_fifo_lvl;   // RX_DATA FIFO level register
    volatile    uint32_t    i2c_scl_low;            // SCL low count register
    volatile    uint32_t    i2c_scl_high;           // SCL high count register
    volatile    uint32_t    i2c_sda_hold;           // SDA hold count register
} i2c_typedef;

#define STA         0x200
#define STO         0x100

#define READ_OP     0x01
#define WRITE_OP    0x00
/*
    i2c_read() is function for reading message over i2c interface
    I2C_ is pointer to current I2C interface(typedef)
    chip_addr is chip address for reading data
    tx_msg is pointer for sending data
    rx_msg is pointer for receiving data
    tx_msg_len is lenght of sending data
    rx_msg_len is lenght of receiving data
*/
int i2c_read(i2c_typedef* I2C_, uint8_t chip_addr, uint8_t* tx_msg, uint32_t tx_msg_len, uint8_t* rx_msg, uint32_t rx_msg_len);
/*
    i2c_write() is function for writing message over i2c interface
    I2C_ is pointer to current I2C interface(typedef)
    chip_addr is chip address for writing data
    tx_msg is pointer for sending data
    msg_len is lenght of transaction
*/
int i2c_write(i2c_typedef* I2C_, uint8_t chip_addr, uint8_t* tx_msg, uint32_t msg_len);

#endif // __I2C_H
