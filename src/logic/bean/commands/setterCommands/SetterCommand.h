/*
 * SetterCommand.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_SETTERCOMMAND_H_
#define SRC_BEAN_COMMANDS_SETTERCOMMAND_H_

#include "logic/bean/commands/CommandInterface.h"

class SetterCommand  : public CommandInterface  {
public:
	#define SET_MOTION_HEADER_CHAR		"MH"
	#define SET_MOTION_FRAME_CHAR		"MF"
	#define RESET_JOINT_SETTINGS_CHAR	"JS"
	#define SET_HOME_VALUE_CHAR			"HO"
	#define SET_MAX_VALUE_CHAR			"MA"
	#define SET_MIN_VALUE_CHAR			"MI"

	enum SubCommandType	{
							UNKNOWN_SUB_COMMAND_TYPE = -1,
							SET_MOTION_HEADER,
							SET_MOTION_FRAME,
							RESET_JOINT_SETTINGS,
							SET_HOME_VALUE,
							SET_MAX_VALUE,
							SET_MIN_VALUE
						};
	SetterCommand(CommandInterface command);
	SetterCommand(CommandType commandType = SETTER_COMMAND);
	void setSubCommandType	(SubCommandType subCommandType);
	SubCommandType getSubCommandType ();

protected:
	SubCommandType subCommandType;
};

#endif /* SRC_BEAN_COMMANDS_SETTERCOMMAND_H_ */
