/*
 * i2c.c
 *
 *  Created on: Feb 3, 2020
 *      Author: menna
 */
#include"i2c.h"

/************************ Function definitions ***************************/
void TWI_init(void)
{
	/* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
	TWBR = (1<<0x02);
	TWSR = 0x00;

	TWAR = 0b00000010; /* address */

	TWCR = (1<<TWEN);
}

void TWI_start(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while(BIT_IS_CLEAR(TWCR,TWINT));
}

void TWI_stop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void TWI_write(uint8 data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
}

uint8 TWI_readWithAck(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);

	/* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR;
}

uint8 TWI_readWithNACK(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);

	/* Wait for TWINT flag set in TWCR Register (data received successfully) */
	while(BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR;
}

uint8 TWI_getStatus(void)
{
	uint8 status;
	status = TWSR&0xF8;
	return status;
}
