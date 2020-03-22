/*
 * PlenControllerFactory.cpp
 *
 *  Created on: 19 mar. 2020
 *      Author: ziash
 */

#include <controller/PlenControllerFactory.h>

PlenController* PlenControllerFactory::getPlenController(){
	JointController2* jointController 	= new JointController2();
	///MotionController* motionController	= new MotionController(*jointController);
	//TODO
	MotionController* motionController;
	Interpreter* interpreter 			= new Interpreter(*motionController);
	LedController* ledController		= new LedController();
	EyeController* eyeController		= new EyeController(ledController);
	WifiController* wifiController		= new WifiController();
	HttpServerController* httpServerController = new HttpServerController();
	ExternalFileSystemController* externalFileSystemController = new ExternalFileSystemController();

	return new PlenController(
			jointController,
			motionController,
			interpreter,
			eyeController,
			wifiController,
			httpServerController,
			externalFileSystemController);
}
