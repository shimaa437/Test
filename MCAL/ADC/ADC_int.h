/*
 * ADC_int.h
 *
 *  Created on: Jul 21, 2022
 *      Author: zas
 */

#ifndef ADC_ADC_INT_H_
#define ADC_ADC_INT_H_

typedef enum
{
	prescaler_2 = 1,    //1
	prescaler_4,        //2
	prescaler_8,        //3
	prescaler_16,       //4
	prescaler_32,       //5
	prescaler_64,       //6
	prescaler_128,      //7

}prescaler_t;

typedef enum
{
	vref_AREF,  //0
	vref_AVCC,  //1
	vref_Internal = 3
}vref_t;

void M_ADC_void_init(prescaler_t copy_u8prescaer,vref_t copy_u8vref);
u16 M_ADC_u16_getValue(u8 copy_u8channel);
#endif /* ADC_ADC_INT_H_ */
