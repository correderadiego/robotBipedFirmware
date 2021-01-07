/*
 * ApplyDiffValueCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/controllerCommands/ApplyDiffValueCommand.h>

ApplyDiffValueCommand::ApplyDiffValueCommand() {
	this->subCommandType 	= APPLY_DIFF_VALUE;
	this->deviceId 			= 0;
	this->value 			= 0;
}

int ApplyDiffValueCommand::getDeviceId(){
	return this->deviceId;
}

void ApplyDiffValueCommand::setDeviceId(int deviceId){
	this->deviceId = deviceId;
}

int ApplyDiffValueCommand::getValue(){
	return this->value;
}

void ApplyDiffValueCommand::setValue(int value){
	this->value = value;
}
