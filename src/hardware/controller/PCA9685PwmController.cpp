/*
 * PwmController.cpp
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#include <hardware/controller/PCA9685PwmController.h>

PCA9685PwmController::PCA9685PwmController() {
	pwmServoDriver =  Adafruit_PWMServoDriver(PWM_CONTROLLER_ID);
	gpioPinEnable  = new GPIOPin(PIN_EXPANSOR_ENABLE, OUTPUT);
	configurePWM();
}

void PCA9685PwmController::resetPWMController(){
	gpioPinEnable->setPinValue(HIGH);
	delay(PWM_CONTROLLER_RESET_TIME);
	gpioPinEnable->setPinValue(LOW);
	delay(PWM_CONTROLLER_RESET_TIME);
}

void PCA9685PwmController::configurePWM(){
	resetPWMController();
	this->pwmServoDriver.begin();
	this->pwmServoDriver.setPWMFreq(PWM_FREQUENCY);
}

void PCA9685PwmController::setAngle(uint8_t num, uint16_t duty){
	this->pwmServoDriver.setPWM(num, 0, duty);
}

void PCA9685PwmController::disableServo(uint8_t num){
	this->pwmServoDriver.setPWM(num, 4096, 0);
}

