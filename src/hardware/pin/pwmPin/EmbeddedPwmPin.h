/*
 * EmbeddedPwmPin.h
 *
 *  Created on: 2 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_HARDWARE_PIN_PWMPIN_EMBEDDEDPWMPIN_H_
#define SRC_HARDWARE_PIN_PWMPIN_EMBEDDEDPWMPIN_H_

#include <hardware/pin/pwmPin/PwmPin.h>
#include <logic/bean/hardware/Joint.h>
#include <Servo.h>

class EmbeddedPwmPin: public PwmPin{
public:
	EmbeddedPwmPin(uint8_t pinNumber);
	virtual ~EmbeddedPwmPin();
	void setValue(Joint::RotationMode rotationMode, uint8_t value);
private:
    Servo* servo = new Servo();
    int getEmbeddedPwmValue(Joint::RotationMode rotationMode, uint8_t value);
};

#endif /* SRC_HARDWARE_PIN_PWMPIN_EMBEDDEDPWMPIN_H_ */
