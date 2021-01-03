/*
 * SetMaxValueCommand.h
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMAXVALUECOMMAND_H_
#define SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMAXVALUECOMMAND_H_

#include <logic/bean/commands/setterCommands/SetterCommand.h>

class SetAngleMaxValueCommand : public SetterCommand{
public:
	SetAngleMaxValueCommand();
	int getDeviceId();
	void setDeviceId(int deviceId);
	int getValue();
	void setValue(int value);
private:
	int deviceId;
	int value;
};

#endif /* SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMAXVALUECOMMAND_H_ */
