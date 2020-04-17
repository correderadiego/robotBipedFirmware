/*
 * DumJointSettingsCommand.h
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPJOINTSETTINGSCOMMAND_H_
#define SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPJOINTSETTINGSCOMMAND_H_

#include <logic/bean/commands/getterCommands/GetterCommand.h>

class DumpJointSettingsCommand :public GetterCommand{
public:
	DumpJointSettingsCommand();
	DumpJointSettingsCommand(GetterCommand getterCommand);
};

#endif /* SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPJOINTSETTINGSCOMMAND_H_ */
