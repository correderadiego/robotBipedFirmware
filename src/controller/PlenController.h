/*
 * Plen.h
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENCONTROLLER_H_
#define SRC_PLENCONTROLLER_H_

#include <controller/JointController.h>
#include <string.h>
#include <Wire.h>
#include <Servo.h>

#include "MotionController.h"
#include "Interpreter.h"
#include "EyeController.h"
#include "WifiController.h"
#include "HttpServerController.h"
#include "ExternalFileSystemController.h"
#include "controller/parser/ParserController.h"
#include "bean/commands/CommandInterface.h"

#include "bean/Plen.h"
#include "hardware/SerialCommunication.h"
#include "bean/Buffer.h"
#include "utils/Logger.h"

class PlenController{
public:
	PlenController(
			JointController*  				jointController,
			MotionController* 				motionController,
			Interpreter*      				interpreter,
			EyeController*	  				eyeController,
			WifiController*   				wifiController,
			HttpServerController* 			HttpServerController,
			ExternalFileSystemController* 	externalFileSystemController,
			ParserController*				parserController);
	void executeThreadTasks(Plen* plen);

private:
	JointController*  				jointController;
	MotionController* 				motionController;
	Interpreter*      				interpreter;
	EyeController*	  				eyeController;
	WifiController*   				wifiController;
	HttpServerController* 			httpServerController;
	ExternalFileSystemController* 	externalFileSystemController;
	ParserController*				parserController;
	void initPlenController(Plen* plen);
	void loadFileConfiguration(Plen* plen);

	void socketController(Plen* plen);
	void proccessInputChar(Plen* plen, char character, CommandInterface command);
	void serialSocketController(Plen* plen);
	void tcpSocketController(Plen* plen);
};

#endif /* SRC_PLENCONTROLLER_H_ */
