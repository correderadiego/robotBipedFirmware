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
#include <PinDefinition.h>
#include "plenLibrary/interfaces/PCA9685PwmControllerInterface.h"

#define PWM_CONTROLLER_ID 0x44
#define MAX_PWM_VALUE	4095
#define PWM_FREQUENCY	60

#define PWM_CONTROLLER_RESET_TIME 200

class PCA9685PwmController: public PCA9685PwmControllerInterface{
public:
	PCA9685PwmController();
	void resetPWMController();
	void setAngle(uint8_t num, uint16_t duty);

private:
	GPIOPin* gpioPinEnable;
	Adafruit_PWMServoDriver pwmServoDriver;
	byte pwmAddress;
	void configurePWM();
};

#endif /* SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_ */
