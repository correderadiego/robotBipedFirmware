/*
 * ProcessControllerInterpreterCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERPRETERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERPRETERCOMMAND_H_

#include <logic/bean/commands/CommandInterface.h>
#include "logic/bean/commands/interpreterCommands/InterpreterCommand.h"
#include <logic/controller/process/ProcessControllerInterface.h>

class ProcessControllerInterpreterCommand : public ProcessControllerInterface {
public:
	ProcessControllerInterpreterCommand();
	bool match(CommandInterface* command);
	CommandControllerErrors process(Plen* plen, CommandInterface* command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERPRETERCOMMAND_H_ */
