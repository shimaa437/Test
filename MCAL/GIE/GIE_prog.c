/*
 * GIE_prog.c
 *
 *  Created on: Jul 19, 2022
 *      Author: zas
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_config.h"
#include "GIE_int.h"
#include "GIE_private.h"






void M_GIE_void_Enable (void)
{
	//set I bit//
	SET_BIT(GIE_SREG, I_bit);
	//using assembly//
	//asm ("SEI");
}
void M_GIE_void_Disable (void)
{
	//asm("CLI");
	CLR_BIT(GIE_SREG, I_bit);
}

