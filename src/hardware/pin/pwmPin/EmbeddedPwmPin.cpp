/*
 * EmbeddedPwmPin.cpp
 *
 *  Created on: 2 abr. 2020
 *      Author: ziash
 */

#include <hardware/pin/pwmPin/EmbeddedPwmPin.h>

EmbeddedPwmPin::EmbeddedPwmPin(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
	servo->attach(pinNumber);
	this->pwmPinType = PwmPin::EMBEDDED_PWM_PIN;
}

void EmbeddedPwmPin::setValue(uint8_t duty){
	servo->write(duty);
}
