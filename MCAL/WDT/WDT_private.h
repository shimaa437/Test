/*
 * WDT_private.h
 *
 *  Created on: Jul 28, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef WDT_WDT_PRIVATE_H_
#define WDT_WDT_PRIVATE_H_

#include "STD_TYPES.h"
#define  WDTCR_REG    *((volatile u8*)0x41)
#define WDE      3
#define WDP0     0
#define WDP1     1
#define WDP2     2

#endif /* WDT_WDT_PRIVATE_H_ */
