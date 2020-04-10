/*
 * DumJointSettingsCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#include <plenLibrary/logic/bean/commands/getterCommands/DumpJointSettingsCommand.h>

DumpJointSettingsCommand::DumpJointSettingsCommand(GetterCommand getterCommand){}

DumpJointSettingsCommand::DumpJointSettingsCommand() {
	this->subCommandType = DUMP_JOINT_SETTINGS;
}
