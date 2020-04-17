/*
 * CommandInterface.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_COMMANDS_COMMANDINTERFACE_H_
#define SRC_BEAN_COMMANDS_COMMANDINTERFACE_H_

class CommandInterface {
	public:
	enum CommandTypeEnum{
						  UNKNOWN_COMMAND_TYPE,
						  CONTROLLER_COMMAND,
						  INTERPRETER_COMMAND,
						  SETTER_COMMAND,
						  GETTER_COMMAND
						};
	CommandInterface(CommandTypeEnum commandType = UNKNOWN_COMMAND_TYPE);
	void setCommandType		(CommandTypeEnum commandType);
	CommandInterface::CommandTypeEnum getCommandType();
	int getCommandLength	();
	void setCommandLength(int commandLength);

	protected:
		CommandTypeEnum commandType;
		int commandLength;
};

#endif /* SRC_BEAN_COMMANDS_COMMANDINTERFACE_H_ */
