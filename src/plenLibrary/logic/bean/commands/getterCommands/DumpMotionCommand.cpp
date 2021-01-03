/*
 * DumpMotion.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/getterCommands/DumpMotionCommand.h>

DumpMotionCommand::DumpMotionCommand() {
	this->subCommandType = DUMP_MOTION;
	this->position = 0;
}

int DumpMotionCommand::getPosition(){
	return this->position;
}

void DumpMotionCommand::setPosition(int position){
	this->position = position;
}

