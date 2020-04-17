/*
 * GetterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/getterCommands/GetterCommand.h>

GetterCommand::GetterCommand(CommandInterface command) {
	this->commandType 	= GETTER_COMMAND;
	this->commandLength = command.getCommandLength();
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

GetterCommand::GetterCommand() {
	this->commandType  	 = GETTER_COMMAND;
	this->commandLength  = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

void GetterCommand::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}

GetterCommand::SubCommandType GetterCommand::getSubCommandType(){
	return this->subCommandType;
}
