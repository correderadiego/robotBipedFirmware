/*
 * ParserControllerGetterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_

#include <logic/bean/commands/getterCommands/DumpJointSettingsCommand.h>
#include <logic/bean/commands/getterCommands/DumpMotionCommand.h>
#include <logic/bean/commands/getterCommands/DumpVersionInformationCommand.h>
#include <logic/bean/commands/getterCommands/DumpNetworkInformationCommand.h>
#include <logic/bean/commands/getterCommands/GetterCommand.h>
#include <logic/bean/hardware/Buffer.h>
#include <logic/controller/parser/ParserInterface.h>
#include "string.h"

#define GETTER_COMMAND_CHAR 	 							'<'
#define DUMP_JOINT_SETTING_COMMAND_LENGHT 					0
#define DUMP_MOTION_COMMAND_LENGHT							2
#define DUMP_VERSION_INFORMATION_COMMAND_LENGTH				3
#define DUMP_NETWORK_INFORMATION_COMMAND_LENGTH				3

class ParserControllerGetterCommand : public ParserInterface {
public:
	ParserControllerGetterCommand();
	ParserControllerGetterCommand(ParserInterface parserInterface);
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseDumpJointSettingsCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseDumpMotionCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseVersionInformationCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseNetworkInformationCommand(
				Buffer* buffer, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_ */
