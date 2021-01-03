/*
 * Controller.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/controllerCommands/ControllerCommand.h>

ControllerCommand::ControllerCommand() {
	this->commandType  	= CONTROLLER_COMMAND;
	this->commandLength = 0;
	this->subCommandType = UNKNOWN_SUB_COMMAND_TYPE;
}

void ControllerCommand::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}

ControllerCommand::SubCommandType ControllerCommand::getSubCommandType(){
	return this->subCommandType;
}
