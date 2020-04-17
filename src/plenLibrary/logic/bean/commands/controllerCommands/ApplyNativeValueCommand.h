/*
 * ApplyNativeValueCommand.h
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYNATIVEVALUECOMMAND_H_
#define SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYNATIVEVALUECOMMAND_H_

#include <logic/bean/commands/controllerCommands/ControllerCommand.h>

class ApplyNativeValueCommand : public ControllerCommand{
public:
	ApplyNativeValueCommand();
	ApplyNativeValueCommand(ControllerCommand controllerCommand);
	int getDeviceId();
	void setDeviceId(int deviceId);
	int getValue();
	void setValue(int value);

private:
	int deviceId;
	int value;
};

#endif /* SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_APPLYNATIVEVALUECOMMAND_H_ */
