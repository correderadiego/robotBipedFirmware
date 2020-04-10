/*
 * InterpreterCommand.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_
#define SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_

#include <plenLibrary/logic/bean/commands/CommandInterface.h>

class InterpreterCommand  : public CommandInterface  {
public:
	#define PUSH_FUNCTION_CHAR		"PU"
	#define POP_FUNCTION_CHAR		"PO"
	#define RESET_INTERPRETER_CHAR	"RI"

	enum SubCommandType	{
							UNKNOWN_SUB_COMMAND_TYPE = -1,
							PUSH_A_FUNCTION,
							POP_A_FUNCTION,
							RESET_INTERPRETER
						};
	InterpreterCommand(CommandInterface command);
	InterpreterCommand();
	void setSubCommandType	(SubCommandType subCommandType);
	SubCommandType getSubCommandType();

protected:
	SubCommandType subCommandType;
};

#endif /* SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_ */
