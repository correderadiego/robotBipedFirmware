/*
 * GPIOPin.cpp
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#include "GPIOPin.h"

GPIOPin::GPIOPin(uint8_t pinNumber, uint8_t mode) {
	this->pinNumber = pinNumber;
	pinMode(pinNumber, mode);
}

int GPIOPin::getPinValue(){
	return digitalRead(pinNumber);
}

void GPIOPin::setPinValue(uint8_t pinValue){
	digitalWrite(this->pinNumber, pinValue);
}

void GPIOPin::pullUpMode(){
	digitalWrite(this->pinNumber, HIGH);
}
