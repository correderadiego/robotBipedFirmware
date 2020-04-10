/*
 * Plen.h
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENCONTROLLER_H_
#define SRC_PLENCONTROLLER_H_


#include <string.h>
#include <Wire.h>
#include <Servo.h>

#include "MotionController.h"
#include "Interpreter.h"
#include "parser/ParserController.h"
#include "process/ProcessController.h"
#include "hardware/EyeController.h"
#include "hardware/WifiController.h"
#include "hardware/HttpServerController.h"
#include "hardware/ExternalFileSystemController.h"
#include "hardware/JointController.h"
#include "logic/bean/commands/CommandInterface.h"

#include "logic/bean/Plen.h"
#include "hardware/SerialCommunication.h"
#include "logic/bean/Buffer.h"
#include "utils/Logger.h"
#include "Arduino.h"

class PlenController{
public:
	#define DEFAULT_WAIT_PERIOD 1000

	enum ParseInputCharError{
	  NO_ERROR,
	  BUFFER_FULL_ERROR,
	  COMMAND_INCOMPLETE_ERROR,
	  WRONG_LENGTH_COMMAND_ERROR,
	  UNKNOWN_COMMAND_ERROR
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
	unsigned long previousTemporizedWait = millis();

	void initPlenController(Plen* plen);
	void loadFileConfiguration(Plen* plen);

	void socketController(Plen* plen);
	void processInputChar(Plen* plen, char character);
	ParseInputCharError parseInputChar(Plen* plen, char character, CommandInterface command);
	void serialSocketController(Plen* plen);
	void tcpSocketController(Plen* plen);
	void temporizedWait();



};

#endif /* SRC_PLENCONTROLLER_H_ */
