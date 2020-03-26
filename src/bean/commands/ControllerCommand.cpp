/*
 * Controller.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <bean/commands/ControllerCommand.h>

ControllerCommand::ControllerCommand(CommandInterface command) {
	this->commandType 	= command.getCommandType();
	this->commandLength = command.getCommandLength();
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

ControllerCommand::ControllerCommand(CommandType commandType) {
	this->commandType  	 = commandType;
	this->commandLength  = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

void ControllerCommand::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}

void ControllerCommand::setCommandType(CommandType commandType){
	this->commandType = commandType;
}

int ControllerCommand::getCommandLength(){
	return this->commandLength;
}

CommandInterface::CommandType ControllerCommand::getCommandType(){
	return this->commandType;
}
