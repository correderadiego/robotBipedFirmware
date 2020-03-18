/*
 * PWMPin.cpp
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#include "PWMPin.h"

PWMPin::PWMPin(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
}

void PWMPin::setValue(uint8_t duty){
	PwmController::getInstance()->setAngle(this->pinNumber, duty);
}
