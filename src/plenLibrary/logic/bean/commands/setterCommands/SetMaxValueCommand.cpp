/*
 * SetMaxValueCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <plenLibrary/logic/bean/commands/setterCommands/SetMaxValueCommand.h>

SetMaxValueCommand::SetMaxValueCommand() {
	this->subCommandType = SET_MAX_VALUE;
	this->deviceId 		= 0;
	this->value 		= 0;
}

SetMaxValueCommand::SetMaxValueCommand(SetterCommand setterCommand){

}

int SetMaxValueCommand::getDeviceId(){
	return this->deviceId;
}

void SetMaxValueCommand::setDeviceId(int deviceId){
	this->deviceId = deviceId;
}

int SetMaxValueCommand::getValue(){
	return this->value;
}

void SetMaxValueCommand::setValue(int value){
	this->value = value;
}
