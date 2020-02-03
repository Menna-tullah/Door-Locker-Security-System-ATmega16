/*
 * eeprom.h
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#define ERROR 0
#define SUCCESS 1

void EEPROM_init(void);
uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);

#endif /* EEPROM_H_ */
