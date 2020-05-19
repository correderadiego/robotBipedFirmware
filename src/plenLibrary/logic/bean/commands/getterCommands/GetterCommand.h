/*
 * GetterCommand.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_GETTERCOMMAND_H_
#define SRC_BEAN_COMMANDS_GETTERCOMMAND_H_

#include <logic/bean/commands/CommandInterface.h>

class GetterCommand  : public CommandInterface  {
	public:
	#define DUMP_JOINT_SETTINGS_CHAR		"JS"
	#define DUMP_A_MOTION_CHAR				"MO"
	#define DUMP_VERSION_INFORMATION_CHAR	"VI"
	#define DUMP_NETWORK_INFORMATION_CHAR	"NI"

	enum SubCommandType	{
						UNKNOWN_SUB_COMMAND_TYPE,
						DUMP_JOINT_SETTINGS,
						DUMP_MOTION,
						DUMP_VERSION_INFORMATION,
						DUMP_NETWORK_INFORMATION
					};
	GetterCommand(CommandInterface command);
	GetterCommand();
	void setSubCommandType	(SubCommandType subCommandType);
	SubCommandType getSubCommandType();

protected:
	SubCommandType subCommandType;
};

#endif /* SRC_BEAN_COMMANDS_GETTERCOMMAND_H_ */
