/*
 * PlenControllerFactory.cpp
 *
 *  Created on: 19 mar. 2020
 *      Author: ziash
 */

#include <PlenControllerFactory.h>

PlenController* PlenControllerFactory::getPlenController(
		ExternalFileSystemController* externalFileSystemController){

	MotionController* motionController;
	Interpreter* interpreter 									= new Interpreter();
	LedController* ledController								= new LedController();
	EyeController* eyeController								= new EyeController(ledController);
	ParserController* parserController 							= new ParserController();
	JointController* jointController 							= new JointController(new PCA9685PwmController(), externalFileSystemController);
	ProcessController* processController						= new ProcessController(jointController);

	return new PlenController(
			jointController,
			motionController,
			interpreter,
			eyeController,
			externalFileSystemController,
			parserController,
			processController);
}
