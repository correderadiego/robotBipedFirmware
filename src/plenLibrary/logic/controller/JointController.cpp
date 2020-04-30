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

ExternalFileSystemController::FileSystemErrors JointController::storeJoint(Plen* plen, Joint* joint, unsigned int startAddress){
	unsigned int sizeWrite = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(joint);

	return (new ExternalFileSystemController())->write(
			startAddress, sizeof(*joint), filler, &sizeWrite, plen->getFileSystem());
}

ExternalFileSystemController::FileSystemErrors JointController::loadJoint(Plen* plen, Joint* joint, unsigned int startAddress){
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(joint);

	return  (new ExternalFileSystemController())->read(
			startAddress, sizeof(*joint), filler, &sizeRead, plen->getFileSystem());
}

void JointController::moveJoint(Joint* joint){
	if(joint->getPwmPin()->getPwmPinType() == PwmPinInterface::PAC9685_PWM_PIN){
		pca9685PwmControllerInterface->setAngle(joint->getPwmPin()->getPinNumber(), joint->getAngle());
		return;
	}
	joint->getPwmPin()->setValue(joint->getAngle());
}
