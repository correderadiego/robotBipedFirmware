/*
 * DumpMotion.h
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPMOTIONCOMMAND_H_
#define SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPMOTIONCOMMAND_H_

#include <logic/bean/commands/getterCommands/GetterCommand.h>

class DumpMotionCommand : public GetterCommand{
public:
	DumpMotionCommand();

	int getPosition();
	void setPosition(int position);
private:
	int position;
};

#endif /* SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPMOTIONCOMMAND_H_ */
