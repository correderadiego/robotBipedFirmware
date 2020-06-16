/*
 * ProcessControllerControllerCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_

#include <logic/bean/commands/controllerCommands/ApplyDiffValueCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>
#include <logic/bean/commands/controllerCommands/PlayAMotionCommand.h>
#include <logic/bean/commands/controllerCommands/StopAMotionCommand.h>
#include <logic/bean/commands/controllerCommands/ControllerCommand.h>
#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/Plen.h>
#include <logic/controller/process/ProcessControllerInterface.h>
#include "logic/controller/MotionController.h"

class ProcessControllerControllerCommand : public ProcessControllerInterface {
public:
	ProcessControllerControllerCommand(MotionController* motionController);
	bool match(CommandInterface* command);
	CommandControllerErrors process(Plen* plen, CommandInterface* command);
private:
	MotionController* motionController;
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_ */
