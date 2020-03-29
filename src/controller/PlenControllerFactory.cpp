/*
 * PlenControllerFactory.cpp
 *
 *  Created on: 19 mar. 2020
 *      Author: ziash
 */

#include <controller/PlenControllerFactory.h>

PlenController* PlenControllerFactory::getPlenController(){
	JointController* jointController 	= new JointController();
	///MotionController* motionController	= new MotionController(*jointController);
	//TODO
	MotionController* motionController;
	Interpreter* interpreter 			= new Interpreter();
	LedController* ledController		= new LedController();
	EyeController* eyeController		= new EyeController(ledController);
	WifiController* wifiController		= new WifiController();
	HttpServerController* httpServerController = new HttpServerController();
	ExternalFileSystemController* externalFileSystemController = new ExternalFileSystemController();
	ParserController* parserController = new ParserController();


	return new PlenController(
			jointController,
			motionController,
			interpreter,
			eyeController,
			wifiController,
			httpServerController,
			externalFileSystemController,
			parserController);
}
