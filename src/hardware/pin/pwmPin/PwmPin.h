/*
 * PWMPin.h
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#ifndef SRC_CORE_PIN_PWMPIN_H_
#define SRC_CORE_PIN_PWMPIN_H_

#include <hardware/pin/ArduinoPin.h>
#include "interfaces/PwmPinInterface.h"

class PwmPin : public ArduinoPin, public PwmPinInterface{
public:
	PwmPin();
	~PwmPin();
	PwmPin(uint8_t pinNumber, PwmPinType pwmPinType = EMBEDDED_PWM_PIN);
	void setValue(int rotationMode, uint8_t duty);
	PwmPinType getPwmPinType();
	uint8_t getPinNumber();

protected:
	PwmPinType pwmPinType;
};

#endif /* SRC_CORE_PIN_PWMPIN_H_ */
