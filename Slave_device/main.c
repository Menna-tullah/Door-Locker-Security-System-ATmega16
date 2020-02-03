/*
 * main.c
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */


#include"LCD.h"
#include"UART.h"
#include"eeprom.h"

#define FULL_WAVE_STEPS 2

int main(void)
{

	UART_init();
	LCD_init();
	LCD_clearScreen();

	 uint8 pass[4];
	 uint8 i = 0, password = 0;
	uint8 val = 0;
	EEPROM_init();
	EEPROM_writeByte(0x0311, 0x0F); /* Write 0x0F in the external EEPROM */
	_delay_ms(10);
	EEPROM_readByte(0x0311, &val); /* value is equal 15 */
	uint8 motor_steps[FULL_WAVE_STEPS] = {12,6};
	DDRD |= 0xFC;
	PORTD = (PORTD&0x03)|(PORTD&0x00);

	while(1)
	{
		LCD_displayString("Enter:");
		for(i = 0; i < 4; i++)
		{
			pass[i] = UART_recieveByte();
			LCD_intgerToString(pass[i]);
		}
		password =pass[0]*1000+pass[1]*100+pass[2]*10+pass[3];

		if(password == (uint8)val)
		{

			PORTD = (motor_steps[1] & 0xFC) | (PORTD & 0x03);

			break;
		}else
		{
			LCD_displayString("ERROR!");
		}

}
}
