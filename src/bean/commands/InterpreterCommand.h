/*
 * InterpreterCommand.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_
#define SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_

#include <bean/commands/Command.h>

class InterpreterCommand  : public Command  {
public:
	#define PUSH_FUNCTION_CHAR		"PU"
	#define POP_FUNCTION_CHAR		"PO"
	#define RESET_INTERPRETER_CHAR	"RI"

	enum SubCommandType	{
							UNKNOWN_SUB_COMMAND_TYPE = -1,
							PUSH_FUNCTION_VALUE,
							POP_FUNCTION_VALUE,
							RESET_INTERPRETER

						};
	InterpreterCommand(CommandType commandType = INTERPRETER_COMMAND);
	void setSubCommandType	(SubCommandType subCommandType);
private:
	SubCommandType subCommandType;
};

#endif /* SRC_BEAN_COMMANDS_INTERPRETERCOMMAND_H_ */
