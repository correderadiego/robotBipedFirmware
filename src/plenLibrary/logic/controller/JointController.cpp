/*
 * JointController2.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: Diego
 */

#include <logic/controller/JointController.h>

JointController::JointController(
		PwmControllerInterface* pca9685PwmController,
		ExternalFileSystemController* externalFileSystemController) {
	this->pca9685PwmController 			= pca9685PwmController;
	this->externalFileSystemController  = externalFileSystemController;
}

void JointController::updateJointPosition(Joint** jointVector, int jointSize){
	for (int i = 0; i < jointSize - 1; i++){
		moveJoint(jointVector[i]);
	}
}

ExternalFileSystemController* JointController::getExternalFileSystemController(){
	return this->externalFileSystemController;
}

ExternalFileSystemController::FileSystemErrors JointController::storeJoint(Plen* plen, Joint* joint, int jointIndex){
	unsigned int sizeWrite = 0;
	unsigned char* filler  = reinterpret_cast<unsigned char*>(joint->getJointMemory());

	return  this->externalFileSystemController->write(
			SETTINGS_HEAD_ADDRESS + jointIndex*sizeof(*joint->getJointMemory()),
			sizeof(*joint->getJointMemory()),
			filler,
			&sizeWrite,
			plen->getFileConfiguration());
}

ExternalFileSystemController::FileSystemErrors JointController::loadJoint(Plen* plen, Joint* joint, int jointIndex){
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(joint->getJointMemory());

	return  this->externalFileSystemController->read(
			SETTINGS_HEAD_ADDRESS + jointIndex*sizeof(*joint->getJointMemory()),
			sizeof(*joint->getJointMemory()),
			filler,
			&sizeRead,
			plen->getFileConfiguration());
}

void JointController::moveJoint(Joint* joint){
	if(joint->getPwmPin() == NULL) {
		return;
	}

	if(!joint->isEnabled()){
		Logger::getInstance()->logln(Logger::DEBUG, S("Joint disabled"));
		return;
	}

	if(joint->getPwmPin()->getPwmPinType() == PwmPinInterface::PAC9685_PWM_PIN){
		this->pca9685PwmController->setValue(
				joint->getRotationMode(),
				joint->getPwmPin()->getPinNumber(),
				joint->getAngle()
				);
		return;
	}

	joint->getPwmPin()->setValue(joint->getRotationMode(), joint->getAngle());
}

void JointController::resetJoint(Joint* joint){
	joint->setAngleHome(joint->getDefaultAngleHome());
	joint->setAngleMax(ANGLE_MAX);
	joint->setAngleMin(ANGLE_MIN);
}

void JointController::dump(Joint* joint){
	Logger::getInstance()->log(Logger::INFO, S("\t{"));

	Logger::getInstance()->log(Logger::INFO, S("\t\t\"max\": "));
	Logger::getInstance()->log(Logger::INFO, joint->getAngleMax());
	Logger::getInstance()->log(Logger::INFO, S(","));

	Logger::getInstance()->log(Logger::INFO, S("\t\t\"min\": "));
	Logger::getInstance()->log(Logger::INFO, joint->getAngleMin());
	Logger::getInstance()->log(Logger::INFO, S(","));

	Logger::getInstance()->log(Logger::INFO, S("\t\t\"home\": "));
	Logger::getInstance()->log(Logger::INFO, joint->getAngleHome());
	Logger::getInstance()->log(Logger::INFO, S("\t}"));
}
