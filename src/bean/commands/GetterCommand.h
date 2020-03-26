/*
 * GetterCommand.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_GETTERCOMMAND_H_
#define SRC_BEAN_COMMANDS_GETTERCOMMAND_H_

#include "CommandInterface.h"

class GetterCommand  : public CommandInterface  {
	public:
	#define DUMP_JOINT_SETTINGS_CHAR		"JS"
	#define DUMP_A_MOTION_CHAR				"MO"
	#define DUMP_VERSION_INFORMATION_CHAR	"VI"

	enum SubCommandType	{
						UNKNOWN_SUB_COMMAND_TYPE = -1,
						DUMP_JOINT_SETTINGS,
						DUMP_A_MOTION,
						DUMP_VERSION_INFORMATION
					};
	GetterCommand(CommandInterface command);
	GetterCommand(CommandType commandType = GETTER_COMMAND);
	void setSubCommandType	(SubCommandType subCommandType);
	void setCommandType		(CommandType commandType);
	int getCommandLength	();
	CommandInterface::CommandType getCommandType();

private:
	SubCommandType subCommandType;
};

#endif /* SRC_BEAN_COMMANDS_GETTERCOMMAND_H_ */