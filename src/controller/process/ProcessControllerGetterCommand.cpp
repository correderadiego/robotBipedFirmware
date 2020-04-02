/*
 * ProccessControllerGetterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <controller/process/ProcessControllerGetterCommand.h>

ProcessControllerGetterCommand::ProcessControllerGetterCommand() {}

bool ProcessControllerGetterCommand::match(CommandInterface command){
	if(command.getCommandType() == CommandInterface::GETTER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
			ProcessControllerGetterCommand::process(CommandInterface command){
	return NO_ERROR;
}

