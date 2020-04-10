/*
 * CommandController.h
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_

#include <plenLibrary/logic/bean/Plen.h>
#include <plenLibrary/logic/controller/process/ProcessControllerControllerCommand.h>
#include <plenLibrary/logic/controller/process/ProcessControllerGetterCommand.h>
#include <plenLibrary/logic/controller/process/ProcessControllerInterface.h>
#include <plenLibrary/logic/controller/process/ProcessControllerInterpreterCommand.h>
#include <plenLibrary/logic/controller/process/ProcessControllerSetterCommand.h>


class ProcessController {
public:
	#define COMMAND_CONTROLLER_VECTOR_SIZE	 4
	ProcessController();
	ProcessControllerInterface::CommandControllerErrors process(Plen* plen, CommandInterface command);

	ProcessControllerInterface* commandController[COMMAND_CONTROLLER_VECTOR_SIZE] = {
			new ProcessControllerControllerCommand(),
			new ProcessControllerInterpreterCommand(),
			new ProcessControllerSetterCommand(),
			new ProcessControllerGetterCommand()
	};
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_ */
