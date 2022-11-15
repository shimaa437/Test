/*
 * TWI_config.h
 *
 *  Created on: Aug 2, 2022
 *      Author: Shimaa_Ismail
 */

#ifndef I2C_TWI_CONFIG_H_
#define I2C_TWI_CONFIG_H_
/*
 * SELECT TWI_MODE : TWI_MASTER_MODE, TWI_SLAVE_MODE
 */
#define TWI_MODE  TWI_MASTER_MODE

/*
 * SELECT F_OSC
 */
#define F_OSC  16
/*
 * SELECT F_SCL
 */
#define F_SCL   400000

/*
 * SELECT SLAVE_ADDRESS :
 */
#define SLAVE_ADDRESS     1
#define GENERAL_CALL      1

#endif /* I2C_TWI_CONFIG_H_ */
