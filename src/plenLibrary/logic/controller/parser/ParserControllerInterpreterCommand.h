/*
 * ParserControllerInterpreterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: Diego
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
#include "utils/ParserUtils.h"


#define INTERPRETER_COMMAND_CHAR 			'#'
#define POP_A_FUNCTION_COMMAND_LENGTH		3
#define PUSH_A_FUNCTION_COMMAND_LENGTH		7
#define RESET_INTERPRETER_COMMAND_LENGHT	3

#define HEADER_LENGTH			2
#define HEADER_INDEX_POSITION	1

#define SLOT_LENGTH				2
#define SLOT_POSITION			HEADER_INDEX_POSITION + HEADER_LENGTH

#define LOOP_COUNT_LENGTH							2
#define LOOP_COUNT_POSITION_INTERPRETER_COMMAND		SLOT_POSITION + SLOT_LENGTH

class ParserControllerInterpreterCommand : public ParserInterface {
public:
	ParserControllerInterpreterCommand();
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parsePopAFunctionCommand(
			Buffer* buffer, PopAFunctionCommand** command);
	ParserInterface::ParseErrors parsePushAFunctionCommand(
			Buffer* buffer, PushAFunctionCommand** command);
	ParserInterface::ParseErrors parseResetInterpreterCommand(
			Buffer* buffer, ResetInterpreterCommand** command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMAND_H_ */
