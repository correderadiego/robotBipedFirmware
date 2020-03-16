/*
 * PinFactory.cpp
 *
 *  Created on: 11 sept. 2017
 *      Author: root
 */

#include "PinFactory.h"

Pin* PinFactory::getPin(uint8_t pin, uint8_t mode){
	return new Pin(pin);
}

Pin* PinFactory::getPin(uint8_t pin){
	return new Pin(pin);
}

void PinFactory::pullUpMode(uint8_t pin){
	digitalWrite(pin, HIGH);
}
