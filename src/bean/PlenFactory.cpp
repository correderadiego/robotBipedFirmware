/*
 * PlenFactory.cpp
 *
 *  Created on: 16 mar. 2020
 *      Author: ziash
 */

#include "PlenFactory.h"

Plen* PlenFactory::getPlen() {

	/**
	 * Controllers
	 */
	JointController* jointController 	= new JointController();
	MotionController* motionController	= new MotionController(*jointController);
	Interpreter* interpreter 			= new Interpreter(*motionController);
	LedController* ledController		= new LedController();
	EyeController* eyeController		= new EyeController(ledController);
	/**
	 * Joint
	 */
	Joint* joint[] = {
						new Joint(-40), // [01] Left : Shoulder Pitch
						new Joint(245), // [02] Left : Thigh Yaw
						new Joint(470), // [03] Left : Shoulder Roll
						new Joint(-100),// [04] Left : Elbow Roll
						new Joint(-205),// [05] Left : Thigh Roll
						new Joint(50), 	// [06] Left : Thigh Pitch
						new Joint(445),	// [07] Left : Knee Pitch
						new Joint(245),	// [08] Left : Foot Pitch
						new Joint(-75), // [09] Left : Foot Roll
						new Joint(),
						new Joint(),
						new Joint(),
						new Joint(15), 	// [10] Right : Shoulder Pitch
						new Joint(-70),	// [11] Right : Thigh Yaw
						new Joint(-390),// [12] Right : Shoulder Roll
						new Joint(250),	// [13] Right : Elbow Roll
						new Joint(195),	// [14] Right : Thigh Roll
						new Joint(-105),// [15] Right : Thigh Pitch
						new Joint(-510),// [16] Right : Knee Pitch
						new Joint(-305),// [17] Right : Foot Pitch
						new Joint(60),	// [18] Right : Foot Roll
						new Joint(),
						new Joint(),
						new Joint(),
	};

	/**
	 * Eyes
	 */
	GPIOPin* gpioPinLed = new GPIOPin(PIN_LED, OUTPUT);
	Led* led 			= new Led(gpioPinLed);
	Eyes* eyes 			= new Eyes(led);

	//TODO review pointers
	File* fileMotion 		= new File();
	File* fileConfiguration = new File();
	this->openFiles(*fileMotion, *fileConfiguration);

	return new Plen(jointController, motionController, interpreter, eyeController, joint, NUMBER_OF_JOINTS, eyes);
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
