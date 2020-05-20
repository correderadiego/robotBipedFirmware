/*
 * SetMotionFrame.h
 *
 *  Created on: 3 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMOTIONFRAMECOMMAND_H_
#define SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMOTIONFRAMECOMMAND_H_

#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include "logic/bean/motion/Frame.h"

class SetMotionFrameCommand : public SetterCommand {
public:
	SetMotionFrameCommand();
	void setMotionFrame(Frame* frame);
	Frame* getMotionFrame();
	~SetMotionFrameCommand();
private:
	Frame* frame = new Frame();
};

#endif /* SRC_BEAN_COMMANDS_SETTERCOMMANDS_SETMOTIONFRAMECOMMAND_H_ */
