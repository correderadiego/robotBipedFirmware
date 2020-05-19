/*
 * ProcessControllerSetterCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_

#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include <logic/bean/commands/setterCommands/SetAngleHomeValueCommand.h>
#include <logic/bean/commands/setterCommands/SetAngleMaxValueCommand.h>
#include <logic/bean/commands/setterCommands/SetMinValueCommand.h>
#include <logic/bean/commands/setterCommands/SetMotionFrameCommand.h>
#include <logic/bean/commands/setterCommands/SetMotionHeaderCommand.h>
#include <logic/bean/Plen.h>
#include <logic/controller/process/ProcessControllerInterface.h>
#include "hardware/controller/ExternalFileSystemController.h"
#include "logic/controller/JointController.h"
#include "logic/controller/MotionController.h"


class ProcessControllerSetterCommand : public ProcessControllerInterface{
public:
	ProcessControllerSetterCommand(
			JointController* jointController,
			MotionController* motionController);
	bool match(CommandInterface* command);
	CommandControllerErrors process(Plen* plen, CommandInterface* command);
private:
	JointController* jointController;
	MotionController* motionController;
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_ */
