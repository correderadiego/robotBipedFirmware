/*
 * ProcessControllerControllerCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: Diego
 */

#include <logic/controller/process/ProcessControllerControllerCommand.h>

ProcessControllerControllerCommand::ProcessControllerControllerCommand(
		JointController* jointController, MotionController* motionController) {
	this->motionController = motionController;
	this->jointController  = jointController;
}

ProcessControllerControllerCommand::~ProcessControllerControllerCommand() {}

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
		plen->getJointVector()[applyNativeValueCommand->getDeviceId()]->setEnabled(true);
		plen->getJointVector()[applyNativeValueCommand->getDeviceId()]->setAngle(applyNativeValueCommand->getValue());
		jointController->updateJointPosition(plen->getJointVector(), plen->getJointSize());
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
		PlayAMotionCommand* playAMotionCommand = (PlayAMotionCommand*)command;
		motionController->getMotion(plen->getFileMotion(), playAMotionCommand->getPosition(), plen->getMotion());
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

	if(controllerCommand->getSubCommandType() == ControllerCommand::APPLY_JOINT_POSITION){
		ApplyJointPositionCommand* applyJointPositionCommand = (ApplyJointPositionCommand*)command;

		if (applyJointPositionCommand->getJoint() > plen->getJointSize()) {
			delete command;
			return INVALID_VALUE;
		}

		if (applyJointPositionCommand->getJoint() < 0 ) {
			delete command;
			return INVALID_VALUE;
		}

		/**
		 * TODO check position values
		 */
		if (applyJointPositionCommand->getPosition() < 0 ) {
			delete command;
			return INVALID_VALUE;
		}

		plen->getJointVector()[applyJointPositionCommand->getJoint()]->setAngle(applyJointPositionCommand->getPosition());

		return NO_ERROR;
		delete command;
	}

	delete command;
	return UNKNOWN_COMMAND;
}

