/*
 * GetterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/getterCommands/GetterCommand.h>

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
