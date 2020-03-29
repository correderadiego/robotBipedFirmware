/*
 * ParserControllerGetterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_

#include "ParserInterface.h"
#include "bean/Buffer.h"
#include "bean/commands/GetterCommand.h"
#include "string.h"

#define GETTER_COMMAND_CHAR 	 '<'

class ParserControllerGetterCommand : public ParserInterface {
public:
	ParserControllerGetterCommand();
	ParserControllerGetterCommand(ParserInterface parserInterface);
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(Buffer* buffer, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_ */
