/*
 * ApplyDiffValueCommand.h
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYDIFFVALUECOMMAND_H_
#define SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYDIFFVALUECOMMAND_H_

#include <logic/bean/commands/controllerCommands/ControllerCommand.h>

class ApplyDiffValueCommand : public ControllerCommand {
public:
	ApplyDiffValueCommand();
	int getDeviceId();
	void setDeviceId(int deviceId);
	int getValue();
	void setValue(int value);

private:
	int deviceId;
	int value;
};

#endif /* SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYDIFFVALUECOMMAND_H_ */
