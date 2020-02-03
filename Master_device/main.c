/*
 * main.c
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */

#include"keypad.h"
#include"UART.h"


int main(void)
{
	uint8 num ;

	UART_init();
	while(1)
	{
		num = keypad_getPressedKey();
		if(num == '*')
		{
			break;
		}
		else {
		_delay_ms(500);
		UART_sendByte(num);
		}

	}
}
