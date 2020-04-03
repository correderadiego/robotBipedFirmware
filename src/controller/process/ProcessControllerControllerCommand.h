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
#include "bean/commands/controllerCommands/ControllerCommand.h"
#include "bean/commands/controllerCommands/ApplyNativeValueCommand.h"
#include "bean/commands/controllerCommands/ApplyDiffValueCommand.h"
#include "bean/Plen.h"

class ProcessControllerControllerCommand : public ProcessControllerInterface {
public:
	ProcessControllerControllerCommand();
	bool match(CommandInterface command);
	CommandControllerErrors process(Plen* plen, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_ */
