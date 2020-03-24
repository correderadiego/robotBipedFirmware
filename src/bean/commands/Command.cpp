/*
 * Command.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include "Command.h"

Command::Command() {
	this->commandType   = UNKNOWN_COMMAND_TYPE;
	this->commandState  = READY2;
	this->commandLength = HEADER_LENGTH;
}

Command::Command(CommandType commandType) {
	this->commandType   = commandType;
	this->commandState  = READY2;
	this->commandLength = ZERO_LENGHT;
}

void Command::setCommandType(CommandType commandType){
	this->commandType = commandType;
}

int Command::getCommandLength(){
	if(this->commandState == HEADER_INCOMING2){
		return HEADER_LENGTH;
	}

	if(this->commandState == COMMAND_INCOMING2){
		return COMMAND_LENGTH;
	}
	return ZERO_LENGHT;
}

Command::CommandState Command::getCommandState(){
	return this->commandState;
}

Command::CommandType Command::getCommandType(){
	return this->commandType;
}

void Command::setSubCommandType(SubCommandType subCommandType){
	this->subCommandType = subCommandType;
}


Command::~Command() {}
