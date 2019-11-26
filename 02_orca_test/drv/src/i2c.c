/*
*  File            :   i2c.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with i2c
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "..\h\i2c.h"

/*
    i2c_read() is function for reading message over i2c interface
    I2C_ is pointer to current I2C interface(typedef)
    tx_msg is pointer for sending data
    rx_msg is pointer for receiving data
    msg_len is lenght of transaction
*/
int i2c_read(i2c_typedef* I2C_, uint16_t* tx_msg, char* rx_msg, uint32_t msg_len){
    for(int i=0 ; i<msg_len ; i++){
        I2C_->i2c_tfr_cmd = tx_msg[i];
        while( !( (I2C_->i2c_isr) & 0x01 ) );
        if( ( I2C_->i2c_isr & 0x04 ) && ( i != msg_len-1 ) )
            return 0;
        rx_msg[i] = I2C_->i2c_rx_data;
    }
    return 1;
}
/*
    i2c_write() is function for writing message over i2c interface
    I2C_ is pointer to current I2C interface(typedef)
    tx_msg is pointer for sending data
    msg_len is lenght of transaction
*/
int i2c_write(i2c_typedef* I2C_, uint16_t* tx_msg, uint32_t msg_len){
    uint32_t dummy_buf;
    for(int i=0 ; i<msg_len ; i++){
        I2C_->i2c_tfr_cmd = tx_msg[i];
        while( !( (I2C_->i2c_isr) & 0x01 ) );
        if( ( I2C_->i2c_isr & 0x04 ) && ( i != msg_len-1 ) )
            return 0;
        dummy_buf = I2C_->i2c_rx_data;
    }
    return 1;
}
