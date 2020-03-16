/*
 * GPIOPin.h
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#ifndef SRC_CORE_PIN_GPIOPIN_H_
#define SRC_CORE_PIN_GPIOPIN_H_

#include <Arduino.h>
#include "Pin.h"

class GPIOPin : public Pin {
public:
	GPIOPin(uint8_t pinNumber, uint8_t mode);
	int getPinValue ();
	void setPinValue(uint8_t value);
	void pullUpMode ();
};

#endif /* SRC_CORE_PIN_GPIOPIN_H_ */
