/*
 * TWI_prog.c
 *  Created on: Aug 2, 2022
 *      Author: Shimaa_Ismail
 */

#include "TWI_int.h"

void M_TWI_Void_Init(void)
{
#if TWI_MODE == TWI_MASTER_MODE
  TWPR_REG = (((F_OSC * 1000000) / F_SCL) - 16 ) / 2;
#elif TWI_MODE == TWI_SLAVE_MODE
  TWAR_REG = (SLAVE_ADDRESS << 1) | GENERAL_CALL;
#endif
  /* ENABLE TWI CIRCUIT */
  SET_BIT(TWCR_REG,TWEN);
}
void M_TWI_Void_StartCondition(void)
{
	SET_BIT(TWCR_REG,TWINT); //clear the flag by writing a logic 1 to it//
    SET_BIT(TWCR_REG,TWSTA);
    /*(internal check) cpu stuck to make sure the job(start condition) is done*/
    while (GET_BIT(TWCR_REG,TWINT) == 0);
    /* double check(external check) check on the data bus(possible the TWI circuit*/
    while ((TWSR_REG & 0XF8) != TWI_START_COND_ACK) ;
}
void M_TWI_Void_StopCondition(void)
{
	SET_BIT(TWCR_REG,TWSTO);
	SET_BIT(TWCR_REG,TWINT);   //clear the flag//
    //while (GET_BIT(TWCR_REG,TWINT) == 0);
    //while ((TWSR_REG & 0XF8) != TWI_STOP_COND_ACK) ;
}
void M_TWI_Void_RepeatedStart(void)
{
	SET_BIT(TWCR_REG,TWSTA);
	SET_BIT(TWCR_REG,TWINT);   //clear the flag//
	while (GET_BIT(TWCR_REG,TWINT) == 0);
	while ((TWSR_REG & 0XF8) != TWI_REPEATED_START_ACK) ;
}
void M_TWI_Void_SendSlaveAddressWrite(u8 Copy_u8Address)
{
  TWDR_REG = Copy_u8Address<<1;      //TWDR_REG=> 7-bit of address//
  SET_BIT(TWCR_REG,TWINT);          //clear the flag by writing a logic one to it//
  while (GET_BIT(TWCR_REG,TWINT) == 0);
  while ((TWSR_REG & 0XF8) != TWI_SEND_SLAVE_ADD_WRITE_ACK) ;
}
void M_TWI_Void_SendSlaveAddressRead(u8 Copy_u8Address)
{
	TWDR_REG = (Copy_u8Address << 1) | 1;
	CLR_BIT(TWCR_REG,TWSTA);
	SET_BIT(TWCR_REG,TWINT); //clear the flag//
	while (GET_BIT(TWCR_REG,TWINT) == 0);
	while ((TWSR_REG & 0XF8) != TWI_SEND_SLAVE_ADD_READ_ACK) ;
}
void M_TWI_Void_SendByte(u8 Copy_u8Data)
{
  TWDR_REG = Copy_u8Data ;
  CLR_BIT(TWCR_REG,TWSTA);
  SET_BIT(TWCR_REG,TWINT); //clear the flag//
  while (GET_BIT(TWCR_REG,TWINT) == 0);
  while ((TWSR_REG & 0XF8) != TWI_SEND_BYTE_ACK) ;
}
u8 M_TWI_u8_ReadByte(void)
{
  CLR_BIT(TWCR_REG,TWSTA);
  CLR_BIT(TWCR_REG,TWSTO);
  SET_BIT(TWCR_REG,TWEA);   //when master receive a byte and set bit to 1 make master send ACK to slave//
  SET_BIT(TWCR_REG,TWINT); //clear the flag by writing a logic 1 on it

  //
  u8 Local_u8Data = 0;
  Local_u8Data = TWDR_REG;
  while (GET_BIT(TWCR_REG,TWINT) == 0);
  while ((TWSR_REG & 0XF8) != TWI_READ_BYTE_ACK);

  return Local_u8Data;
}

