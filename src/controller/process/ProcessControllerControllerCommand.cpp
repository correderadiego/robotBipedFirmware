/*
 * ProcessControllerControllerCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <controller/process/ProcessControllerControllerCommand.h>

ProcessControllerControllerCommand::ProcessControllerControllerCommand() {}

bool ProcessControllerControllerCommand::match(CommandInterface command){
	if(command.getCommandType() == CommandInterface::CONTROLLER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
		ProcessControllerControllerCommand::process(CommandInterface command){
	return NO_ERROR;

}
