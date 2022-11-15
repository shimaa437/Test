/*
 * UART_config.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef UART_UART_CONFIG_H_
#define UART_UART_CONFIG_H_

/*
 *  UART_CHARACTER_SIZE : 5 , 6 , 7 , 8
 */
#define UART_CHARACTER_SIZE    8
/*
 *  UART_STOP_BITS : 1 , 2
 */
#define UART_STOP_BITS    1
/*
 *  UART_PARITY_MODE : ENABLE_PARITY_EVEN , ENABLE_PARITY_ODD , DIABLE_PARITY
 */
#define UART_PARITY_MODE   DIABLE_PARITY
/*
 *  choose F_OSC
 */
#define F_OSC    16
#endif /* UART_UART_CONFIG_H_ */
