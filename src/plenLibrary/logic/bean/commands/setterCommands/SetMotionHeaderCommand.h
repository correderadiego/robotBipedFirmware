/*
 * SetHeaderFrameCommand.h
 *
 *  Created on: 3 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETHEADERFRAMECOMMAND_H_
#define SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETHEADERFRAMECOMMAND_H_

#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include "logic/bean/motion/Header.h"

class SetMotionHeaderCommand : public SetterCommand {
public:
	SetMotionHeaderCommand();
	void setHeader(Header* header);
	Header* getHeader();
private:
	Header* header = new Header();
};

#endif /* SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETHEADERFRAMECOMMAND_H_ */
