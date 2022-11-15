/*
 * DIO_int.h
 *
 *  Created on: Jul 5, 2022
 *      Author: Shimaa Ismail
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_
#include "STD_TYPES.h"
/*Macros for ports IDs*/
#define PORTA_ID    0
#define PORTB_ID    1
#define PORTC_ID    2
#define PORTD_ID    3

/* Macros for pins IDs*/
#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2        2
#define DIO_PIN3        3
#define DIO_PIN4        4
#define DIO_PIN5        5
#define DIO_PIN6        6
#define DIO_PIN7        7

/*Macros for pin directions*/
#define PIN_DIRECTION_OUTPUT 1
#define PIN_DIRECTION_INPUT  0

#define HIGH           1
#define LOW            0

void M_DIO_void_Init(void);

/*
 * fn name: M_DIO_void_setpinDirectio
 * input: Port ID, Pin ID,
 */
void M_DIO_void_setpinDirection(u8 PortID,u8 PinID,u8 Direction);

void M_DIO_void_setpinValue(u8 PortID,u8 PinID,u8 Value);
void M_DIO_void_getPinValue(u8 PortID,u8 PinID, u8* PtrValue);
void M_DIO_void_TogglePinValue(u8 PortID, u8 PinID);

#endif /* MCAL_DIO_DIO_INT_H_ */
