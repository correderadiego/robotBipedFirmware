/*
 * PlayAMotion.h
 *
 *  Created on: 29 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_PLAYAMOTIONCOMMAND_H_
#define SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_PLAYAMOTIONCOMMAND_H_

#include "ControllerCommand.h"

class PlayAMotionCommand  : public ControllerCommand{
public:
	PlayAMotionCommand();
	int getSlot();
	void setSlot(int slot);
private:
	int slot;
};

#endif /* SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_PLAYAMOTIONCOMMAND_H_ */
