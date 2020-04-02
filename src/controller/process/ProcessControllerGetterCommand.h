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

class ProcessControllerGetterCommand : public ProcessControllerInterface {
public:
	ProcessControllerGetterCommand();
	bool match(CommandInterface command);
	CommandControllerErrors process(CommandInterface command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERGETTERCOMMAND_H_ */
