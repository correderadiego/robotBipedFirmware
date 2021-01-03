/*
 * SetMinValueCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/setterCommands/SetMinValueCommand.h>

SetMinValueCommand::SetMinValueCommand() {
	this->subCommandType = SET_ANGLE_MIN_VALUE;
	this->deviceId 		= 0;
	this->value 		= 0;
}

int SetMinValueCommand::getDeviceId(){
	return this->deviceId;
}

void SetMinValueCommand::setDeviceId(int deviceId){
	this->deviceId = deviceId;
}

int SetMinValueCommand::getValue(){
	return this->value;
}

void SetMinValueCommand::setValue(int value){
	this->value = value;
}
