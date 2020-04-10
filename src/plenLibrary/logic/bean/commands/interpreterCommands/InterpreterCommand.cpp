/*
 * InterpreterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <plenLibrary/logic/bean/commands/interpreterCommands/InterpreterCommand.h>

InterpreterCommand::InterpreterCommand(CommandInterface command) {
	this->commandType 	 = command.getCommandType();
	this->commandLength  = command.getCommandLength();
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

InterpreterCommand::InterpreterCommand() {
	this->commandType  	 = INTERPRETER_COMMAND;
	this->commandLength  = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

void InterpreterCommand::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}

InterpreterCommand::SubCommandType InterpreterCommand::getSubCommandType(){
	return this->subCommandType;
}
