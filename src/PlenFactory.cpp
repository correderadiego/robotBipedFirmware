/*
 * PlenFactory.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include <PlenFactory.h>

Plen* PlenFactory::getPlen() {
	joint[0] =	new Joint(new PCA9685PwmPin(PIN_LEFT_SHOULDER_PITCH),	HOME_POSITION_LEFT_SHOULDER_PITCH, Joint::counterClockWise);
	joint[1] =	new Joint(new PCA9685PwmPin(PIN_LEFT_THIGH_YAW),		HOME_POSITION_LEFT_THIGH_YAW);
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
	this->openFiles(*fileMotion, *fileConfiguration);

	return new Plen(joint, NUMBER_OF_JOINTS, eyes, serialBuffer, socketBuffer, fileMotion, fileConfiguration);
}

void PlenFactory::openFiles(File fileMotion, File fileConfiguration){
	File file;
	unsigned char buf[BUF_SIZE] = {1};
	ExternalFileSystemController* externalFsController = new ExternalFileSystemController();
    if (!SPIFFS.exists(MOTION_FILE) || !SPIFFS.exists(CONFIG_FILE)){
    	externalFsController->createFile(
    			file, MOTION_FILE, MOTION_FILE_SIZE, buf, BUF_SIZE);
    	externalFsController->createFile(
    			file, CONFIG_FILE, CONFIG_FILE_SIZE, buf, BUF_SIZE );
    }
    fileMotion = SPIFFS.open(MOTION_FILE, FILE_MODE_READ);
    fileConfiguration = SPIFFS.open(CONFIG_FILE, FILE_MODE_READ);
}


