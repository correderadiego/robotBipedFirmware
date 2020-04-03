/*
 * PWMPin.h
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#ifndef SRC_CORE_PIN_PWMPIN_H_
#define SRC_CORE_PIN_PWMPIN_H_

#include "hardware/pin/Pin.h"
#include "Servo.h"

class PwmPin : public Pin{
public:
	enum PwmPinType{
		EMBEDDED_PWM_PIN,
		PAC9685_PWM_PIN
	};
	PwmPin();
	PwmPin(uint8_t pinNumber, PwmPinType pwmPinType = EMBEDDED_PWM_PIN);
	void setValue(uint8_t duty);
	PwmPinType getPwmPinType();

protected:
	PwmPinType pwmPinType;
};

#endif /* SRC_CORE_PIN_PWMPIN_H_ */
