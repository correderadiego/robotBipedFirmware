/*
 * InterpreterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <bean/commands/InterpreterCommand.h>

InterpreterCommand::InterpreterCommand(CommandInterface command) {
	//this->commandType 	= command.getCommandType();
	//this->commandLength = command.getCommandLength();
	//this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

InterpreterCommand::InterpreterCommand(CommandType commandType) {
	this->commandType  	 = commandType;
	this->commandLength  = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

void InterpreterCommand::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}

InterpreterCommand::SubCommandType InterpreterCommand::getSubCommandType(){
	return this->subCommandType;
}
