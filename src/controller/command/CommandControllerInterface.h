/*
 * CommandControllerInterface.h
 *
 *  Created on: 28 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_COMMAND_COMMANDCONTROLLERINTERFACE_H_
#define SRC_CONTROLLER_COMMAND_COMMANDCONTROLLERINTERFACE_H_

#include "bean/commands/CommandInterface.h"

class CommandControllerInterface {
public:
	enum CommandControllerErrors{
	  UNKNOWN_COMMAND,
	  NO_ERROR 			 =  0
	};

    virtual bool match(CommandInterface command);
    virtual CommandControllerErrors process(CommandInterface command);
    virtual ~CommandControllerInterface();
};



#endif /* SRC_CONTROLLER_COMMAND_COMMANDCONTROLLERINTERFACE_H_ */
