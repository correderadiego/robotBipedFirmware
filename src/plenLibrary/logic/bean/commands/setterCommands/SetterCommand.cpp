/*
 * SetterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/setterCommands/SetterCommand.h>

SetterCommand::SetterCommand(CommandInterface command) {
	this->commandType 	= SETTER_COMMAND;
	this->commandLength = command.getCommandLength();
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

SetterCommand::SetterCommand() {
	this->commandType  	 = SETTER_COMMAND;
	this->commandLength  = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

void SetterCommand::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}

SetterCommand::SubCommandType SetterCommand::getSubCommandType(){
	return this->subCommandType;
}
