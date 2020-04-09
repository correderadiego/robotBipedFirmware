/*
 * SetMaxValueCommand.h
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMAXVALUECOMMAND_H_
#define SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMAXVALUECOMMAND_H_

#include "SetterCommand.h"

class SetMaxValueCommand : public SetterCommand{
public:
	SetMaxValueCommand();
	SetMaxValueCommand(SetterCommand setterCommand);

	int getDeviceId();
	void setDeviceId(int deviceId);
	int getValue();
	void setValue(int value);
private:
	int deviceId;
	int value;
};

#endif /* SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMAXVALUECOMMAND_H_ */
