/*
 * ProccessControllerGetterCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMAND_H_

#include <Configuration.h>
#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/commands/getterCommands/DumpJointSettingsCommand.h>
#include <logic/bean/commands/getterCommands/DumpMotionCommand.h>
#include <logic/bean/commands/getterCommands/GetterCommand.h>
#include <logic/controller/process/ProcessControllerInterface.h>
#include "logic/controller/JointController.h"

class ProcessControllerGetterCommand : public ProcessControllerInterface {
public:
	ProcessControllerGetterCommand(JointController* jointController);
	bool match(CommandInterface* command);
	CommandControllerErrors process(Plen* plen, CommandInterface* command);

private:
	JointController* jointController;
	void processDumpNetworkInformation(Plen* plen);
	void processDumpVersionInformation();
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMAND_H_ */
