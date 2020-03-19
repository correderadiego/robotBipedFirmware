/*
 * PlenControllerFactory.cpp
 *
 *  Created on: 19 mar. 2020
 *      Author: ziash
 */

#include <controller/PlenControllerFactory.h>

PlenController* PlenControllerFactory::getPlenController(){
	JointController* jointController 	= new JointController();
	MotionController* motionController	= new MotionController(*jointController);
	Interpreter* interpreter 			= new Interpreter(*motionController);
	LedController* ledController		= new LedController();
	EyeController* eyeController		= new EyeController(ledController);
	ExternalFileSystemController* externalFileSystemController = new ExternalFileSystemController();

	return new PlenController(
			jointController,
			motionController,
			interpreter,
			eyeController,
			externalFileSystemController);
}
