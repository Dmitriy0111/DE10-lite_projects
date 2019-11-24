/*
*  File            :   i2c.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with i2c
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "..\h\i2c.h"

int read_mem(i2c_typedef* I2C_, unsigned* msg, unsigned msg_len, unsigned int* read_val){
    for(int i=0 ; i<msg_len ; i++){
        I2C_->i2c_tfr_cmd = msg[i];
        while( ( (I2C_->i2c_isr) & 0x01 ) == 0 );
        if( ( ( I2C_->i2c_isr & 0x04 ) == 0x04 ) && ( ( msg[i] & STO ) != 0 ) )
            return 0;
        *read_val = I2C_->i2c_rx_data;
    }
    return 1;
}
