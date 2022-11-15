/*
 * WDT_prog.c
 *
 *  Created on: Jul 28, 2022
 *      Author: Shimaa_Ismail
 */

#include "WDT_int.h"

void M_WDT_Void_Enable(void)
{
	/* to enable Watch dog timer  */
	SET_BIT(WDTCR_REG,WDE);
	/* TO SELECT 2.1 seconds as window time */
	SET_BIT(WDTCR_REG,WDP0);
	SET_BIT(WDTCR_REG,WDP1);
	SET_BIT(WDTCR_REG,WDP2);

}

void M_WDT_Void_Refresh(void)
{
	asm("WDR");
}
