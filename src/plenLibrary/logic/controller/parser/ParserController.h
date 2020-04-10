/*
 * ParserController.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSERCONTROLLER_H_
#define SRC_CONTROLLER_PARSERCONTROLLER_H_

#include <plenLibrary/logic/bean/Buffer.h>
#include <plenLibrary/logic/bean/commands/CommandInterface.h>
#include <plenLibrary/logic/controller/parser/ParserControllerControllerCommand.h>
#include <plenLibrary/logic/controller/parser/ParserControllerGetterCommand.h>
#include <plenLibrary/logic/controller/parser/ParserControllerInterpreterCommand.h>
#include <plenLibrary/logic/controller/parser/ParserControllerSetterCommand.h>
#include <plenLibrary/logic/controller/parser/ParserInterface.h>


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
