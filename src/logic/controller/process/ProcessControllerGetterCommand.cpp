/*
 * ProccessControllerGetterCommand.cpp
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/process/ProcessControllerGetterCommand.h>

ProcessControllerGetterCommand::ProcessControllerGetterCommand() {}

bool ProcessControllerGetterCommand::match(CommandInterface command){
	if(command.getCommandType() == CommandInterface::GETTER_COMMAND){
		return true;
	}
	return false;
}

ProcessControllerInterface::CommandControllerErrors
			ProcessControllerGetterCommand::process(Plen* plen, CommandInterface command){
	GetterCommand getterCommand = (GetterCommand) command;

	if(getterCommand.getSubCommandType() == GetterCommand::DUMP_JOINT_SETTINGS){
		DumpJointSettingsCommand dumpJointSettingsCommand = (DumpJointSettingsCommand)getterCommand;
		for (int i = 0; i < plen->getJointSize(); i++) {
			plen->getJointVector()[i]->dump();
		}
		return NO_ERROR;
	}

	if(getterCommand.getSubCommandType() == GetterCommand::DUMP_A_MOTION){
		return NO_ERROR;
	}

	if(getterCommand.getSubCommandType() == GetterCommand::DUMP_VERSION_INFORMATION){
		return NO_ERROR;
	}
	return UNKNOWN_COMMAND;
}

