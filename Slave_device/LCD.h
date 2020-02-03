/*
 * LCD.h
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */

#ifndef LCD_H_
#define LCD_H_

#include"std_types.h"
#include"micro_config.h"
#include"common_macros.h"

/******************** preprocessor macros *************************/
#define RS PB5
#define E PB7
#define RW PB6

/* LCD HW pins */
#define LCD_CTRL_PORT PORTB
#define LCD_CTRL_PORT_DIR DDRB

#define LCD_DATA_PORT PORTA
#define LCD_DATA_PORT_DIR DDRA

/* LCD commands */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80


/******************** Function prototypes ************************/
void LCD_init();
void LCD_sendCommand(uint8 cmd);
void LCD_displayChar(const uint8 data);
void LCD_integerToString(uint8 data);
void LCD_clearScreen(void);
void LCD_displayString(const char *str);
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);
void LCD_goToRowColumn(uint8 row,uint8 col);



#endif /* LCD_H_ */
