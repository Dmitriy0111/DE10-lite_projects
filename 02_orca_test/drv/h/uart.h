/*
*  File            :   uart.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.24
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with uart
*  Copyright(c)    :   2019 Vlasov D.V.
*/

//#include "sys_cfg.h"

#define UART_BASE   0x00010020
#define UART_0_BASE ( UART_BASE + 0x00 )

typedef struct{
    volatile    unsigned    uart_rx;        // receive data
    volatile    unsigned    uart_tx;        // transmit data
    volatile    unsigned    uart_status;    // status register
    volatile    unsigned    uart_control;   // control register
    volatile    unsigned    uart_divisor;   // divisor register
    volatile    unsigned    uart_eof;       // end-of-packet
} uart_typedef;

#define UART_0  ( (uart_typedef *) UART_0_BASE)
