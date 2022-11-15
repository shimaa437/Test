/*
 * DIO_private.h
 *
 *  Created on: Jul 5, 2022
 *      Author: Shimaa Ismail
 *
 */
#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_

/*
 * This file it's a private file to the driver
 * contains the following :
 * private(Not sharable) Macros
 * private(Not sharable) function like Macros
 * static function
 */
/**********PORTA Registers************/
#define PORTA_REG *((volatile u8*)0x3B)  //OUTPUT DATA REGISTER//
#define DDRA_REG  *((volatile u8*)0x3A) //
#define PINA_REG  *((volatile u8*)0x39) //

/**********PORTB Registers************/
#define PORTB_REG *((volatile u8*)0x38)
#define DDRB_REG  *((volatile u8*)0x37)
#define PINB_REG  *((volatile u8*)0x36)

/**********PORTC Registers************/
#define PORTC_REG *((volatile u8*)0x35)
#define DDRC_REG  *((volatile u8*)0x34)
#define PINC_REG  *((volatile u8*)0x33)

/**********PORTD Registers************/
#define PORTD_REG *((volatile u8*)0x32)
#define DDRD_REG  *((volatile u8*)0x31)
#define PIND_REG  *((volatile u8*)0x30)


/*************Function Like Macros************/
#define CONC(b0,b1,b2,b3,b4,b5,b6,b7) CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7);
#define CONC_HELP(b0,b1,b2,b3,b4,b5,b6,b7)   0b##b7##b6##b5##b4##b3##b2##b1##b0;





#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
