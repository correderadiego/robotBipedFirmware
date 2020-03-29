/*
 * PushAFunction.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <bean/commands/interpreterCommands/PushAFunctionCommand.h>

PushAFunctionCommand::PushAFunctionCommand() {
	this->subCommandType 	= PUSH_A_FUNCTION;
	this->slot 				= 0;
	this->loopCount 		= 0;
}

int PushAFunctionCommand::getSlot(){
	return this->slot;
}

void PushAFunctionCommand::setSlot(int slot){
	this->slot = slot;
}

int PushAFunctionCommand::getLoopCount(){
	return this->loopCount;
}

void PushAFunctionCommand::setLoopCount(int loopCount){
	this->loopCount = loopCount;
}
