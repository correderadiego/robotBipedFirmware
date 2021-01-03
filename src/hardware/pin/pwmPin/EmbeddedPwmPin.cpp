/*
 * EmbeddedPwmPin.cpp
 *
 *  Created on: 2 abr. 2020
 *      Author: Diego
 */

#include <hardware/pin/pwmPin/EmbeddedPwmPin.h>

EmbeddedPwmPin::EmbeddedPwmPin(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
	servo->attach(pinNumber);
	this->pwmPinType = PwmPin::EMBEDDED_PWM_PIN;
}

EmbeddedPwmPin::~EmbeddedPwmPin() {}

void EmbeddedPwmPin::setValue(Joint::RotationMode rotationMode, uint8_t value){
	servo->write(getEmbeddedPwmValue(rotationMode, value));
}

int EmbeddedPwmPin::getEmbeddedPwmValue(Joint::RotationMode rotationMode, uint8_t value){
	if(rotationMode == Joint::RotationMode::clockWise){
		return 90 + value / 10;
	}
	return 90 - value / 10;
}
