/*
 * ADC_prog.c
 *
 *  Created on: Jul 21, 2022
 *      Author: zas
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_int.h"

void M_ADC_void_init(prescaler_t copy_u8prescaer, vref_t copy_u8vref)
{
  //step 1: choose prescaler
	ADCSRA_REG &= PRESCALER_MASK;
	ADCSRA_REG |= (u8)copy_u8prescaer;
 //step 2 : Enable ADC
	SET_BIT(ADCSRA_REG, ADEN);
// step 3 : Disable Interrupt
	CLR_BIT(ADCSRA_REG, ADIE);
//step 4: disable auto trigger
	CLR_BIT(ADCSRA_REG, ADATE);
	//Step 5 :Adjust right//
	CLR_BIT(ADMUX_REG, ADLAR);
// step 6: Choose vref//ZZZZZZ
	ADMUX_REG &= VREFF_MASK;
  ADMUX_REG |= (((u8)copy_u8vref) << REFS0);
}


u16 M_ADC_u16_getValue(u8 copy_u8channel)
{
	//Step 1: Choose channel
	ADMUX_REG &= CHANNEL_MASK;
	ADMUX_REG |= copy_u8channel;
	// Step 2: play (start conversion)
	SET_BIT(ADCSRA_REG, ADSC);
	// Step 3: Wait until conversion is done (polling)
	while (GET_BIT(ADCSRA_REG, ADIF) == 0);

	// Step 4: return digital value

    return ADCL_REG ;
}


