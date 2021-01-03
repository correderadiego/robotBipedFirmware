/*
 * ParserControllerGetterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: Diego
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
#include "utils/ParserUtils.h"
#include "string.h"

#define GETTER_COMMAND_CHAR 	 							'<'
#define DUMP_JOINT_SETTING_COMMAND_LENGHT 					3
#define DUMP_MOTION_COMMAND_LENGHT							5
#define DUMP_VERSION_INFORMATION_COMMAND_LENGTH				3
#define DUMP_NETWORK_INFORMATION_COMMAND_LENGTH				3

#define HEADER_LENGTH			2
#define HEADER_INDEX_POSITION	1

#define SLOT_LENGTH				2
#define SLOT_POSITION     		HEADER_INDEX_POSITION + HEADER_LENGTH

class ParserControllerGetterCommand : public ParserInterface {
public:
	ParserControllerGetterCommand();
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseDumpJointSettingsCommand(
			Buffer* buffer, DumpJointSettingsCommand** command);
	ParserInterface::ParseErrors parseDumpMotionCommand(
			Buffer* buffer, DumpMotionCommand** command);
	ParserInterface::ParseErrors parseDumpVersionInformationCommand(
			Buffer* buffer, DumpVersionInformationCommand** command);
	ParserInterface::ParseErrors parseDumpNetworkInformationCommand(
				Buffer* buffer, DumpNetworkInformationCommand** command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_ */
