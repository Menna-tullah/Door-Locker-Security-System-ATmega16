/*
 * LCD.c
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */

#include"LCD.h"

void LCD_init() {

	LCD_CTRL_PORT_DIR |= (1 << E) | (1 << RS) | (1 << RW); /* Rs, E, RW -> output pins */
	LCD_DATA_PORT_DIR = 0xFF; /* data port as output port */
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
	LCD_sendCommand(CURSOR_OFF);
	LCD_sendCommand(CLEAR_COMMAND);

}

void LCD_sendCommand(uint8 command) {

	CLEAR_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
	LCD_DATA_PORT = command;
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);

}

void LCD_displayChar(uint8 data) {
	SET_BIT(LCD_CTRL_PORT, RS);
	CLEAR_BIT(LCD_CTRL_PORT, RW);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
	LCD_DATA_PORT = data;
	_delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT, E);
	_delay_ms(1);
}

void LCD_displayString(const char *str) {
	uint8 i = 0;
	while (str[i] != '\0') {
		LCD_displayChar(str[i]);
		i++;
	}
}

void LCD_goToRowColumn(uint8 row, uint8 col) {
	uint8 Address;
	switch (row) {
	case 0:
		Address = col;
		break;
	case 1:
		Address = col + 0x40;
		break;
	case 2:
		Address = col + 0x10;
		break;
	case 3:
		Address = col + 0x50;
		break;
	}
	LCD_sendCommand(Address | SET_CURSOR_LOCATION);
}


void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str) {
	LCD_goToRowColumn(row, col);
	LCD_displayString(Str);
}


void LCD_intgerToString(uint8 data) {
	char buff[16];
	itoa(data, buff, 10);
	LCD_displayString(buff);
}


void LCD_clearScreen(void) {
	LCD_sendCommand(CLEAR_COMMAND); //clear display
}
