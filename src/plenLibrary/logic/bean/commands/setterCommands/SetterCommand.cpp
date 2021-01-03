/*
 * SetterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/setterCommands/SetterCommand.h>

SetterCommand::SetterCommand() {
	this->commandType  	 = SETTER_COMMAND;
	this->commandLength  = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

SetterCommand::~SetterCommand() {}

void SetterCommand::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}

SetterCommand::SubCommandType SetterCommand::getSubCommandType(){
	return this->subCommandType;
}
