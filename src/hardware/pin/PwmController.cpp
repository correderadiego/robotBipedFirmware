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
	configurePWM();
}

PwmController* PwmController::getInstance(){
	if(PwmController::pwmController == NULL){
		pwmController = new PwmController();
	}
	return pwmController;
}

void PwmController::configurePWM(){
	this->pwmServoDriver.begin();
	this->pwmServoDriver.setPWMFreq(PWM_FREQUENCY);
	Serial.println("PwmController::configurePWM");
}

void PwmController::setPWM(uint8_t num, uint16_t duty){
	this->pwmServoDriver.setPWM(num, invertPWMLogic(obtainPWMValue(duty)), MAX_PWM_VALUE);
}

uint16_t PwmController::obtainPWMValue(uint16_t duty){
	if(duty > MAX_PWM_PERCENTAJE_VALUE || duty < MIN_PWM_PERCENTAJE_VALUE){
		return HALF_PWM_VALUE;
	}
	return ((MAX_PWM_VALUE*duty)/100);
}


uint16_t PwmController::invertPWMLogic(uint16_t value){
	return MAX_PWM_VALUE - value;
}
