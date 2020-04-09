/*
 * CommandInterface.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include "CommandInterface.h"

void CommandInterface::setCommandType(CommandType commandType){
	this->commandType = commandType;
}

CommandInterface::CommandType CommandInterface::getCommandType(){
	return this->commandType;
}

int CommandInterface::getCommandLength(){
	return this->commandLength;
}

void CommandInterface::setCommandLength(int commandLength){
	this->commandLength = commandLength;
}
