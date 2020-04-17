/*
 * PCA9685PwmPin.cpp
 *
 *  Created on: 2 abr. 2020
 *      Author: ziash
 */

#include <hardware/pin/pwmPin/PCA9685PwmPin.h>

PCA9685PwmPin::PCA9685PwmPin(uint8_t pinNumber) {
	this->pinNumber = pinNumber;
	this->pwmPinType = PwmPin::PAC9685_PWM_PIN;
}
