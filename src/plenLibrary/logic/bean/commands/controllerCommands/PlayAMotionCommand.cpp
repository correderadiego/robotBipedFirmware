/*
 * PlayAMotion.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/controllerCommands/PlayAMotionCommand.h>

PlayAMotionCommand::PlayAMotionCommand() {
	this->subCommandType 	= PLAY_A_MOTION;
	this->position 				= 0;
}

int PlayAMotionCommand::getPosition(){
	return position;
}

void PlayAMotionCommand::setPosition(int slot){
	this->position = slot;
}
