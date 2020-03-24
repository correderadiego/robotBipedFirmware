/*
 * Command.h
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_COMMAND_H_
#define SRC_BEAN_COMMANDS_COMMAND_H_

class Command {
public:
	#define ZERO_LENGHT 0
	#define HEADER_LENGTH  1
	#define COMMAND_LENGTH 2

	enum CommandType{
					  UNKNOWN_COMMAND_TYPE = -1,
					  CONTROLLER_COMMAND,
					  INTERPRETER_COMMAND,
					  SETTER_COMMAND,
					  GETTER_COMMAND
					};

	enum SubCommandType	{};

	enum CommandState{
						READY2,
						HEADER_INCOMING2 = 0,
						COMMAND_INCOMING2,
						ARGUMENTS_INCOMING2
					 };

	Command();
	Command					(CommandType commandType);
	void setCommandType		(CommandType commandType);
	void setSubCommandType	(SubCommandType subCommandType);
	int getCommandLength	();
	CommandState getCommandState();
	Command::CommandType getCommandType();
	virtual ~Command();

protected:
	CommandType commandType;
	int commandLength;
	CommandState commandState;
	SubCommandType subCommandType;
};

#endif /* SRC_BEAN_COMMANDS_COMMAND_H_ */
