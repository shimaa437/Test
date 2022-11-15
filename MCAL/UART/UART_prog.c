/*
 * UART_prog.c
 *
 *  Created on: Jul 31, 2022
 *      Author: Shimaa_Ismail
 */

#include "UART_int.h"

void M_UART_void_Init(void)
{
	u8 Local_u8UCSRCValue = 0b10000000;
#if   UART_CHARACTER_SIZE   ==   8
	SET_BIT(Local_u8UCSRCValue,UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSZ1);
	CLR_BIT(UCSRB_REG,UCSZ2);
#elif UART_CHARACTER_SIZE   ==   7
	CLR_BIT(Local_u8UCSRCValue,UCSZ0);
	SET_BIT(Local_u8UCSRCValue,UCSZ1);
	CLR_BIT(UCSRB_REG,UCSZ2);
#elif UART_CHARACTER_SIZE   ==   6
	SET_BIT(Local_u8UCSRCValue,UCSZ0);
	CLR_BIT(Local_u8UCSRCValue,UCSZ1);
	CLR_BIT(UCSRB_REG,UCSZ2);
#elif UART_CHARACTER_SIZE   ==   5
	CLR_BIT(Local_u8UCSRCValue,UCSZ0);
	CLR_BIT(Local_u8UCSRCValue,UCSZ1);
	CLR_BIT(UCSRB_REG,UCSZ2);
#endif
#if   UART_STOP_BITS   ==   1
	CLR_BIT(Local_u8UCSRCValue,USBS);
#elif UART_STOP_BITS   ==   2
	SET_BIT(Local_u8UCSRCValue,USBS);
#endif
#if   UART_PARITY_MODE   ==   ENABLE_PARITY_EVEN
	CLR_BIT(Local_u8UCSRCValue,UPM0);
	SET_BIT(Local_u8UCSRCValue,UPM1);
#elif UART_PARITY_MODE   ==   ENABLE_PARITY_ODD
	SET_BIT(Local_u8UCSRCValue,UPM0);
	SET_BIT(Local_u8UCSRCValue,UPM1);
#elif UART_PARITY_MODE   ==   DIABLE_PARITY
	CLR_BIT(Local_u8UCSRCValue,UPM0);
	CLR_BIT(Local_u8UCSRCValue,UPM1);
#endif
	UCSRC_REG = Local_u8UCSRCValue;
	/* to enable tx and rx circiuit */
	SET_BIT(UCSRB_REG,RXEN);
	SET_BIT(UCSRB_REG,TXEN);
}
void M_UART_void_SetBaudRate(u32 Copy_u32BaudRate)
{
	/* to select 9600 baud rate */
	UBRRL_REG = ((F_OSC * 1000000) / (16 * Copy_u32BaudRate)) - 1;
}
void M_UART_void_Tx(u8 Copy_u8Data)
{
	UDR_REG = Copy_u8Data;
	u32 Local_u32Counter = 0;
	while(Local_u32Counter < 500000)
	{
		Local_u32Counter++;
		if(GET_BIT(UCSRA_REG,TXC) == 1)
			break;
	}
}
void M_UART_void_Rx(u8*Copy_u8PtrData)
{
	u32 Local_u32Counter = 0;
	while(Local_u32Counter < 500000)
	{
		Local_u32Counter++;
		if(GET_BIT(UCSRA_REG,RXC) == 1)
			break;
	}
	*Copy_u8PtrData = UDR_REG;
}
