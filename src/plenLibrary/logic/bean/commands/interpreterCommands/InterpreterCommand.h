/*
 * InterpreterCommand.h
 *
 *  Created on: 24 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_
#define SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_

#include <logic/bean/commands/CommandInterface.h>

class InterpreterCommand  : public CommandInterface  {
public:
	#define PUSH_A_FUNCTION_CHAR	"PU"
	#define POP_A_FUNCTION_CHAR		"PO"
	#define RESET_INTERPRETER_CHAR	"RI"

	enum SubCommandType	{
							UNKNOWN_SUB_COMMAND_TYPE,
							PUSH_A_FUNCTION,
							POP_A_FUNCTION,
							RESET_INTERPRETER
						};
	InterpreterCommand();
	void setSubCommandType	(SubCommandType subCommandType);
	SubCommandType getSubCommandType();

protected:
	SubCommandType subCommandType;
};

#endif /* SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_ */
