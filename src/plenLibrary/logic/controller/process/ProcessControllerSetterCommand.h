/*
 * ProcessControllerSetterCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_

#include <plenLibrary/logic/bean/commands/CommandInterface.h>
#include <plenLibrary/logic/bean/commands/setterCommands/SetHomeValueCommand.h>
#include <plenLibrary/logic/bean/commands/setterCommands/SetMaxValueCommand.h>
#include <plenLibrary/logic/bean/commands/setterCommands/SetMinValueCommand.h>
#include <plenLibrary/logic/bean/commands/setterCommands/SetterCommand.h>
#include <plenLibrary/logic/bean/Plen.h>
#include <plenLibrary/logic/controller/process/ProcessControllerInterface.h>


class ProcessControllerSetterCommand : public ProcessControllerInterface{
public:
	ProcessControllerSetterCommand();
	bool match(CommandInterface command);
	CommandControllerErrors process(Plen* plen, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_ */
