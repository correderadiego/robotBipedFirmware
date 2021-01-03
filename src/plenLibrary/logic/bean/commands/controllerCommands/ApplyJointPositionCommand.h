/*
 * SetJoinPosition.h
 *
 *  Created on: 30 nov. 2020
 *      Author: Diego
 */

#ifndef SRC_PLENLIBRARY_LOGIC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYJOINTPOSITIONCOMMAND_H_
#define SRC_PLENLIBRARY_LOGIC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYJOINTPOSITIONCOMMAND_H_

#include <logic/bean/commands/controllerCommands/ControllerCommand.h>

class ApplyJointPositionCommand : public ControllerCommand {
public:
	ApplyJointPositionCommand();
	int getPosition();
	void setPosition(int position);
	int getJoint();
	void setJoint(int joint);
	virtual ~ApplyJointPositionCommand();
private:
	int position;
	int joint;
};

#endif /* SRC_PLENLIBRARY_LOGIC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYJOINTPOSITIONCOMMAND_H_ */
