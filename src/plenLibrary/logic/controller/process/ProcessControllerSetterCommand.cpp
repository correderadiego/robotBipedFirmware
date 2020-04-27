/*
 * ProcessControllerSetterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/process/ProcessControllerSetterCommand.h>

ProcessControllerSetterCommand::ProcessControllerSetterCommand() {}

bool ProcessControllerSetterCommand::match(CommandInterface* command){
	if(command->getCommandType() == CommandInterface::SETTER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
		ProcessControllerSetterCommand::process(Plen* plen, CommandInterface* command){
//	SetterCommand controllerCommand = (SetterCommand) command;
//
//	if(controllerCommand.getSubCommandType() == SetterCommand::SET_MOTION_HEADER){
//		return NO_ERROR;
//	}
//	if(controllerCommand.getSubCommandType() == SetterCommand::SET_MOTION_FRAME){
//		return NO_ERROR;
//	}
//	if(controllerCommand.getSubCommandType() == SetterCommand::RESET_JOINT_SETTINGS){
//		//TODO reset joint settings
//		return NO_ERROR;
//	}
//	if(controllerCommand.getSubCommandType() == SetterCommand::SET_HOME_VALUE){
//		SetHomeValueCommand setHomeValueCommand = (SetHomeValueCommand)controllerCommand;
//		plen->getJointVector()[setHomeValueCommand.getDeviceId()]->
//				setAngleHome(setHomeValueCommand.getValue());
//		return NO_ERROR;
//	}
//	if(controllerCommand.getSubCommandType() == SetterCommand::SET_MAX_VALUE){
//		SetMaxValueCommand setMaxValueCommand = (SetMaxValueCommand)controllerCommand;
//		plen->getJointVector()[setMaxValueCommand.getDeviceId()]->
//				setAngleHome(setMaxValueCommand.getValue());
//		return NO_ERROR;
//	}
//	if(controllerCommand.getSubCommandType() == SetterCommand::SET_MIN_VALUE){
//		SetMinValueCommand setMinValueCommand = (SetMinValueCommand)controllerCommand;
//		plen->getJointVector()[setMinValueCommand.getDeviceId()]->
//				setAngleMin(setMinValueCommand.getValue());
//		return NO_ERROR;
//	}

	return UNKNOWN_COMMAND;
}
