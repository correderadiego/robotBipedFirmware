/*
 * DumJointSettingsCommand.cpp
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#include <logic/bean/commands/getterCommands/DumpJointSettingsCommand.h>

DumpJointSettingsCommand::DumpJointSettingsCommand(GetterCommand getterCommand){}

DumpJointSettingsCommand::DumpJointSettingsCommand() {
	this->subCommandType = DUMP_JOINT_SETTINGS;
}
