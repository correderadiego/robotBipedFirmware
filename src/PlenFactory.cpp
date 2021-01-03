/*
 * PlenFactory.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: Diego
 */

#include <PlenFactory.h>

Plen* PlenFactory::getPlen(ExternalFileSystemController* externalFsController) {
	joint[0] =	new Joint(new PCA9685PwmPin(PIN_LEFT_SHOULDER_PITCH),	HOME_POSITION_LEFT_SHOULDER_PITCH, Joint::counterClockWise);
	joint[1] =	new Joint(new PCA9685PwmPin(PIN_LEFT_THIGH_YAW),		HOME_POSITION_LEFT_THIGH_YAW, Joint::clockWise);
	joint[2] =  new Joint(new PCA9685PwmPin(PIN_LEFT_SHOULDER_ROLL),	HOME_POSITION_LEFT_SHOULDER_ROLL);
	joint[3] =	new Joint(new PCA9685PwmPin(PIN_LEFT_ELBOW_ROLL),		HOME_POSITION_LEFT_ELBOW_ROLL);
	joint[4] =	new Joint(new PCA9685PwmPin(PIN_LEFT_THIGH_ROLL),		HOME_POSITION_LEFT_THIGH_ROLL);
	joint[5] =	new Joint(new PCA9685PwmPin(PIN_LEFT_THIGH_PITCH),		HOME_POSITION_LEFT_THIGH_PITCH);
	joint[6] =	new Joint(new PCA9685PwmPin(PIN_LEFT_KNEE_PITCH),		HOME_POSITION_LEFT_KNEE_PITCH);
	joint[7] =	new Joint(new PCA9685PwmPin(PIN_LEFT_FOOT_PITCH),		HOME_POSITION_LEFT_FOOT_PITCH);
	joint[8] =	new Joint(new PCA9685PwmPin(PIN_LEFT_FOOT_ROLL),		HOME_POSITION_LEFT_FOOT_ROLL);
	joint[9] =	new Joint();
	joint[10] =	new Joint();
	joint[11] =	new Joint();
	joint[12] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_SHOULDER_PITCH),  HOME_POSITION_RIGHT_SHOULDER_PITCH, Joint::counterClockWise);
	joint[13] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_THIGH_YAW), 		HOME_POSITION_RIGHT_THIGH_YAW);
	joint[14] =	new Joint(new EmbeddedPwmPin(PIN_RIGHT_SHOULDER_ROLL),  HOME_POSITION_RIGHT_SHOULDER_ROLL);
	joint[15] =	new Joint(new EmbeddedPwmPin(PIN_RIGHT_ELBOW_ROLL), 	HOME_POSITION_RIGHT_ELBOW_ROLL);
	joint[16] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_THIGH_ROLL),  	HOME_POSITION_RIGHT_THIGH_ROLL);
	joint[17] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_THIGH_PITCH), 	HOME_POSITION_RIGHT_THIGH_PITCH);
	joint[18] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_KNEE_PITCH), 		HOME_POSITION_RIGHT_KNEE_PITCH);
	joint[19] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_FOOT_PITCH), 		HOME_POSITION_RIGHT_FOOT_PITCH);
	joint[20] =	new Joint(new PCA9685PwmPin(PIN_RIGHT_FOOT_ROLL),   	HOME_POSITION_RIGHT_FOOT_ROLL);
	joint[21] =	new Joint();
	joint[22] =	new Joint();
	joint[23] =	new Joint();

	GPIOPin* gpioPinLed = new GPIOPin(PIN_LED, OUTPUT);
	Led* led 			= new Led(gpioPinLed);
	Eyes* eyes 			= new Eyes(led);

	Buffer* serialBuffer = new Buffer();
	Buffer* socketBuffer = new Buffer();

	File* fileMotion 		= new File();
	File* fileConfiguration = new File();
	File* fileSystem		= new File();

	this->openFiles(externalFsController, fileMotion, fileConfiguration, fileSystem);
	return new Plen(joint, NUMBER_OF_JOINTS, eyes, serialBuffer, socketBuffer, fileMotion, fileConfiguration, fileSystem);
}

void PlenFactory::openFiles(ExternalFileSystemController* externalFsController, File* fileMotion, File* fileConfiguration, File* fileSystem){
    createFilesIfDontExist(externalFsController);
    *fileMotion 		= SPIFFS.open(MOTION_FILE, 		 FILE_MODE_READ_WRITE);
    *fileConfiguration 	= SPIFFS.open(JOINT_CONFIG_FILE, FILE_MODE_READ_WRITE);
    *fileSystem		 	= SPIFFS.open(SYS_FILE,    		 FILE_MODE_READ_WRITE);
}

void PlenFactory::createFilesIfDontExist(ExternalFileSystemController* externalFsController){
	unsigned char buf[BUF_SIZE] = {1};
	File* file = new File();

	if (!SPIFFS.exists(JOINT_CONFIG_FILE)){
			externalFsController->createAndResetFile(
							file, JOINT_CONFIG_FILE, CONFIG_FILE_SIZE, buf, BUF_SIZE);
	}

	if (!SPIFFS.exists(SYS_FILE)){
				externalFsController->createAndResetFile(
								file, SYS_FILE, SYS_FILE_SIZE, buf, BUF_SIZE);
	}

	if (!SPIFFS.exists(MOTION_FILE)){
		externalFsController->createAndResetFile(
						file, MOTION_FILE, MOTION_FILE_SIZE, buf, BUF_SIZE);
	}
}
