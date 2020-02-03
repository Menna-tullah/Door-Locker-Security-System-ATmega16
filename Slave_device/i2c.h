/*
 * i2c.h
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */

#ifndef I2C_H_
#define I2C_H_

#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"

/*************************** preprocessor macros ****************************/
#define TWI_SATRT 		   0x08
#define TWI_REPEATED_START 0x10
#define TWI_MT_DATA_ACK    0x28
#define TWI_MT_SLA_W_ACK   0x18
#define TWI_MT_SLA_R_ACK   0x40
#define TWI_MR_DATA_ACK    0x50
#define TWI_MR_DATA_NACK   0x58

/*************************** Function prototypes ****************************/
void TWI_init(void);
void TWI_start(void);
void TWI_stop(void);
void TWI_write(uint8 data);
uint8 TWI_readWithAck(void);
uint8 TWI_readWithNACK(void); /* read without sending ACK */
uint8 TWI_getStatus(void);

#endif /* I2C_H_ */
