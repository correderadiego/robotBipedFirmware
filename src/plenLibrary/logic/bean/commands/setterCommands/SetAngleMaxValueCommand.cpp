/*
 * SetMaxValueCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/setterCommands/SetAngleMaxValueCommand.h>

SetAngleMaxValueCommand::SetAngleMaxValueCommand() {
	this->subCommandType = SET_ANGLE_MAX_VALUE;
	this->deviceId 		= 0;
	this->value 		= 0;
}

SetAngleMaxValueCommand::SetAngleMaxValueCommand(SetterCommand setterCommand){

}

int SetAngleMaxValueCommand::getDeviceId(){
	return this->deviceId;
}

void SetAngleMaxValueCommand::setDeviceId(int deviceId){
	this->deviceId = deviceId;
}

int SetAngleMaxValueCommand::getValue(){
	return this->value;
}

void SetAngleMaxValueCommand::setValue(int value){
	this->value = value;
}
