/*
 * ProcessControllerSetterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: Diego
 */

#include <logic/controller/process/ProcessControllerSetterCommand.h>

ProcessControllerSetterCommand::ProcessControllerSetterCommand(
		JointController* jointController, MotionController* motionController) {
	this->jointController  = jointController;
	this->motionController = motionController;
}

bool ProcessControllerSetterCommand::match(CommandInterface* command){
	if(command->getCommandType() == CommandInterface::SETTER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
		ProcessControllerSetterCommand::process(Plen* plen, CommandInterface* command){
	SetterCommand* setterCommand = (SetterCommand*) command;

	if(setterCommand->getSubCommandType() == SetterCommand::SET_MOTION_HEADER){
		SetMotionHeaderCommand* setMotionHeaderCommand = (SetMotionHeaderCommand *)setterCommand;
		motionController->setHeader(
								plen->getFileMotion(),
								setMotionHeaderCommand->getMotionHeader()
							);
		delete setMotionHeaderCommand;
		return NO_ERROR;
	}
	if(setterCommand->getSubCommandType() == SetterCommand::SET_MOTION_FRAME){
		SetMotionFrameCommand* setMotionFrameCommand = (SetMotionFrameCommand *)setterCommand;
		motionController->setFrame(
								plen->getFileMotion(),
								setMotionFrameCommand->getMotionFrame()
							);
		delete setMotionFrameCommand;
		return NO_ERROR;
	}
	if(setterCommand->getSubCommandType() == SetterCommand::RESET_JOINT_SETTINGS){
		for (int i = 0; i < plen->getJointSize(); i++) {
			jointController->resetJoint((plen->getJointVector()[i]));
			jointController->storeJoint( plen, plen->getJointVector()[i], i);
		}
		delete setterCommand;
		return NO_ERROR;
	}
	if(setterCommand->getSubCommandType() == SetterCommand::SET_ANGLE_HOME_VALUE){
		SetAngleHomeValueCommand* setHomeValueCommand = (SetAngleHomeValueCommand*)setterCommand;
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
	if(setterCommand->getSubCommandType() == SetterCommand::SET_ANGLE_MAX_VALUE){
		SetAngleMaxValueCommand* setAngleMaxValueCommand = (SetAngleMaxValueCommand*)setterCommand;
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
	if(setterCommand->getSubCommandType() == SetterCommand::SET_ANGLE_MIN_VALUE){
		SetMinValueCommand* setMinValueCommand = (SetMinValueCommand*)setterCommand;
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

	delete setterCommand;
	return UNKNOWN_COMMAND;
}
