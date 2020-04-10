/*
 * Plen.h
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENCONTROLLER_H_
#define SRC_PLENCONTROLLER_H_


#include <plenLibrary/logic/bean/Buffer.h>
#include <plenLibrary/logic/bean/commands/CommandInterface.h>
#include <plenLibrary/logic/bean/Plen.h>
#include <plenLibrary/logic/controller/hardware/ExternalFileSystemController.h>
#include <plenLibrary/logic/controller/hardware/EyeController.h>
#include <plenLibrary/logic/controller/hardware/HttpServerController.h>
#include <plenLibrary/logic/controller/hardware/JointController.h>
#include <plenLibrary/logic/controller/hardware/WifiController.h>
#include <plenLibrary/logic/controller/Interpreter.h>
#include <plenLibrary/logic/controller/MotionController.h>
#include <plenLibrary/logic/controller/parser/ParserController.h>
#include <plenLibrary/logic/controller/process/ProcessController.h>
#include <plenLibrary/utils/Logger.h>
#include <string.h>
#include <Wire.h>
#include <Servo.h>

#include "hardware/SerialCommunication.h"
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
