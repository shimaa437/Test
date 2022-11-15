/*
 * TIMER0_private.h
 *
 *  Created on: Jul 25, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef TIMER0_TIMER0_PRIVATE_H_
#define TIMER0_TIMER0_PRIVATE_H_

#define NORMAL_MODE    1
#define CTC_MODE       2
#define NON_INVERTED   1
#define INVERTED       2
#define FAST_PWM       1
#define PHASE_COREECT  2

#define  TCCR0_REG    *((volatile u8*)0x53)
#define  FOC0    7
#define  WGM00   6
#define  COM01   5
#define  COM00   4
#define  WGM01   3
#define  CS02    2
#define  CS01    1
#define  CS00    0


#define  TIMSK_REG    *((volatile u8*)0x59)
#define  TOIE0   0
#define  OCIE0   1

#define TCNT0_REG     *((volatile u8*)0x52)

#define OCR0_REG      *((volatile u8*)0x5C)

#endif /* TIMER0_TIMER0_PRIVATE_H_ */
