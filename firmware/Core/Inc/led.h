/*
 * led.h
 *
 *  Created on: Feb 29, 2024
 *      Author: gabrteta22
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include <stdint.h>

void LedStart(void);

void LedSetValue(uint8_t value);

void LedPulse(void);

#endif /* INC_LED_H_ */
