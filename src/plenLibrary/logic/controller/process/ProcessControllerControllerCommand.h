/*
 * ProcessControllerControllerCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_

#include <plenLibrary/logic/bean/commands/controllerCommands/ApplyDiffValueCommand.h>
#include <plenLibrary/logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>
#include <plenLibrary/logic/bean/commands/controllerCommands/ControllerCommand.h>
#include <plenLibrary/logic/bean/commands/CommandInterface.h>
#include <plenLibrary/logic/bean/Plen.h>
#include <plenLibrary/logic/controller/process/ProcessControllerInterface.h>

class ProcessControllerControllerCommand : public ProcessControllerInterface {
public:
	ProcessControllerControllerCommand();
	bool match(CommandInterface command);
	CommandControllerErrors process(Plen* plen, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERCONTROLLERCOMMAND_H_ */
