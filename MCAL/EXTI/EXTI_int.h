/*
 * EXTI_int.h
 *
 *  Created on: Jul 19, 2022
 *      Author: zas
 */

#ifndef EXTI_EXTI_INT_H_
#define EXTI_EXTI_INT_H_


#define EXTI_LOW_LEVEL    0     //00
#define EXTI_ANY_CHANGE   1    //01
#define EXTI_RISE_EDGE    2   //10
#define EXTI_FALL_EDGE    3  //11

/*External interrupt IDS
 *
 */

#define INT0_ID     6
#define INT1_ID     7
#define INT2_ID     5

void M_EXTI_void_Enable(u8 copy_u8IntID,u8 copy_u8IntTrig);
void M_EXTI_void_DIable(u8 copy_u8IntID);
void M_EXTI_void_setCallBackfn(void (*copy_ptrfn)(void),u8 copy_u8IntID);

#endif /* EXTI_EXTI_INT_H_ */
