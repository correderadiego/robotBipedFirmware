/*
 * PlayAMotion.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/controllerCommands/PlayAMotionCommand.h>

PlayAMotionCommand::PlayAMotionCommand() {
	this->subCommandType 	= PLAY_A_MOTION;
	this->slot 				= 0;
}

int PlayAMotionCommand::getSlot(){
	return slot;
}

void PlayAMotionCommand::setSlot(int slot){
	this->slot;
}
