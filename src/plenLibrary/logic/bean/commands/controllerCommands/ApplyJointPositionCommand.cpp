/*
 * SetJoinPosition.cpp
 *
 *  Created on: 30 nov. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/controllerCommands/ApplyJointPositionCommand.h>

ApplyJointPositionCommand::ApplyJointPositionCommand() {
	this->subCommandType 	= APPLY_JOINT_POSITION;
	this->position 			= 0;
	this->joint 			= 0;
}

int ApplyJointPositionCommand::getPosition(){
	return position;
}

void ApplyJointPositionCommand::setPosition(int position){
	this->position = position;
}

int ApplyJointPositionCommand::getJoint(){
	return joint;
}

void ApplyJointPositionCommand::setJoint(int joint){
	this->joint = joint;
}

ApplyJointPositionCommand::~ApplyJointPositionCommand() {
	// TODO Auto-generated destructor stub
}
