/*
 * CommandController.h
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_COMMAND_COMMANDCONTROLLER_H_
#define SRC_CONTROLLER_COMMAND_COMMANDCONTROLLER_H_

#include "controller/command/CommandControllerInterface.h"

class CommandController {
public:
	#define COMMAND_CONTROLLER_VECTOR_SIZE	 4
	CommandController();
	CommandControllerInterface::CommandControllerErrors process(CommandInterface command);

	CommandControllerInterface* commandController[COMMAND_CONTROLLER_VECTOR_SIZE] = {};
};

#endif /* SRC_CONTROLLER_COMMAND_COMMANDCONTROLLER_H_ */
