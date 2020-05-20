/*
 * SetMotionFrame.cpp
 *
 *  Created on: 3 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/setterCommands/SetMotionFrameCommand.h>

SetMotionFrameCommand::SetMotionFrameCommand() {
	this->subCommandType = SET_MOTION_FRAME;
}

void SetMotionFrameCommand::setMotionFrame(Frame* frame){
	this->frame = frame;
}

Frame* SetMotionFrameCommand::getMotionFrame(){
	return this->frame;
}

SetMotionFrameCommand::~SetMotionFrameCommand(){
	frame = nullptr;
	delete frame;
}
