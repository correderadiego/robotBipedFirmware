/*
 * PlenControllerFactory.cpp
 *
 *  Created on: 19 mar. 2020
 *      Author: Diego
 */

#include <PlenControllerFactory.h>

PlenController* PlenControllerFactory::getPlenController(
		ExternalFileSystemController* externalFileSystemController){
	FrameController* frameController		= new FrameController(externalFileSystemController);
	HeaderController* headerController		= new HeaderController(externalFileSystemController);
	Interpreter* interpreter 				= new Interpreter();
	LedController* ledController			= new LedController();
	EyeController* eyeController			= new EyeController(ledController);
	ParserController* parserController 		= new ParserController();
	JointController* jointController 		= new JointController( new PCA9685PwmController(), externalFileSystemController);
	MotionController* motionController 		= new MotionController(headerController, frameController, externalFileSystemController, jointController);
	ProcessController* processController	= new ProcessController(jointController, motionController);

	return new PlenController(
			jointController,
			motionController,
			interpreter,
			eyeController,
			externalFileSystemController,
			parserController,
			processController);
}
