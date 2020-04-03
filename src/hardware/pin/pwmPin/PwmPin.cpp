/*
 * PWMPin.cpp
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#include <hardware/pin/pwmPin/PwmPin.h>

PwmPin::PwmPin(){}

PwmPin::PwmPin(uint8_t pinNumber, PwmPinType pwmPinType) {
	this->pinNumber = pinNumber;
	this->pwmPinType = pwmPinType;
}

void PwmPin::setValue(uint8_t duty){}

PwmPin::PwmPinType PwmPin::getPwmPinType(){
	return pwmPinType;
}
