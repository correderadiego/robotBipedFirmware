/*
 * ParserControllerInterpreterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMAND_H_

#include "ParserInterface.h"
#include "bean/Buffer.h"
#include "bean/commands/InterpreterCommand.h"
#include "string.h"

#define INTERPRETER_COMMAND_CHAR '#'

class ParserControllerInterpreterCommand : public ParserInterface {
public:
	ParserControllerInterpreterCommand();
	ParserControllerInterpreterCommand(ParserInterface parserInterface);
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(Buffer* buffer, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERINTERPRETERCOMMAND_H_ */
