/*
 * SetHomeValueCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/setterCommands/SetAngleHomeValueCommand.h>

SetAngleHomeValueCommand::SetAngleHomeValueCommand() {
	this->subCommandType = SET_ANGLE_HOME_VALUE;
	this->deviceId 		= 0;
	this->value 		= 0;
}

int SetAngleHomeValueCommand::getDeviceId(){
	return this->deviceId;
}

void SetAngleHomeValueCommand::setDeviceId(int deviceId){
	this->deviceId = deviceId;
}

int SetAngleHomeValueCommand::getValue(){
	return this->value;
}

void SetAngleHomeValueCommand::setValue(int value){
	this->value = value;
}
