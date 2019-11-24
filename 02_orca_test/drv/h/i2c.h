/*
*  File            :   i2c.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with i2c
*  Copyright(c)    :   2019 Vlasov D.V.
*/

//#include "sys_cfg.h"

#define I2C_BASE    0x00010040
#define I2C_0_BASE  ( I2C_BASE + 0x00 )

typedef struct{
    volatile    unsigned    i2c_tfr_cmd;            // Transfer command FIFO
    volatile    unsigned    i2c_rx_data;            // Receive data FIFO
    volatile    unsigned    i2c_ctrl;               // Control register
    volatile    unsigned    i2c_iser;               // Interrupt status enable register
    volatile    unsigned    i2c_isr;                // Interrupt status register
    volatile    unsigned    i2c_status;             // Status register
    volatile    unsigned    i2c_tfr_cmd_fifo_lvl;   // TFR_CMD FIFO level register
    volatile    unsigned    i2c_rx_data_fifo_lvl;   // RX_DATA FIFO level register
    volatile    unsigned    i2c_scl_low;            // SCL low count register
    volatile    unsigned    i2c_scl_high;           // SCL high count register
    volatile    unsigned    i2c_sda_hold;           // SDA hold count register
} i2c_typedef;

#define I2C_0   ( (i2c_typedef *) I2C_0_BASE)

#define STA         0x200
#define STO         0x100

int read_mem(i2c_typedef* I2C_, unsigned* msg, unsigned msg_len, unsigned int* read_val);
