

/*
 * SPI_prog.c
 *
 *  Created on: Aug 1, 2022
 *      Author: Shimaa_Ismail
 */

#include "SPI_int.h"

void M_SPI_Void_Init(void)
{
#if SPI_MODE == SPI_MASTER_MODE
	SET_BIT(SPCR_REG,MSTR);
	SET_BIT(SPCR_REG,SPR0);
	SET_BIT(SPCR_REG,SPR1);
    M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN4,PIN_DIRECTION_OUTPUT);
    M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN5,PIN_DIRECTION_OUTPUT);
    M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN6,PIN_DIRECTION_INPUT);
    M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN7,PIN_DIRECTION_OUTPUT);

#elif  SPI_MODE == SPI_SLAVE_MODE
	CLR_BIT(SPCR_REG,MSTR);
	M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN4,PIN_DIRECTION_INPUT);
	M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN5,PIN_DIRECTION_INPUT);
	M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN6,PIN_DIRECTION_OUTPUT);
	M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN7,PIN_DIRECTION_INPUT);
#endif
    /* To Send From LSB First */
	SET_BIT(SPCR_REG,DORD);
	/* TO Enable SPI Circuit */
	SET_BIT(SPCR_REG,SPE);

}

u8 M_SPI_Void_Transive(u8 Copy_u8Data)
{
	SPCR_REG = Copy_u8Data;
	while (GET_BIT(SPSR_REG,SPIF) == 0);

	return SPCR_REG;
}
