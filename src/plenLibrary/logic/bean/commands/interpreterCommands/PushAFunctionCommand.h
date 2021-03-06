/*
 * PushAFunction.h
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_COMMANDS_INTERPRETERCOMMANDS_PUSHAFUNCTIONCOMMAND_H_
#define SRC_BEAN_COMMANDS_INTERPRETERCOMMANDS_PUSHAFUNCTIONCOMMAND_H_

#include <logic/bean/commands/interpreterCommands/InterpreterCommand.h>

class PushAFunctionCommand : public InterpreterCommand{
public:
	PushAFunctionCommand();
	int getSlot();
	void setSlot(int slot);

	int getLoopCount();
	void setLoopCount(int loopCount);

private:
	int slot;
	int loopCount;
};

#endif /* SRC_BEAN_COMMANDS_INTERPRETERCOMMANDS_PUSHAFUNCTIONCOMMAND_H_ */
