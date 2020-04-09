/*
 * DumJointSettingsCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include "DumpJointSettingsCommand.h"

DumpJointSettingsCommand::DumpJointSettingsCommand(GetterCommand getterCommand){}

DumpJointSettingsCommand::DumpJointSettingsCommand() {
	this->subCommandType = DUMP_JOINT_SETTINGS;
}
