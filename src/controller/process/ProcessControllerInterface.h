/*
 * CommandControllerInterface.h
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERFACE_H_
#define SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERFACE_H_

#include "bean/commands/CommandInterface.h"
#include "bean/Plen.h"

class ProcessControllerInterface {
public:
	enum CommandControllerErrors{
	  UNKNOWN_COMMAND,
	  NO_ERROR 			 =  0
	};

    virtual bool match(CommandInterface command);
    virtual CommandControllerErrors process(Plen* plen, CommandInterface command);
};



#endif /* SRC_CONTROLLER_PROCESS_PROCESSCONTROLLERINTERFACE_H_ */
