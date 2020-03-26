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
	enum CommandType{
						  UNKNOWN_COMMAND_TYPE = -1,
						  CONTROLLER_COMMAND,
						  INTERPRETER_COMMAND,
						  SETTER_COMMAND,
						  GETTER_COMMAND
						};
	virtual ~CommandInterface();
	virtual void setCommandType		(CommandType commandType);
	virtual int getCommandLength	();
	virtual CommandInterface::CommandType getCommandType();

	protected:
		CommandType commandType;
		int commandLength;
};

#endif /* SRC_BEAN_COMMANDS_COMMANDINTERFACE_H_ */
