/*
 * PWMPin.h
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#ifndef SRC_CORE_PIN_PWMPIN_H_
#define SRC_CORE_PIN_PWMPIN_H_

#include "Pin.h"
#include "PwmController.h"

#define PWM_HIGH 100
#define PWM_LOW 0

class PWMPin :public Pin{
public:
	PWMPin(uint8_t pinNumber);
	void setPinValue(uint8_t duty);
	void setValue(uint8_t duty);
};

#endif /* SRC_CORE_PIN_PWMPIN_H_ */
