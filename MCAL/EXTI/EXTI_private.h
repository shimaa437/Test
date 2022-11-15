/*
 * EXTI_private.h
 *
 *  Created on: Jul 19, 2022
 *      Author: zas
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

#define EXTI_MCUCR  *((volatile u8*)0X55)          // TRIGGER REGISTER FOR FIRST TO BITS OF IT FOR INT0 SECOND TWO BITS FOR INT1//
#define ISC00   0                                // Interrupt sense control 0 Bit 0
#define ISC01   1                               // Interrupt sense control 1 Bit 1
#define ISC10   2                               // Interrupt sense control 2 Bit 2
#define ISC11   3                             // Interrupt sense control 2 Bit 3

#define EXTI_MCUCSR *((volatile u8*)0X54)     // TRIGGER REGISTER FOR INT2//
#define ISC2    6                           //Interrupt Sense Control 2//

#define EXTI_GICR  *((volatile u8*)0X58)   //PIE REGISTER(Special Key)//
#define INT2   5
#define INT0   6
#define INT1   7

#define EXTI_GIFR  *((volatile u8*)0X5A)  //FLAGS REGISTER//
#define INTF2   5
#define INTF1   7
#define INTF0   6

#define EXTI_INT0_TRIGGER_MASK  0b11111100
#define EXTI_INT1_TRIGGER_MASK  0b11110011

#endif /* EXTI_EXTI_PRIVATE_H_ */
