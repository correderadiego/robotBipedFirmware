/*
 * ProccessControllerGetterCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMAND_H_

#include "ProcessControllerInterface.h"
#include "bean/commands/CommandInterface.h"
#include "bean/commands/getterCommands/GetterCommand.h"
#include "bean/commands/getterCommands/DumpJointSettingsCommand.h"
#include "bean/commands/getterCommands/DumpMotionCommand.h"

class ProcessControllerGetterCommand : public ProcessControllerInterface {
public:
	ProcessControllerGetterCommand();
	bool match(CommandInterface command);
	CommandControllerErrors process(Plen* plen, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMAND_H_ */
