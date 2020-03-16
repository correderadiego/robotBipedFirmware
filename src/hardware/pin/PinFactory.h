/*
 * PinFactory.h
 *
 *  Created on: 11 sept. 2017
 *      Author: root
 */

#ifndef SRC_PIN_PINFACTORY_H_
#define SRC_PIN_PINFACTORY_H_

#include "Pin.h"

class PinFactory {
public:
	static Pin* getPin(uint8_t pin, uint8_t mode);
	static Pin* getPin(uint8_t pin);
	static void pullUpMode(uint8_t pin);
private:
	static void init(uint8_t pin, uint8_t mode);
};

#endif /* SRC_PIN_PINFACTORY_H_ */
