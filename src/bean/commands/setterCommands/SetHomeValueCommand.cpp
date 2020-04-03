/*
 * SetHomeValueCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <bean/commands/setterCommands/SetHomeValueCommand.h>

SetHomeValueCommand::SetHomeValueCommand() {
	this->subCommandType = SET_HOME_VALUE;
	this->deviceId 		= 0;
	this->value 		= 0;
}

SetHomeValueCommand::SetHomeValueCommand(SetterCommand setterCommand){

}

int SetHomeValueCommand::getDeviceId(){
	return this->deviceId;
}

void SetHomeValueCommand::setDeviceId(int deviceId){
	this->deviceId = deviceId;
}

int SetHomeValueCommand::getValue(){
	return this->value;
}

void SetHomeValueCommand::setValue(int value){
	this->value = value;
}
