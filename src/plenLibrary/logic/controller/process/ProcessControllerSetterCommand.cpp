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
	SetterCommand* controllerCommand = (SetterCommand*) command;

	if(controllerCommand->getSubCommandType() == SetterCommand::SET_MOTION_HEADER){
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::SET_MOTION_FRAME){
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::RESET_JOINT_SETTINGS){
		//TODO reset joint settings
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::SET_ANGLE_HOME_VALUE){
		SetAngleHomeValueCommand* setHomeValueCommand = (SetAngleHomeValueCommand*)controllerCommand;
		plen->getJointVector()[setHomeValueCommand->getDeviceId()]->
				setAngleHome(setHomeValueCommand->getValue());
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::SET_ANGLE_MAX_VALUE){
		SetAngleMaxValueCommand* setAngleMaxValueCommand = (SetAngleMaxValueCommand*)controllerCommand;
		plen->getJointVector()[setAngleMaxValueCommand->getDeviceId()]->
				setAngleMax(setAngleMaxValueCommand->getValue());
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::SET_ANGLE_MIN_VALUE){
		SetMinValueCommand* setMinValueCommand = (SetMinValueCommand*)controllerCommand;
		plen->getJointVector()[setMinValueCommand->getDeviceId()]->
				setAngleMin(setMinValueCommand->getValue());
		(new ExternalFileSystemController())->writeMinAngle(plen, plen->getJointVector()[setMinValueCommand->getDeviceId()]);
		return NO_ERROR;
	}

	return UNKNOWN_COMMAND;
}
