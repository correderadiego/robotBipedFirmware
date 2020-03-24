/*
 * InterpreterCommand.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include <bean/commands/InterpreterCommand.h>

InterpreterCommand::InterpreterCommand(CommandType commandType) {
	this->commandType 		= commandType;
	this->commandState 		= COMMAND_INCOMING2;
	this->commandLength 	= COMMAND_LENGTH;
	this->subCommandType 	= UNKNOWN_SUB_COMMAND_TYPE;
}
