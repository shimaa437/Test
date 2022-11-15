/*
 * ADC_private.h
 *
 *  Created on: Jul 21, 2022
 *      Author: zas
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_

#define ADMUX_REG        *((volatile u8 *)0x27)
#define REFS1   7
#define REFS0   6
#define ADLAR   5

#define ADCSRA_REG       *((volatile u8 *)0x26)
#define  ADEN    7     // ADC Enable
#define  ADSC    6    // ADC Start conversion
#define  ADATE   5    //Auto Trigger =0
#define  ADIF    4    //conversion completet flag(interrupt flag)
#define  ADIE    3    // Interrupt Enalbe
#define  ADPS2   2    //prescaler2
#define  ADPS1   1   //prescaler1
#define  ADPS0   0  //prescaler0

//#define ADCH_REG         *((volatile u8 *)0x25)//
#define ADCL_REG         *((volatile u16 *)0x24)

#define SFIOR_REG        *((volatile u8 *)0x50)
#define ADTS2   7
#define ADTS1   6
#define ADTS0   5

#define PRESCALER_MASK   0b11111000

#define VREFF_MASK       0b00111111

#define  CHANNEL_MASK    0b11100000

#endif /* ADC_ADC_PRIVATE_H_ */
