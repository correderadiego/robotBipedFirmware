/*
 * CommandControllerInterface.h
 *
 *  Created on: 28 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERFACE_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERFACE_H_

#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/Plen.h>

class ProcessControllerInterface {
public:
	enum CommandControllerErrors{
	  INVALID_VALUE,
	  UNKNOWN_COMMAND,
	  NO_ERROR
	};

    virtual bool match(CommandInterface* command) = 0;
    virtual CommandControllerErrors process(Plen* plen, CommandInterface* command) = 0;
    virtual ~ProcessControllerInterface() = 0;
};

inline ProcessControllerInterface::~ProcessControllerInterface() {}

#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERFACE_H_ */
