/*
 * TIMER0_prog.c
 *
 *  Created on: Jul 25, 2022
 *      Author: Shimaa_Ismail
 *
 */

#include "TIMER0_int.h"
#include "LED_int.h"

u32 Timer0_u32NUMOfOv = 0;
u8  Timer0_u8RemTicks = 0;
u32 Timer0_u32NumOfCM = 0;
void (*CallBack) (void);       // pointer to function//

void M_TIMER0_Void_Init(void)
{
#if TIMER0_MODE == NORMAL_MODE
	CLR_BIT (TCCR0_REG,WGM00);
	CLR_BIT (TCCR0_REG,WGM01);
	/*ENABLE TIMER0 OVERFLOW INTERRUPT */
	SET_BIT(TIMSK_REG,TOIE0);
#elif TIMER0_MODE == CTC_MODE
	  CLR_BIT (TCCR0_REG,WGM00);
	  SET_BIT (TCCR0_REG,WGM01);
	  /*ENABLE TIMER0 COMPARE MATCH INTERRUPT
	   * */
	  SET_BIT(TIMSK_REG,OCIE0);
#endif

}
void M_TIMER0_Void_SetTime(u32 copy_u32DesiredTime)
{
	u32 Local_u32TickTime   = TIMER0_PRESCALER / F_OSC;   /*Result will be in microsecond*/
	u32 Local_u32TotalTicks = (copy_u32DesiredTime * 1000) / Local_u32TickTime; /*desiredtime im ms multiply it by 1000 to be in micro,ticktime in microsecond*/
#if TIMER0_MODE == NORMAL_MODE
	Timer0_u32NUMOfOv       = Local_u32TotalTicks / 256;
	Timer0_u8RemTicks       = Local_u32TotalTicks % 256;
	if (Timer0_u8RemTicks != 0)        // if there is a reminder ticks//
	{
	 TCNT0_REG            = 256 - Timer0_u8RemTicks;
	 Timer0_u32NUMOfOv++;   /*as number of overflow is increased due to the reminder ticks*/
	}
#elif TIMER0_MODE == CTC_MODE
	 u8 Local_u8Counter =255;
	 while (Local_u32TotalTicks % Local_u8Counter)
	 {
		 Local_u8Counter--;
	 }
	 Timer0_u32NumOfCM = Local_u32TotalTicks / Local_u8Counter;
	 OCR0_REG          = Local_u8Counter - 1;   // as comparator need extra tick to interrupt the cpu so to be accurate write on the register counter -1*/
#endif
}
void M_TIMER0_Void_Start(void)
{
#if TIMER0_PRESCALER == 1024
	SET_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
#elif TIMER0_PRESCALER == 256

	CLR_BIT(TCCR0_REG,CS00);
    CLR_BIT(TCCR0_REG,CS01);
	SET_BIT(TCCR0_REG,CS02);
#endif
}
void M_TIMER0_Void_Stop(void)
{
	CLR_BIT(TCCR0_REG,CS00);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS02);

}
void M_TIMER0_VoidSetCallBack(void(*Copyptr)(void))
{
	CallBack = Copyptr;
}

void M_TIMER0_Void_Pwm0Init(void)
{
	/* Enable output circut for PB3 (set pin OC0 as output to get out pwm) */
	M_DIO_void_setpinDirection(PORTB_ID,DIO_PIN3,PIN_DIRECTION_OUTPUT);

#if TIMER0_PWM_MODE == FAST_PWM
	/* To Select Fast PWM Mode */
	SET_BIT (TCCR0_REG,WGM00);
	SET_BIT (TCCR0_REG,WGM01);

#if TIMER0_FAST_PWM_MODE == NON_INVERTED
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);

#elif TIMER0_FAST_PWM_MODE == INVERTED
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#endif
#endif
#if TIMER0_PWM_MODE == PHASE_COREECT
	/* To Select Phase correct PWM Mode */
		SET_BIT (TCCR0_REG,WGM00);
		CLR_BIT (TCCR0_REG,WGM01);

    #if TIMER0_FAST_PWM_MODE == NON_INVERTED
		CLR_BIT(TCCR0_REG,COM00);
		SET_BIT(TCCR0_REG,COM01);

	#elif TIMER0_FAST_PWM_MODE == INVERTED
		SET_BIT(TCCR0_REG,COM00);
		SET_BIT(TCCR0_REG,COM01);
#endif
#endif
}
void M_TIMER0_Void_Pwm0SetDutyCycle(u8 Copy_u8DutyCycle)
{
#if TIMER0_PWM_MODE == TIMER0_FAST_PWM_MODE
   #if TIMER0_FAST_PWM_MODE == NON_INVERTED
    OCR0_REG = ((Copy_u8DutyCycle * 256) / 100) - 1 ;
   #elif TIMER0_FAST_PWM_MODE == INVERTED
   #endif
   #elif TIMER0_PWM_MODE == PHASE_COREECT
      #if TIMER0_FAST_PWM_MODE == NON_INVERTED
      OCR0_REG = ((Copy_u8DutyCycle * 255) / 100) ;
      #elif TIMER0_FAST_PWM_MODE ==  INVERTED
      #endif
#endif
}
void M_TIMER0_Void_Pwm0Start(void)
{
	M_TIMER0_Void_Start();
}
void M_TIMER0_Void_Pwm0Stop(void)
{
	M_TIMER0_Void_Stop();
}








#if TIMER0_MODE == NORMAL_MODE
ISR(TIMER0_OVF_vect)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter++;   // to arrive to overflow//
	if (Local_u32Counter == Timer0_u32NUMOfOv)
	{
		CallBack();
		Local_u32Counter = 0;
		TCNT0_REG   = 256 - Timer0_u8RemTicks;
	}
}
#elif TIMER0_MODE == CTC_MODE
ISR(TIMER0_COMP_vect)
{
	static u32 Local_u32Counter = 0;
	Local_u32Counter++;   // to arrive to overflow//
	if (Local_u32Counter == Timer0_u32NumOfCM)
	{
		CallBack();
		Local_u32Counter = 0;

	}
}
#endif
