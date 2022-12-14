/*
 * TIMER0_config.h
 *
 *  Created on: Jul 25, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef TIMER0_TIMER0_CONFIG_H_
#define TIMER0_TIMER0_CONFIG_H_
/*
 * CHOOSE TIMER MODE :  NORMAL_MODE , CTC_MODE
 */
#define TIMER0_MODE        CTC_MODE

/*
 * CHOOSE TIMER0_PRESCALER :  1024 , 256
 */
#define TIMER0_PRESCALER  1024

/*
 * CHOOSE F_OSC
 */
#define F_OSC   16

/*
 * CHOOSE TIMER0_PWM_MODE :  PHASE_COREECT , FAST_PWM
 */
#define TIMER0_PWM_MODE  PHASE_COREECT

/*
 * CHOOSE TIMER0_FAST_PWM_MODE :  NON_INVERTED, INVERTED
 */
#define TIMER0_FAST_PWM_MODE   NON_INVERTED



#endif /* TIMER0_TIMER0_CONFIG_H_ */
