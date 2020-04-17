/*
 * ProcessControllerSetterCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_

#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/commands/setterCommands/SetHomeValueCommand.h>
#include <logic/bean/commands/setterCommands/SetMaxValueCommand.h>
#include <logic/bean/commands/setterCommands/SetMinValueCommand.h>
#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include <logic/bean/Plen.h>
#include <logic/controller/process/ProcessControllerInterface.h>


class ProcessControllerSetterCommand : public ProcessControllerInterface{
public:
	ProcessControllerSetterCommand();
	bool match(CommandInterface command);
	CommandControllerErrors process(Plen* plen, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_ */
