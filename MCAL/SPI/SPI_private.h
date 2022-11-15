/*
 * SPI_private.h
 *
 *  Created on: Aug 1, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef SPI_SPI_PRIVATE_H_
#define SPI_SPI_PRIVATE_H_

#define SPCR_REG        *((volatile u8*)0x2D)
#define SPR0             0
#define SPR1             1
#define MSTR             4
#define DORD             5
#define SPE              6

#define SPDR_REG        *((volatile u8*)0x2F)


#define SPSR_REG        *((volatile u8*)0x2E)
#define SPIF             7


#define SPI_MASTER_MODE    0
#define SPI_SLAVE_MODE     1
#endif /* SPI_SPI_PRIVATE_H_ */
