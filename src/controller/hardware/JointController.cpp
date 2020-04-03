/*
 * JointController2.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include "JointController.h"

JointController::JointController(PCA9685PwmController* pca9685PwmController) {
	this->pca9685PwmController = pca9685PwmController;
}

void JointController::executeThreadTasks(Plen* plen){
	for (int i = 0; i < plen->getJointSize(); i++){
		moveJoint(plen->getJointVector()[i]);
	}
}

void JointController::moveJoint(Joint* joint){
	if(joint->getPwmPin()->getPwmPinType() == PwmPin::PAC9685_PWM_PIN){
		pca9685PwmController->setAngle(joint->getPwmPin()->getPinNumber(), joint->getAngle());
		return;
	}
	joint->getPwmPin()->setValue(joint->getAngle());
}
