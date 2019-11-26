/*
*  File            :   i2c.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with i2c
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "risc_v_types.h"

#define I2C_BASE    0x00010040
#define I2C_0_BASE  ( I2C_BASE + 0x00 )

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

#define I2C_0   ( (i2c_typedef *) I2C_0_BASE)

#define STA         0x200
#define STO         0x100
/*
    i2c_read() is function for reading message over i2c interface
    I2C_ is pointer to current I2C interface(typedef)
    tx_msg is pointer for sending data
    rx_msg is pointer for receiving data
    msg_len is lenght of transaction
*/
int i2c_read(i2c_typedef* I2C_, uint16_t* tx_msg, char* rx_msg, uint32_t msg_len);
/*
    i2c_write() is function for writing message over i2c interface
    I2C_ is pointer to current I2C interface(typedef)
    tx_msg is pointer for sending data
    msg_len is lenght of transaction
*/
int i2c_write(i2c_typedef* I2C_, uint16_t* tx_msg, uint32_t msg_len);
