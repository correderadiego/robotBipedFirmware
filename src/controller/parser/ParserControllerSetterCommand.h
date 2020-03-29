/*
 * ParserControllerSetterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_

#include "ParserInterface.h"
#include "bean/Buffer.h"
#include "bean/commands/setterCommands/SetterCommand.h"
#include "string.h"

#define SETTER_COMMAND_CHAR 	 '>'

class ParserControllerSetterCommand : public ParserInterface  {
public:
	ParserControllerSetterCommand();
	ParserControllerSetterCommand(ParserInterface parserInterface);
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(Buffer* buffer, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_ */
