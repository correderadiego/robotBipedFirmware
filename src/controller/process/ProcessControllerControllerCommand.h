/*
 * ProcessControllerControllerCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_

#include "ProcessControllerInterface.h"
#include "bean/commands/CommandInterface.h"

class ProcessControllerControllerCommand : public ProcessControllerInterface {
public:
	ProcessControllerControllerCommand();
	bool match(CommandInterface command);
	CommandControllerErrors process(CommandInterface command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_ */
