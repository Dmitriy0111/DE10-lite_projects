/*
*  File            :   uart.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with uart
*  Copyright(c)    :   2019 Vlasov D.V.
*/

#ifndef __UART_H
#define __UART_H

#include "risc_v_types.h"

typedef struct{
    volatile    uint32_t    uart_rx;        // receive data
    volatile    uint32_t    uart_tx;        // transmit data
    volatile    uint32_t    uart_status;    // status register
    volatile    uint32_t    uart_control;   // control register
    volatile    uint32_t    uart_divisor;   // divisor register
    volatile    uint32_t    uart_eof;       // end-of-packet
} uart_typedef;

void uart_send_symbol(uart_typedef* UART_, char symbol);
void uart_send_msg(uart_typedef* UART_, char* msg, uint32_t msg_len);

#endif // __UART_H
