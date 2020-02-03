/*
 * UART.h
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */

#ifndef UART_H_
#define UART_H_

#include"common_macros.h"
#include"std_types.h"
#include"micro_config.h"

/*********************** preprocessor macros ****************************/
#define UART_BAUDRATE 9600

/*********************** Function prototypes ****************************/
void UART_init(void);
void UART_sendByte(const uint8);
uint8 UART_recieveByte(void);
void UART_sendString(const uint8 *str);
void UART_recieveString(uint8 *str); /* recieve till '*' */

#endif
