/*
 * DumpMotion.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <bean/commands/getterCommands/DumpMotionCommand.h>

DumpMotionCommand::DumpMotionCommand() {
	this->subCommandType = DUMP_A_MOTION;
	this->slot = 0;
}

int DumpMotionCommand::getSlot(){
	return this->slot;
}

void DumpMotionCommand::setSlot(int slot){
	this->slot = slot;
}

