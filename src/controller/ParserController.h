/*
 * ParserController.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSERCONTROLLER_H_
#define SRC_CONTROLLER_PARSERCONTROLLER_H_

#include "bean/commands/Command.h"
#include "bean/commands/ControllerCommand.h"
#include "bean/commands/InterpreterCommand.h"
#include "bean/commands/SetterCommand.h"
#include "bean/commands/GetterCommand.h"
#include "bean/Buffer.h"
#include "string.h"

class ParserController {
public:
	#define CONTROLLER_COMMAND_CHAR  '$'
	#define INTERPRETER_COMMAND_CHAR '#'
	#define SETTER_COMMAND_CHAR 	 '>'
	#define GETTER_COMMAND_CHAR 	 '<'

	enum ParseErrors{
	  UNKNOWN_COMMAND,
	  INCOMPLETE_MESSAGE = -1,
	  NO_ERROR 			 =  0
	};

	ParserController();
	ParseErrors parse(Buffer* buffer, Command command);

private:
	ParserController::ParseErrors parseHeader				(char character, Command command);
	ParserController::ParseErrors parseCommand				(char character, Command command);
	ParserController::ParseErrors parseControllerCommand	(char* characters, ControllerCommand command);
	ParserController::ParseErrors parseInterpreterCommand	(char* characters, InterpreterCommand command);
	ParserController::ParseErrors parseSetterCommand		(char* characters, SetterCommand command);
	ParserController::ParseErrors parseGetterCommand		(char* characters, GetterCommand command);

};

#endif /* SRC_CONTROLLER_PARSERCONTROLLER_H_ */
