/*
 * SetHeaderFrameCommand.cpp
 *
 *  Created on: 3 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/setterCommands/SetMotionHeaderCommand.h>

SetMotionHeaderCommand::SetMotionHeaderCommand() {
	this->subCommandType = SET_MOTION_HEADER;
}

void SetMotionHeaderCommand::setHeader(Header* header){
	this->header = header;
}
Header* SetMotionHeaderCommand::getHeader(){
	return header;
}
