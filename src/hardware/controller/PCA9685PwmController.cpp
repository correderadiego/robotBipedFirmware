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
	delay(PWM_CONTROLLER_CONFIGURE_TIME);
}

void PCA9685PwmController::setValue(Joint::RotationMode rotationMode, uint8_t servoNumber, uint16_t duty){
	this->pwmServoDriver.setPWM(servoNumber, 0, getPwmValue(rotationMode, duty));
}

void PCA9685PwmController::disableServo(uint8_t num){
	this->pwmServoDriver.setPWM(num, 4096, 0);
}

int PCA9685PwmController::getPwmValue(Joint::RotationMode rotationMode, uint16_t duty){
	if(rotationMode == Joint::RotationMode::clockWise){
		return map(
					duty,
					ANGLE_MIN, ANGLE_MAX,
					PWM_MIN, PWM_MAX
				);
	}
	return map(
				duty,
				ANGLE_MIN, ANGLE_MAX,
				PWM_MAX, PWM_MIN
			);
}
