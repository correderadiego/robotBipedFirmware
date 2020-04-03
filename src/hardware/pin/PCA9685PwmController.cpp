/*
 * PwmController.cpp
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#include <hardware/pin/PCA9685PwmController.h>

PCA9685PwmController* PCA9685PwmController::pwmController = NULL;

PCA9685PwmController::PCA9685PwmController() {
	pwmServoDriver =  Adafruit_PWMServoDriver(PWM_CONTROLLER_ID);
	gpioPinEnable  = new GPIOPin(PIN_EXPANSOR_ENABLE, OUTPUT);
	configurePWM();
}

PCA9685PwmController* PCA9685PwmController::getInstance(){
	if(PCA9685PwmController::pwmController == NULL){
		pwmController = new PCA9685PwmController();
	}
	return pwmController;
}

void PCA9685PwmController::resetPWMController(){
	gpioPinEnable->setPinValue(HIGH);
	delay(PWM_CONTROLLER_RESET_TIME);
	gpioPinEnable->setPinValue(LOW);
}

void PCA9685PwmController::configurePWM(){
	resetPWMController();
	this->pwmServoDriver.begin();
	this->pwmServoDriver.setPWMFreq(PWM_FREQUENCY);
}

void PCA9685PwmController::setAngle(uint8_t num, uint16_t duty){
	this->pwmServoDriver.setPWM(num, duty, MAX_PWM_VALUE);
}

