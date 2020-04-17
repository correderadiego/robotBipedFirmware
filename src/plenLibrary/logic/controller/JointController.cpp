/*
 * JointController2.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/JointController.h>

JointController::JointController(PCA9685PwmControllerInterface* pca9685PwmControllerInterface) {
	this->pca9685PwmControllerInterface = pca9685PwmControllerInterface;
}

void JointController::executeThreadTasks(Plen* plen){
	for (int i = 0; i < plen->getJointSize(); i++){
		moveJoint(plen->getJointVector()[i]);
	}
}

void JointController::moveJoint(Joint* joint){
	if(joint->getPwmPin()->getPwmPinType() == PwmPinInterface::PAC9685_PWM_PIN){
		pca9685PwmControllerInterface->setAngle(joint->getPwmPin()->getPinNumber(), joint->getAngle());
		return;
	}
	joint->getPwmPin()->setValue(joint->getAngle());
}
