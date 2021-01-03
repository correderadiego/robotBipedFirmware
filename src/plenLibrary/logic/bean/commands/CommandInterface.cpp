/*
 * CommandInterface.h
 *
 *  Created on: 25 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/CommandInterface.h>

CommandInterface::CommandInterface(CommandTypeEnum commandType){
	this->commandType 	= commandType;
	this->commandLength = 0;
}

CommandInterface::~CommandInterface() {}

void CommandInterface::setCommandType(CommandTypeEnum commandType){
	this->commandType = commandType;
}

CommandInterface::CommandTypeEnum CommandInterface::getCommandType(){
	return this->commandType;
}

int CommandInterface::getCommandLength(){
	return this->commandLength;
}

void CommandInterface::setCommandLength(int commandLength){
	this->commandLength = commandLength;
}
