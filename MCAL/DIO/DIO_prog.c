/*
 * DIO_prog.c
 *
 *  Created on: Jul 5, 2022
 *      Author: shimaa Ismail
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_int.h"
#include "DIO_config.h"

void M_DIO_void_Init(void)
{
 DDRA_REG = CONC(PA0_DIR,PA1_DIR,PA2_DIR,PA3_DIR,PA4_DIR,PA5_DIR,PA6_DIR,PA7_DIR);
 DDRB_REG = CONC(PB0_DIR,PB1_DIR,PB2_DIR,PB3_DIR,PB4_DIR,PB5_DIR,PB6_DIR,PB7_DIR);
 DDRC_REG = CONC(PC0_DIR,PC1_DIR,PC2_DIR,PC3_DIR,PC4_DIR,PC5_DIR,PC6_DIR,PC7_DIR);
 DDRD_REG = CONC(PD0_DIR,PD1_DIR,PD2_DIR,PD3_DIR,PD4_DIR,PD5_DIR,PD6_DIR,PD7_DIR);
}
void M_DIO_void_setpinDirection(u8 PortID,u8 PinID,u8 Direction)
{
	switch (PortID)
	{
	case PORTA_ID:
		 CLR_BIT(DDRA_REG ,PinID);
		 DDRA_REG |= Direction << PinID;
		 break;
    case PORTB_ID:
		CLR_BIT(DDRB_REG ,PinID);
		DDRB_REG |= Direction << PinID;
		break;
	case PORTC_ID:
		CLR_BIT(DDRC_REG ,PinID);
		DDRC_REG |= Direction << PinID;
		break;
	case PORTD_ID:
		CLR_BIT(DDRD_REG ,PinID);
		DDRD_REG |= Direction << PinID;
		break;
	default:
		break;
	}
}

void M_DIO_void_setpinValue(u8 PortID,u8 PinID,u8 Value)
{
	switch (PortID)
	{
	case PORTA_ID:
			 CLR_BIT(PORTA_REG ,PinID);
			 PORTA_REG |= Value << PinID;
			 break;
	    case PORTB_ID:
			CLR_BIT(PORTB_REG ,PinID);
			PORTB_REG |= Value << PinID;
			break;
		case PORTC_ID:
			CLR_BIT(PORTC_REG ,PinID);
			PORTC_REG |= Value << PinID;
			break;
		case PORTD_ID:
			CLR_BIT(PORTD_REG ,PinID);
			PORTD_REG |= Value << PinID;
			break;
		default:
			break;
		}
}

void M_DIO_void_getPinValue(u8 PortID,u8 PinID, u8* PtrValue)
{
	switch (PortID)
		{
		case PORTA_ID: *PtrValue = GET_BIT(PINA_REG,PinID);break;
		case PORTB_ID: *PtrValue = GET_BIT(PINB_REG,PinID);break;
		case PORTC_ID: *PtrValue = GET_BIT(PINC_REG,PinID);break;
		case PORTD_ID: *PtrValue = GET_BIT(PIND_REG,PinID);break;
			default: break;
			}
}
void M_DIO_void_TogglePinValue(u8 PortID, u8 PinID)
{
	switch (PortID)
			{
			case PORTA_ID: TOG_BIT(PORTA_REG,PinID);break;
			case PORTB_ID: TOG_BIT(PORTB_REG,PinID);break;
			case PORTC_ID: TOG_BIT(PORTC_REG,PinID);break;
			case PORTD_ID: TOG_BIT(PORTD_REG,PinID);break;
				default: break;
			}
}



