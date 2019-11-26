/*
*  File            :   uart.c
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with uart
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#include "..\h\uart.h"
/*
    uart_send_symbol() is function for sending symbol over uart interface
    UART_ is pointer to current UART interface(typedef)
    symbol is sending symbol
*/
void uart_send_symbol(uart_typedef* UART_, char symbol){
    UART_->uart_tx=symbol;
    while( ( UART_->uart_status & 0x40 ) == 0 );
}
/*
    uart_send_msg() is function for sending message over uart interface
    UART_ is pointer to current UART interface(typedef)
    msg is pointer to sending message
    msg_len is length of sending message
*/
void uart_send_msg(uart_typedef* UART_, char* msg, uint32_t msg_len){
    for(uint32_t i=0 ; i<msg_len ; i++) {
        UART_->uart_tx=msg[i];
        while( ( UART_->uart_status & 0x40 ) == 0 );
    }
}
