/*
 * ParserControllerCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_

#include "ParserInterface.h"
#include "bean/Buffer.h"
#include "bean/commands/controllerCommands/ControllerCommand.h"
#include "string.h"

#define CONTROLLER_COMMAND_CHAR  '$'

class ParserControllerControllerCommand : public ParserInterface{
public:
	ParserControllerControllerCommand();
	ParserControllerControllerCommand(ParserInterface parserInterface);
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseSubCommandType(
												Buffer* buffer, ControllerCommand command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_ */
