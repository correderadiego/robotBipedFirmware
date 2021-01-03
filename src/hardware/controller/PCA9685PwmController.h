/*
 * PwmController.h
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#ifndef SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_
#define SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_

#include <Adafruit_PWMServoDriver.h>
#include <hardware/pin/gpioPin/GPIOPin.h>
#include <interfaces/PwmControllerInterface.h>
#include <PinDefinition.h>
#include "plenLibrary/Configuration.h"
#include "logic/bean/hardware/Joint.h"

#define PWM_CONTROLLER_RESET_TIME 			1000
#define PWM_CONTROLLER_CONFIGURE_TIME	  	1000

class PCA9685PwmController: public PwmControllerInterface{
public:
	PCA9685PwmController();
	void resetPWMController();
	void setValue(Joint::RotationMode rotationMode, uint8_t num, uint16_t duty);
	void disableServo(uint8_t num);

private:
	GPIOPin* gpioPinEnable;
	Adafruit_PWMServoDriver pwmServoDriver;
	byte pwmAddress;
	void configurePWM();
	int getPwmValue(Joint::RotationMode rotationMode, uint16_t duty);
};

#endif /* SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_ */
