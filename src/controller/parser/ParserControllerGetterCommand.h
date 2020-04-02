/*
 * ParserControllerGetterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_

#include <bean/commands/getterCommands/DumpJointSettingsCommand.h>
#include <bean/commands/getterCommands/DumpVersionInformationCommand.h>
#include "ParserInterface.h"
#include "bean/Buffer.h"
#include "bean/commands/getterCommands/GetterCommand.h"
#include "bean/commands/getterCommands/DumpMotionCommand.h"
#include "string.h"

#define GETTER_COMMAND_CHAR 	 							'<'
#define DUMP_JOINT_SETTING_COMMAND_LENGHT 					0
#define DUMP_MOTION_COMMAND_LENGHT							2
#define DUMP_MOTION_VERSION_INFORMATION_COMMAND_LENGTH		0

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
	ParserInterface::ParseErrors parseDumpMotionVersionInformationCommand(
			Buffer* buffer, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERGETTERCOMMAND_H_ */
