/*
 * PlenControllerFactory.cpp
 *
 *  Created on: 19 mar. 2020
 *      Author: ziash
 */

#include <plenLibrary/logic/PlenControllerFactory.h>

PlenController* PlenControllerFactory::getPlenController(){
	JointController* jointController 	= new JointController(new PCA9685PwmController());
	///MotionController* motionController	= new MotionController(*jointController);
	//TODO
	MotionController* motionController;
	Interpreter* interpreter 									= new Interpreter();
	LedController* ledController								= new LedController();
	EyeController* eyeController								= new EyeController(ledController);
	WifiController* wifiController								= new WifiController();
	HttpServerController* httpServerController 					= new HttpServerController();
	ExternalFileSystemController* externalFileSystemController  = new ExternalFileSystemController();
	ParserController* parserController 							= new ParserController();
	ProcessController* processController						= new ProcessController();

	return new PlenController(
			jointController,
			motionController,
			interpreter,
			eyeController,
			wifiController,
			httpServerController,
			externalFileSystemController,
			parserController,
			processController);
}