/*
 * TIMER1_int.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef TIMER1_TIMER1_INT_H_
#define TIMER1_TIMER1_INT_H_
#include "TIMER1_config.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_private.h"
#include "DIO_int.h"


void M_TIMER1_VoidPwm1Init(void);
void M_TIMER1_VoidPwm1SetFreq(u32);
void M_TIMER1_VoidPwm1SetDutyCycle(f32);
void M_TIMER1_VoidPwm1Start(void);
void M_TIMER1_VoidPwm1Stop(void);
#endif /* TIMER1_TIMER1_INT_H_ */
