/*
 * JointController2.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/JointController.h>

JointController::JointController(PCA9685PwmControllerInterface* pca9685PwmControllerInterface,
		ExternalFileSystemController* externalFileSystemControler) {
	this->pca9685PwmControllerInterface = pca9685PwmControllerInterface;
	this->externalFileSystemController  = externalFileSystemController;
}

void JointController::executeThreadTasks(Plen* plen){
	for (int i = 0; i < plen->getJointSize(); i++){
		moveJoint(plen->getJointVector()[i]);
	}
}

ExternalFileSystemController* JointController::getExternalFileSystemController(){
	return this->externalFileSystemController;
}

ExternalFileSystemController::FileSystemErrors JointController::storeJoint(Plen* plen, Joint* joint, int jointIndex){
	unsigned int sizeWrite = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(joint->getJointMemory());

	return (new ExternalFileSystemController)->write(
			SETTINGS_HEAD_ADDRESS + jointIndex*sizeof(*joint->getJointMemory()),
			sizeof(*joint->getJointMemory()),
			filler,
			&sizeWrite,
			plen->getFileConfiguration());
}

ExternalFileSystemController::FileSystemErrors JointController::loadJoint(Plen* plen, Joint* joint, int jointIndex){
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(joint->getJointMemory());

	return  (new ExternalFileSystemController())->read(
			SETTINGS_HEAD_ADDRESS + jointIndex*sizeof(*joint->getJointMemory()),
			sizeof(*joint->getJointMemory()),
			filler, &sizeRead, plen->getFileConfiguration());
}

void JointController::moveJoint(Joint* joint){
	if(joint->getPwmPin()->getPwmPinType() == PwmPinInterface::PAC9685_PWM_PIN){
		pca9685PwmControllerInterface->setAngle(joint->getPwmPin()->getPinNumber(), joint->getAngle());
		return;
	}
	joint->getPwmPin()->setValue(joint->getAngle());
}
