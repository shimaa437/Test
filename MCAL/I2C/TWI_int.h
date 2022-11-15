/*
 * TWI_int.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef I2C_TWI_INT_H_
#define I2C_TWI_INT_H_
/************ INCLUDES ***********/
#include "TWI_config.h"
#include "TWI_private.h"
#include "DIO_int.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/************* PROTOTYPES *************/
void M_TWI_Void_Init(void);
void M_TWI_Void_StartCondition(void);
void M_TWI_Void_StopCondition(void);
void M_TWI_Void_RepeatedStart(void);
void M_TWI_Void_SendSlaveAddressWrite(u8);
void M_TWI_Void_SendSlaveAddressRead(u8);
void M_TWI_Void_SendByte(u8);
u8 M_TWI_u8_ReadByte(void);

#endif /* I2C_TWI_INT_H_ */
