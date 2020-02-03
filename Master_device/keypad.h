/*
 * keypad.h
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"common_macros.h"
#include"std_types.h"
#include"micro_config.h"

/*********************** preprocessor Macros **************************/
/* keypad configurations for number of columns  and rows */
#define N_col 3
#define N_row 4

/* keypad port configurations */
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN PINA
#define KEYPAD_PORT_DIR DDRA

/*********************** function prototypes ***************************/
uint8 keypad_getPressedKey(void);


#endif /* KEYPAD_H_ */
