/*
 * PwmController.h
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#ifndef SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_
#define SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_

#include <Adafruit_PWMServoDriver.h>
#include "hardware/pin/PinDefinition.h"
#include "hardware/pin/GPIOPin.h"


#define PWM_CONTROLLER_ID 0x44
#define MAX_PWM_VALUE	4095
#define PWM_FREQUENCY	60

#define PWM_CONTROLLER_RESET_TIME 200

class PCA9685PwmController {
public:
	PCA9685PwmController();
	static PCA9685PwmController* getInstance();
	void resetPWMController();
	void setAngle(uint8_t num, uint16_t duty);

private:
	static PCA9685PwmController* pwmController;
	GPIOPin* gpioPinEnable;
	Adafruit_PWMServoDriver pwmServoDriver;
	byte pwmAddress;
	void configurePWM();
};

#endif /* SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_ */
