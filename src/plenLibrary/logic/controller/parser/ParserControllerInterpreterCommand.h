/*
 * ParserControllerInterpreterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMAND_H_

#include <ArduinoIncludes.h>
#include <logic/bean/commands/interpreterCommands/InterpreterCommand.h>
#include <logic/bean/commands/interpreterCommands/PopAFunctionCommand.h>
#include <logic/bean/commands/interpreterCommands/PushAFunctionCommand.h>
#include <logic/bean/commands/interpreterCommands/ResetInterpreterCommand.h>
#include <logic/bean/hardware/Buffer.h>
#include <logic/controller/parser/ParserInterface.h>
#include "string.h"


#define INTERPRETER_COMMAND_CHAR 			'#'
#define POP_CODE_COMMAND_LENGTH				0
#define PUSH_CODE_COMMAND_LENGTH			4
#define RESET_INTERPRETER_COMMAND_LENGHT	0

class ParserControllerInterpreterCommand : public ParserInterface {
public:
	ParserControllerInterpreterCommand();
	ParserControllerInterpreterCommand(ParserInterface parserInterface);
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parsePopCodeCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parsePushCodeCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseResetInterpreterCommand(
			Buffer* buffer, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMAND_H_ */
