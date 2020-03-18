/*
 * PwmController.cpp
 *
 *  Created on: 23 ago. 2018
 *      Author: diego
 */

#include "PwmController.h"

PwmController* PwmController::pwmController = NULL;

PwmController::PwmController() {
	pwmServoDriver =  Adafruit_PWMServoDriver(PWM_CONTROLLER_ID);
	gpioPinEnable  = new GPIOPin(PIN_EXPANSOR_ENABLE, OUTPUT);
	configurePWM();
}

PwmController* PwmController::getInstance(){
	if(PwmController::pwmController == NULL){
		pwmController = new PwmController();
	}
	return pwmController;
}

void PwmController::resetPWMController(){
	gpioPinEnable->setPinValue(HIGH);
	delay(PWM_CONTROLLER_RESET_TIME);
	gpioPinEnable->setPinValue(LOW);
}

void PwmController::configurePWM(){
	resetPWMController();
	this->pwmServoDriver.begin();
	this->pwmServoDriver.setPWMFreq(PWM_FREQUENCY);
	Serial.println("PwmController::configurePWM");
}

void PwmController::setAngle(uint8_t num, uint16_t duty){
	this->pwmServoDriver.setPWM(num, invertPWMLogic(obtainPWMValue(duty)), MAX_PWM_VALUE);
}

uint16_t PwmController::obtainPWMValue(uint16_t angle){
	return 90 - angle / 10;;
}

uint16_t PwmController::invertPWMLogic(uint16_t value){
	return MAX_PWM_VALUE - value;
}
