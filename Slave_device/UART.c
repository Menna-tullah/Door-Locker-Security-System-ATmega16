/*
 * UART.c
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */

#include "UART.h"

#define BAUD_PRESCALE (((F_CPU / (UART_BAUDRATE * 8UL))) - 1)

/************************* Function definitions ****************************/
void UART_init(void)
{
	/* reduce the divisor of the baud rate divider from 16 to 8 effectively doubling
	*	the transfer rate for asynchronous communication
	*/
	UCSRA = (1<<U2X);

	/*
	 * RXEN: Receiver Enable
	 * TXEN: Transmitter Enable
	 */
	UCSRB = (1<<RXEN)|(1<<TXEN);

	/* UCSZ1:0 = 11 For 8-bit data mode */
	UCSRC =  (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;

}

void UART_sendByte(const uint8 data)
{
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}
		UDR = data;
}

uint8 UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)){}
	return UDR;
}

void UART_sendString(const uint8 *str)
{
	while(*str != '\0')
	{
		UART_sendByte(*str);
		str++;
	}
}

void UART_recieveString(uint8 *str)
{
	uint8 i = 0;
	str[i] = UART_recieveByte();
	while(str[i] != '*')
	{
		UART_recieveByte();
		i++;
	}
	str[i] = '\0';
}


