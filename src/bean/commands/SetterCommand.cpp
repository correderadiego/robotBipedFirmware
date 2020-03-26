/*
 * SetterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <bean/commands/SetterCommand.h>

SetterCommand::SetterCommand(CommandInterface command) {
	this->commandType 	= command.getCommandType();
	this->commandLength = command.getCommandLength();
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

SetterCommand::SetterCommand(CommandType commandType) {
	this->commandType  	 = commandType;
	this->commandLength  = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

void SetterCommand::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}

void SetterCommand::setCommandType(CommandType commandType){
	this->commandType = commandType;
}

int SetterCommand::getCommandLength(){
	return this->commandLength;
}

CommandInterface::CommandType SetterCommand::getCommandType(){
	return this->commandType;
}
