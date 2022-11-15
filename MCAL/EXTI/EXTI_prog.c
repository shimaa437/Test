/*
 * EXTI_prog.c
 *
 *  Created on: Jul 19, 2022
 *      Author: zas
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_int.h"
#include <avr/interrupt.h>

static void (*ptr_ArrCallBack[])(void) = {NULL,NULL,NULL};

/*
 * THIS FUNCTION ENABLES SPECIAL KEYES &CONFIGURE TRIGGER ONLY
 */
void M_EXTI_void_Enable(u8 copy_u8IntID,u8 copy_u8IntTrig)
{
	//step 1: Enable (special Key)
	SET_BIT(EXTI_GICR, copy_u8IntID);

	//Step 2: Config trigger
	switch (copy_u8IntID)
	{
	case INT0_ID :
		/*
		 * eaiser but longer way
		switch (copy_u8IntTrig)
		{
		case EXTI_LOW_LEVEL :
			CLR_BIT(EXTI_MCUCR,ISC00);
			CLR_BIT(EXTI_MCUCR,ISC01);
			break;
		case EXTI_ANY_CHANGE :
			SET_BIT(EXTI_MCUCR,ISC00);
			CLR_BIT(EXTI_MCUCR,ISC01);
			break;
		case EXTI_RISE_EDGE :
			CLR_BIT(EXTI_MCUCR,ISC00);
			SET_BIT(EXTI_MCUCR,ISC00);
			break;
		case EXTI_FALL_EDGE :
			CLR_BIT(EXTI_MCUCR,ISC00);
			SET_BIT(EXTI_MCUCR,ISC00);
			break;
		}*/
		EXTI_MCUCR  &= EXTI_INT0_TRIGGER_MASK ;
		EXTI_MCUCR |= copy_u8IntTrig;
		break;
	case INT1_ID :
		EXTI_MCUCR &= EXTI_INT1_TRIGGER_MASK ;
		EXTI_MCUCR |= copy_u8IntTrig << 2;
		break;

	case INT2_ID :
		/*switch (copy_u8IntTrig )
		{
		case EXTI_FALL_EDGE :
			CLR_BIT(EXTI_MCUCSR,ISC2);
			break;

		case EXTI_RISE_EDGE :
			SET_BIT(EXTI_MCUCSR,ISC2);
		} */
		CLR_BIT(EXTI_MCUCSR, ISC2);
		EXTI_MCUCSR |= ((copy_u8IntTrig &1) << ISC2);
	    break;
	}

}
void M_EXTI_void_DIable(u8 copy_u8IntID)
{
	CLR_BIT(EXTI_GICR, copy_u8IntID);
}

void M_EXTI_void_setCallBackfn(void (*copy_ptrfn)(void),u8 copy_u8IntID)
{
	switch (copy_u8IntID)
	{
	 case INT0_ID :
		 ptr_ArrCallBack[0] = 	copy_ptrfn ;
		 break;
	 case INT1_ID :
		 ptr_ArrCallBack[1] = 	copy_ptrfn ;
	 	 break;
	 case INT2_ID :
		 ptr_ArrCallBack[2] = 	copy_ptrfn ;
	 	 break;
	 default:
		 break;

	}
}

ISR(INT0_vect)
{
	ptr_ArrCallBack[0] ();
}

ISR(INT1_vect)
{
	ptr_ArrCallBack[1] ();
}

ISR(INT2_vect)
{
	ptr_ArrCallBack[2] ();
}


