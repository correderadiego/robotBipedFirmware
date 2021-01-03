/*
 * SetHeaderFrameCommand.h
 *
 *  Created on: 3 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETHEADERFRAMECOMMAND_H_
#define SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETHEADERFRAMECOMMAND_H_

#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include "logic/bean/motion/Header.h"

class SetMotionHeaderCommand : public SetterCommand {
public:
	SetMotionHeaderCommand();
	void setMotionHeader(Header* header);
	Header* getMotionHeader();
	virtual ~SetMotionHeaderCommand();
private:
	Header* header;
};

#endif /* SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETHEADERFRAMECOMMAND_H_ */
