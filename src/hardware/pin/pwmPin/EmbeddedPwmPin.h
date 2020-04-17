/*
 * EmbeddedPwmPin.h
 *
 *  Created on: 2 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_HARDWARE_PIN_PWMPIN_EMBEDDEDPWMPIN_H_
#define SRC_HARDWARE_PIN_PWMPIN_EMBEDDEDPWMPIN_H_

#include <hardware/pin/pwmPin/PwmPin.h>
#include <Servo.h>

class EmbeddedPwmPin: public PwmPin{
public:
	EmbeddedPwmPin(uint8_t pinNumber);
	void setValue(uint8_t duty);
private:
    Servo* servo = new Servo();
};

#endif /* SRC_HARDWARE_PIN_PWMPIN_EMBEDDEDPWMPIN_H_ */
