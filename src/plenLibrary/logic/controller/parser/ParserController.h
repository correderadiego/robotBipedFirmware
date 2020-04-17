/*
 * ParserController.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSERCONTROLLER_H_
#define SRC_CONTROLLER_PARSERCONTROLLER_H_

#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/hardware/Buffer.h>
#include <logic/controller/parser/ParserControllerControllerCommand.h>
#include <logic/controller/parser/ParserControllerGetterCommand.h>
#include <logic/controller/parser/ParserControllerInterpreterCommand.h>
#include <logic/controller/parser/ParserControllerSetterCommand.h>
#include <logic/controller/parser/ParserInterface.h>


class ParserController {
public:
	#define PARSER_CONTROLLER_VECTOR_SIZE	 4
	#define MIN_MESSAGE_SIZE 				 3

	ParserController();
	ParserInterface::ParseErrors parse(Buffer* buffer, CommandInterface command);

private:

	ParserInterface* parseController[PARSER_CONTROLLER_VECTOR_SIZE] = {
											new ParserControllerControllerCommand(),
											new ParserControllerInterpreterCommand(),
											new ParserControllerSetterCommand(),
											new ParserControllerGetterCommand()
										  };
};

#endif /* SRC_CONTROLLER_PARSERCONTROLLER_H_ */
