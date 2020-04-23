/*
 * ApplyNativeValueCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>

ApplyNativeValueCommand::ApplyNativeValueCommand() {
	this->subCommandType 	= APPY_NATIVE_VALUE;
	this->deviceId 			= 0;
	this->value 			= 0;
}

ApplyNativeValueCommand::ApplyNativeValueCommand(ControllerCommand controllerCommand){
	this->commandLength		= controllerCommand.getCommandLength();
	this->commandType		= controllerCommand.getCommandType();
	this->subCommandType 	= APPY_NATIVE_VALUE;
}

ApplyNativeValueCommand::ApplyNativeValueCommand(CommandInterface commandInterfaces){
	this->commandLength		= commandInterfaces.getCommandLength();
	this->commandType		= commandInterfaces.getCommandType();
	this->subCommandType 	= APPY_NATIVE_VALUE;
}

int ApplyNativeValueCommand::getDeviceId(){
	return this->deviceId;
}

void ApplyNativeValueCommand::setDeviceId(int deviceId){
	this->deviceId = deviceId;
}

int ApplyNativeValueCommand::getValue(){
	return this->value;
}

void ApplyNativeValueCommand::setValue(int value){
	this->value = value;
}
