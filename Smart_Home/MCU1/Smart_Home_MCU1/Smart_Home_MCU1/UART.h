/*
 * UART.h
 *
 * Created: 4/23/2021 1:58:17 PM
 *  Author: ArtDeco
 */ 

#include "BIT_Math.h"
#include "MCU.h"
#include "STD.h"


#ifndef UART_H_
#define UART_H_

void UART_Init(void);

void UART_Tx(uint8 data);

void UART_TxString(uint8* str);

uint8 UART_Rx(void);





#endif /* UART_H_ */