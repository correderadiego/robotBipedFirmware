/*
 * PlayAMotion.h
 *
 *  Created on: 29 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_PLAYAMOTIONCOMMAND_H_
#define SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_PLAYAMOTIONCOMMAND_H_

#include <logic/bean/commands/controllerCommands/ControllerCommand.h>

class PlayAMotionCommand : public ControllerCommand{
public:
	PlayAMotionCommand();
	int getPosition();
	void setPosition(int position);
private:
	int position;
};

#endif /* SRC_BEAN_COMMANDS_CONTROLLERCOMMANDS_PLAYAMOTIONCOMMAND_H_ */
