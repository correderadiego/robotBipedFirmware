/*
 * CommandController.h
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_

#include <logic/controller/process/ProcessControllerControllerCommand.h>
#include <logic/controller/process/ProcessControllerGetterCommand.h>
#include <logic/controller/process/ProcessControllerInterface.h>
#include <logic/controller/process/ProcessControllerInterpreterCommand.h>
#include <logic/controller/process/ProcessControllerSetterCommand.h>

#define COMMAND_CONTROLLER_VECTOR_SIZE	 4
class ProcessController {
	public:
		ProcessController();
		ProcessControllerInterface::CommandControllerErrors process(Plen* plen, CommandInterface* command);

		ProcessControllerInterface* commandController[COMMAND_CONTROLLER_VECTOR_SIZE] = {
				new ProcessControllerControllerCommand(),
				new ProcessControllerInterpreterCommand(),
				new ProcessControllerSetterCommand(),
				new ProcessControllerGetterCommand()
		};
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_ */
