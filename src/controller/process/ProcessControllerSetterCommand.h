/*
 * ProcessControllerSetterCommand.h
 *
 *  Created on: 1 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_

#include "ProcessControllerInterface.h"
#include "bean/Plen.h"
#include "bean/commands/CommandInterface.h"
#include "bean/commands/setterCommands/SetterCommand.h"
#include "bean/commands/setterCommands/SetMaxValueCommand.h"
#include "bean/commands/setterCommands/SetMinValueCommand.h"
#include "bean/commands/setterCommands/SetHomeValueCommand.h"


class ProcessControllerSetterCommand : public ProcessControllerInterface{
public:
	ProcessControllerSetterCommand();
	bool match(CommandInterface command);
	CommandControllerErrors process(Plen* plen, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERSETTERCOMMAND_H_ */
