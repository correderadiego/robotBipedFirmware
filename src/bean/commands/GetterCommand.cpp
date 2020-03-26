/*
 * GetterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <bean/commands/GetterCommand.h>

GetterCommand::GetterCommand(CommandInterface command) {
	this->commandType 	= command.getCommandType();
	this->commandLength = command.getCommandLength();
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

GetterCommand::GetterCommand(CommandType commandType) {
	this->commandType  	 = commandType;
	this->commandLength  = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

void GetterCommand::setCommandType(CommandType commandType){
	this->commandType = commandType;
}

int GetterCommand::getCommandLength(){
	return this->commandLength;
}

CommandInterface::CommandType GetterCommand::getCommandType(){
	return this->commandType;
}
