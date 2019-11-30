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
    chip_addr is chip address for reading data
    tx_msg is pointer for sending data
    rx_msg is pointer for receiving data
    tx_msg_len is lenght of sending data
    rx_msg_len is lenght of receiving data
*/
int i2c_read(i2c_typedef* I2C_, uint8_t chip_addr, uint8_t* tx_msg, uint32_t tx_msg_len, uint8_t* rx_msg, uint32_t rx_msg_len){
    // send chip address and write
    I2C_->i2c_tfr_cmd = STA | chip_addr | WRITE_OP;
    while( !( (I2C_->i2c_isr) & 0x01 ) );
    if( I2C_->i2c_isr & 0x04 )
        return 0;
    // send tx data (reg address)
    for(int i=0 ; i<tx_msg_len ; i++){
        if( ( i != tx_msg_len-1 ) ) {
            I2C_->i2c_tfr_cmd = tx_msg[i];
            while( !( (I2C_->i2c_isr) & 0x01 ) );
            if( ( I2C_->i2c_isr & 0x04 ) )
                return 0;
        } else {
            I2C_->i2c_tfr_cmd = tx_msg[i];
            while( !( (I2C_->i2c_isr) & 0x01 ) );
        }
    }
    // send chip address and read
    I2C_->i2c_tfr_cmd = STA | chip_addr | READ_OP;
    while( !( (I2C_->i2c_isr) & 0x01 ) );
    if( I2C_->i2c_isr & 0x04 )
        return 0;
    // receive data
    for(int i=0 ; i<rx_msg_len ; i++){
        if( ( i != rx_msg_len-1 ) ) {
            I2C_->i2c_tfr_cmd = rx_msg[i];
            while( !( (I2C_->i2c_isr) & 0x01 ) );
            if( ( I2C_->i2c_isr & 0x04 ) )
                return 0;
        } else {
            I2C_->i2c_tfr_cmd = rx_msg[i] | STO;
            while( !( (I2C_->i2c_isr) & 0x01 ) );
        }
        while( !( (I2C_->i2c_isr) & 0x02 ) );
        rx_msg[i] = I2C_->i2c_rx_data;
    }

    return 1;
}
/*
    i2c_write() is function for writing message over i2c interface
    I2C_ is pointer to current I2C interface(typedef)
    chip_addr is chip address for writing data
    tx_msg is pointer for sending data
    msg_len is lenght of transaction
*/
int i2c_write(i2c_typedef* I2C_, uint8_t chip_addr, uint8_t* tx_msg, uint32_t msg_len){
    // send chip address and write
    I2C_->i2c_tfr_cmd = STA | chip_addr | WRITE_OP;
    while( !( (I2C_->i2c_isr) & 0x01 ) );
    if( I2C_->i2c_isr & 0x04 )
        return 0;

    // send reg address and tx data
    for(int i=0 ; i<msg_len ; i++){
        if( ( i != msg_len-1 ) ) {
            I2C_->i2c_tfr_cmd = tx_msg[i];
            while( !( (I2C_->i2c_isr) & 0x01 ) );
            if( ( I2C_->i2c_isr & 0x04 ) )
                return 0;
        } else {
            I2C_->i2c_tfr_cmd = tx_msg[i] | STO;
            while( !( (I2C_->i2c_isr) & 0x01 ) );
        }
    }
    return 1;
}
