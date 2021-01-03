/*
 * SetHeaderFrameCommand.cpp
 *
 *  Created on: 3 abr. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/setterCommands/SetMotionHeaderCommand.h>

SetMotionHeaderCommand::SetMotionHeaderCommand() {
	this->header = new Header();
	this->subCommandType = SET_MOTION_HEADER;
}

SetMotionHeaderCommand::~SetMotionHeaderCommand(){
	delete this->header;
	this->header = nullptr;
}

void SetMotionHeaderCommand::setMotionHeader(Header* header){
	delete this->header;
	this->header = header;
}
Header* SetMotionHeaderCommand::getMotionHeader(){
	return header;
}


