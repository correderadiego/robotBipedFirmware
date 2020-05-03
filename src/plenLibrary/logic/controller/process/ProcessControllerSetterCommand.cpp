/*
 * ProcessControllerSetterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/process/ProcessControllerSetterCommand.h>

ProcessControllerSetterCommand::ProcessControllerSetterCommand(JointController* jointController) {
	this->jointController = jointController;
}

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
		delete command;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::SET_MOTION_FRAME){
		delete command;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::RESET_JOINT_SETTINGS){
		for (int i = 0; i < plen->getJointSize(); i++) {
			jointController->resetJoint((plen->getJointVector()[i]));
			jointController->storeJoint( plen, plen->getJointVector()[i], i);
		}
		delete command;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::SET_ANGLE_HOME_VALUE){
		SetAngleHomeValueCommand* setHomeValueCommand = (SetAngleHomeValueCommand*)controllerCommand;
		plen->getJointVector()[setHomeValueCommand->getDeviceId()]->
				setAngleHome(setHomeValueCommand->getValue());
		jointController->storeJoint(
									plen,
									plen->getJointVector()[setHomeValueCommand->getDeviceId()],
									setHomeValueCommand->getDeviceId()
									);
		delete setHomeValueCommand;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::SET_ANGLE_MAX_VALUE){
		SetAngleMaxValueCommand* setAngleMaxValueCommand = (SetAngleMaxValueCommand*)controllerCommand;
		plen->getJointVector()[setAngleMaxValueCommand->getDeviceId()]->
				setAngleMax(setAngleMaxValueCommand->getValue());
		jointController->storeJoint(
									plen,
									plen->getJointVector()[setAngleMaxValueCommand->getDeviceId()],
									setAngleMaxValueCommand->getDeviceId()
									);
		delete setAngleMaxValueCommand;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == SetterCommand::SET_ANGLE_MIN_VALUE){
		SetMinValueCommand* setMinValueCommand = (SetMinValueCommand*)controllerCommand;
		plen->getJointVector()[setMinValueCommand->getDeviceId()]->
				setAngleMin(setMinValueCommand->getValue());
		jointController->storeJoint(
									plen,
									plen->getJointVector()[setMinValueCommand->getDeviceId()],
									setMinValueCommand->getDeviceId()
									);
		delete setMinValueCommand;
		return NO_ERROR;
	}

	delete command;
	return UNKNOWN_COMMAND;
}
