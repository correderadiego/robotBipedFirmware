/*
 * ProcessControllerInterpreterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/process/ProcessControllerInterpreterCommand.h>

ProcessControllerInterpreterCommand::ProcessControllerInterpreterCommand() {}

bool ProcessControllerInterpreterCommand::match(CommandInterface* command){
	if((*command).getCommandType() == CommandInterface::INTERPRETER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
		ProcessControllerInterpreterCommand::process(Plen* plen, CommandInterface* command){
	InterpreterCommand* interpreterCommand = (InterpreterCommand*)command;
	delete interpreterCommand;
	return NO_ERROR;
}
