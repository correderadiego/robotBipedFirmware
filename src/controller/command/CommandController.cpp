/*
 * CommandController.cpp
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#include <controller/command/CommandController.h>

CommandController::CommandController() {}

CommandControllerInterface::CommandControllerErrors CommandController::process(CommandInterface command){

	for (unsigned int i= 0; i < sizeof(commandController)/sizeof(commandController[0]); i++) {
		if (commandController[i]->match(command)) {
			return commandController[i]->process(command);
		}
	}

	return CommandControllerInterface::UNKNOWN_COMMAND;
}
