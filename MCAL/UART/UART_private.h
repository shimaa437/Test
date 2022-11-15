/*
 * UART_private.h
 *
 *  Created on: Jul 31, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef UART_UART_PRIVATE_H_
#define UART_UART_PRIVATE_H_

#define DIABLE_PARITY        0
#define ENABLE_PARITY_ODD    1
#define ENABLE_PARITY_EVEN   2



#define UCSRA_REG   *((volatile u8 *)0x2B)
#define TXC            6
#define RXC            7
#define UCSRB_REG   *((volatile u8 *)0x2A)
#define UCSZ2          2
#define TXEN           3
#define RXEN           4
#define UCSRC_REG   *((volatile u8 *)0x40)
#define UCSZ0          1
#define UCSZ1          2
#define USBS           3
#define UPM0           4
#define UPM1           5
#define UDR_REG     *((volatile u8 *)0x2C)
#define UBRRL_REG   *((volatile u8 *)0x29)

#endif /* UART_UART_PRIVATE_H_ */
