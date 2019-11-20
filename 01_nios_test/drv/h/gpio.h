/*
*  File            :   gpio.h
*  Autor           :   Vlasov D.V.
*  Data            :   2019.11.18
*  Language        :   C
*  Description     :   This is constants, macros and functions for working with gpio
*  Copyright(c)    :   2019 Vlasov D.V.
*/

//#include "sys_cfg.h"

#define GPIO_BASE   0x00010000
#define GPIO_0_BASE ( GPIO_BASE + 0x00 )

#define GPIO_GPI    0x00
#define GPIO_GPO    0x04
#define GPIO_GPD    0x08
#define GPIO_IRQ_M  0x0C
#define GPIO_CAP    0x10
#define GPIO_IRQ_V  0x14

// macro for working with gpi (gpio input) register
#define GPIO_GPI_IN(BASE)           __builtin_ldwio ( (void *) (BASE + GPIO_GPI)         )
// macro for working with gpo (gpio output) register
#define GPIO_GPO_IN(BASE)           __builtin_ldwio ( (void *) (BASE + GPIO_GPO)         )
#define GPIO_GPO_OUT(BASE, VAL)     __builtin_stwio ( (void *) (BASE + GPIO_GPO)   , VAL )
// macro for working with gpd (gpio direction) register
#define GPIO_GPD_IN(BASE)           __builtin_ldwio ( (void *) (BASE + GPIO_GPD)         )
#define GPIO_GPD_OUT(BASE, VAL)     __builtin_stwio ( (void *) (BASE + GPIO_GPD)   , VAL )
// macro for working with interrupt mask register
#define GPIO_IRQ_M_IN(BASE)         __builtin_ldwio ( (void *) (BASE + GPIO_IRQ_M)       )
#define GPIO_IRQ_M_OUT(BASE, VAL)   __builtin_stwio ( (void *) (BASE + GPIO_IRQ_M) , VAL )
// macro for working with capture input register
#define GPIO_CAP_IN(BASE)           __builtin_ldwio ( (void *) (BASE + GPIO_CAP)         )
#define GPIO_CAP_OUT(BASE, VAL)     __builtin_stwio ( (void *) (BASE + GPIO_CAP)   , VAL )
// macro for working with interrupt input register
#define GPIO_IRQ_V_IN(BASE)         __builtin_ldwio ( (void *) (BASE + GPIO_IRQ_V)       )
#define GPIO_IRQ_V_OUT(BASE, VAL)   __builtin_stwio ( (void *) (BASE + GPIO_IRQ_V) , VAL )
