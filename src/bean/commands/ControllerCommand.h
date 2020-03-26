/*
 * Controller.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_CONTROLLERCOMMAND_H_
#define SRC_BEAN_COMMANDS_CONTROLLERCOMMAND_H_

#include "CommandInterface.h"

class ControllerCommand : public CommandInterface {
public:
	#define APPY_NATIVE_CHAR			"AN"
	#define APPLY_DIFF_CHAR				"AD"
	#define PLAY_A_MOTION_CHAR			"PM"
	#define STOP_A_MOTION_CHAR			"SM"
	#define APPLY_HOME_POSITION_CHAR	"HP"

	enum SubCommandType	{
							UNKNOWN_SUB_COMMAND_TYPE = -1,
							APPY_NATIVE_VALUE,
							APPLY_DIFF_VALUE,
							PLAY_A_MOTION,
							STOP_A_MOTION,
							APPLY_HOME_POSITION
						};
	ControllerCommand(CommandInterface command);
	ControllerCommand(CommandType commandType = CONTROLLER_COMMAND);
	void setSubCommandType	(SubCommandType subCommandType);
	void setCommandType		(CommandType commandType);
	int getCommandLength	();
	CommandInterface::CommandType getCommandType();

private:
	SubCommandType subCommandType;
};

#endif /* SRC_BEAN_COMMANDS_CONTROLLERCOMMAND_H_ */
