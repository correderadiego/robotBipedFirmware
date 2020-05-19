/*
 * DumpMotion.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/commands/getterCommands/DumpMotionCommand.h>

DumpMotionCommand::DumpMotionCommand() {
	this->subCommandType = DUMP_MOTION;
	this->slot = 0;
}

int DumpMotionCommand::getSlot(){
	return this->slot;
}

void DumpMotionCommand::setSlot(int slot){
	this->slot = slot;
}

