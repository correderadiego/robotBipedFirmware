/*
 * PwmController.h
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#ifndef SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_
#define SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_

#define PWM_CONTROLLER_ID 0x44

#define MAX_PWM_VALUE	4095
#define HALF_PWM_VALUE	2047
#define MIN_PWM_VALUE	0

#define PWM_FREQUENCY	1000
#define CLOCK_FREQUENCY	400000

#define MAX_PWM_PERCENTAJE_VALUE		100
#define MIN_PWM_PERCENTAJE_VALUE		0


#include <Adafruit_PWMServoDriver.h>

class PwmController {
public:
	PwmController();
	static PwmController* getInstance();
	void setPWM(uint8_t num, uint16_t duty);
	void setPWMColor(uint8_t num, uint16_t duty);

private:
	static PwmController* pwmController;
	Adafruit_PWMServoDriver pwmServoDriver;
	byte pwmAddress;
	uint16_t obtainPWMValue(uint16_t duty);
	uint16_t obtainPWMColor(uint16_t duty);
	uint16_t invertPWMLogic(uint16_t value);
	void configurePWM();
};

#endif /* SRC_CORE_PWMCONTROLLER_PWMCONTROLLER_H_ */
