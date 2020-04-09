/*
 * DumpMotion.h
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPMOTIONCOMMAND_H_
#define SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPMOTIONCOMMAND_H_

#include "GetterCommand.h"

class DumpMotionCommand : public GetterCommand{
public:
	DumpMotionCommand();

	int getSlot();
	void setSlot(int slot);
private:
	int slot;
};

#endif /* SRC_BEAN_COMMANDS_GETTERCOMMANDS_DUMPMOTIONCOMMAND_H_ */
