/*
 * Plen.h
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENCONTROLLER_H_
#define SRC_PLENCONTROLLER_H_

#include <hardware/bean/SerialCommunication.h>
#include <hardware/controller/ExternalFileSystemController.h>
#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/hardware/Buffer.h>
#include <logic/bean/Plen.h>
#include <logic/controller/EyeController.h>
#include <logic/controller/Interpreter.h>
#include <logic/controller/JointController.h>
#include <logic/controller/MotionController.h>
#include <logic/controller/parser/ParserController.h>
#include <logic/controller/process/ProcessController.h>
#include <utils/Logger.h>
#include <string.h>

#include "Arduino.h"

class PlenController{
public:
	enum ParseBufferErrors{
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
			ExternalFileSystemController* 	externalFileSystemController,
			ParserController*				parserController,
			ProcessController* 				processController);
	void executeThreadTasks(Plen* plen);
	void initPlenController(Plen* plen);

	JointController*  				jointController;

private:

	MotionController* 				motionController;
	Interpreter*      				interpreter;
	EyeController*	  				eyeController;
	ExternalFileSystemController* 	externalFileSystemController;
	ParserController*				parserController;
	ProcessController* 				processController;

	void loadFileConfiguration(Plen* plen);
	void processBuffer(Plen* plen, Buffer* buffer);
	void initFileConfiguration(Plen* plen);
	void loadFileJoints(Plen* plen);
	ParseBufferErrors parseBuffer(Buffer* buffer, CommandInterface** command);
	CommandInterface* command;
};

#endif /* SRC_PLENCONTROLLER_H_ */
