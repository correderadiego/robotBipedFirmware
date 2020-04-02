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
#include "controller/process/ProcessController.h"
#include "bean/commands/CommandInterface.h"

#include "bean/Plen.h"
#include "hardware/SerialCommunication.h"
#include "bean/Buffer.h"
#include "utils/Logger.h"

class PlenController{
public:
	enum ParseInputCharError{
	  BUFFER_FULL_ERROR,
	  COMMAND_INCOMPLETE_ERROR,
	  WRONG_LENGHT_COMMAND_ERROR,
	  UNKNOWN_COMMAND_ERROR,
	  NO_ERROR = 0
	};

	PlenController(
			JointController*  				jointController,
			MotionController* 				motionController,
			Interpreter*      				interpreter,
			EyeController*	  				eyeController,
			WifiController*   				wifiController,
			HttpServerController* 			HttpServerController,
			ExternalFileSystemController* 	externalFileSystemController,
			ParserController*				parserController,
			ProcessController* 				processController);
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
	ProcessController* 				processController;
	void initPlenController(Plen* plen);
	void loadFileConfiguration(Plen* plen);

	void socketController(Plen* plen);
	void processInputChar(Plen* plen, char character);
	ParseInputCharError parseInputChar(Plen* plen, char character, CommandInterface command);
	void serialSocketController(Plen* plen);
	void tcpSocketController(Plen* plen);
};

#endif /* SRC_PLENCONTROLLER_H_ */
