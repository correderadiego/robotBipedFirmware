/*
 * CommandController.h
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLER_H_

#include "bean/Plen.h"
#include <controller/process/ProcessControllerInterface.h>
#include "ProcessControllerControllerCommand.h"
#include "ProcessControllerInterpreterCommand.h"
#include "ProcessControllerSetterCommand.h"
#include "ProcessControllerGetterCommand.h"


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
