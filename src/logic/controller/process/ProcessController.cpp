/*
 * CommandController.cpp
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/process/ProcessController.h>

ProcessController::ProcessController() {}

ProcessControllerInterface::CommandControllerErrors ProcessController::process(Plen* plen, CommandInterface command){

	for (unsigned int i= 0; i < sizeof(commandController)/sizeof(commandController[0]); i++) {
		if (commandController[i]->match(command)) {
			return commandController[i]->process(plen, command);
		}
	}

	return ProcessControllerInterface::UNKNOWN_COMMAND;
}
