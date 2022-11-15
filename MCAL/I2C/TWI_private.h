/*
 * I2C_private.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef I2C_TWI_PRIVATE_H_
#define I2C_TWI_PRIVATE_H_

#define  TWI_MASTER_MODE   1
#define  TWI_SLAVE_MODE    2


#define TWPR_REG   *((volatile u8*)0x20)

#define TWSR_REG   *((volatile u8*)0x21)

#define TWAR_REG   *((volatile u8*)0x22)

#define TWCR_REG   *((volatile u8*)0x56)
#define TWIE       0
#define TWEN       2
#define TWSTO      4
#define TWSTA      5
#define TWEA       6
#define TWINT      7

#define TWDR_REG   *((volatile u8*)0x23)

#define TWI_START_COND_ACK            0x08
#define TWI_REPEATED_START_ACK        0x10
#define TWI_SEND_SLAVE_ADD_WRITE_ACK  0x18
#define TWI_SEND_SLAVE_ADD_READ_ACK   0x40
#define TWI_SEND_BYTE_ACK             0x28
#define TWI_READ_BYTE_ACK             0x50

#endif /* I2C_TWI_PRIVATE_H_ */
