/*
 * SetMotionFrame.cpp
 *
 *  Created on: 3 abr. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/setterCommands/SetMotionFrameCommand.h>

SetMotionFrameCommand::SetMotionFrameCommand() {
	this->subCommandType = SET_MOTION_FRAME;
	this->frame = new Frame();
}

void SetMotionFrameCommand::setMotionFrame(Frame* frame){
	delete this->frame;
	this->frame = frame;
}

Frame* SetMotionFrameCommand::getMotionFrame(){
	return this->frame;
}

SetMotionFrameCommand::~SetMotionFrameCommand(){
	delete this->frame;
	this->frame = nullptr;
}
