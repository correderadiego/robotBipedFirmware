/*
 * ProcessControllerSetterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <controller/process/ProcessControllerSetterCommand.h>

ProcessControllerSetterCommand::ProcessControllerSetterCommand() {}

bool ProcessControllerSetterCommand::match(CommandInterface command){
	if(command.getCommandType() == CommandInterface::SETTER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
		ProcessControllerSetterCommand::process(CommandInterface command){
	return NO_ERROR;
}
