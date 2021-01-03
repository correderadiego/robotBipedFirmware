/*
 * PWMPin.cpp
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#include <hardware/pin/pwmPin/PwmPin.h>

PwmPin::PwmPin(){
	this->pinNumber = pinNumber;
	this->pwmPinType = pwmPinType;
}

PwmPin::PwmPin(uint8_t pinNumber, PwmPinType pwmPinType) {
	this->pinNumber = pinNumber;
	this->pwmPinType = pwmPinType;
}

PwmPin::~PwmPin() {}

void PwmPin::setValue(int rotationMode, uint8_t duty){}

PwmPin::PwmPinType PwmPin::getPwmPinType(){
	return pwmPinType;
}

uint8_t PwmPin::getPinNumber(){
	return this->pinNumber;
}
