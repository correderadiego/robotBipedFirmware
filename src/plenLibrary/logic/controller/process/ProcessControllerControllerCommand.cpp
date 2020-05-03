/*
 * ProcessControllerControllerCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/process/ProcessControllerControllerCommand.h>

ProcessControllerControllerCommand::ProcessControllerControllerCommand() {}

bool ProcessControllerControllerCommand::match(CommandInterface* command){
	if(command->getCommandType() == CommandInterface::CONTROLLER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
		ProcessControllerControllerCommand::process(Plen* plen, CommandInterface* command){
	ControllerCommand* controllerCommand = (ControllerCommand*)command;

	if(controllerCommand->getSubCommandType() == ControllerCommand::APPY_NATIVE_VALUE){
		ApplyNativeValueCommand* applyNativeValueCommand = (ApplyNativeValueCommand*)command;
		plen->getJointVector()[applyNativeValueCommand->getDeviceId()]->setAngle(applyNativeValueCommand->getValue());
		delete applyNativeValueCommand;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == ControllerCommand::APPLY_DIFF_VALUE){
		ApplyDiffValueCommand* applyDiffValueCommand = (ApplyDiffValueCommand*)command;
		int angle = plen->getJointVector()[applyDiffValueCommand->getDeviceId()]->getAngleHome() + applyDiffValueCommand->getValue();
		plen->getJointVector()[applyDiffValueCommand->getDeviceId()]->setAngle(angle);
		delete applyDiffValueCommand;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == ControllerCommand::PLAY_A_MOTION){
		//TODO play a motion
		PlayAMotionCommand* playAMotionCommand = (PlayAMotionCommand*)command;
		delete playAMotionCommand;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == ControllerCommand::STOP_A_MOTION){
		//TODO stop motion
		StopAMotionCommand* stopAMotionCommand = (StopAMotionCommand*)command;
		delete stopAMotionCommand;
		return NO_ERROR;
	}
	if(controllerCommand->getSubCommandType() == ControllerCommand::APPLY_HOME_POSITION){
		for (int i = 0; i < plen->getJointSize(); i++) {
			plen->getJointVector()[i]->setAngle(plen->getJointVector()[i]->getAngleHome());
		}
		return NO_ERROR;
		delete command;
	}

	delete command;
	return UNKNOWN_COMMAND;
}

