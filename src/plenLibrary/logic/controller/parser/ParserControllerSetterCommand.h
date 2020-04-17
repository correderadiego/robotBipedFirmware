/*
 * ParserControllerSetterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_

#include <ArduinoIncludes.h>
#include <logic/bean/commands/setterCommands/ResetJointSettingsCommand.h>
#include <logic/bean/commands/setterCommands/SetHomeValueCommand.h>
#include <logic/bean/commands/setterCommands/SetMaxValueCommand.h>
#include <logic/bean/commands/setterCommands/SetMinValueCommand.h>
#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include <logic/bean/hardware/Buffer.h>
#include <logic/controller/parser/ParserInterface.h>
#include "string.h"

#define SETTER_COMMAND_CHAR 	 '>'
#define SET_MOTION_HEADER_COMMAND_LENGHT 	30
#define SET_MOTION_FRAME_COMMAND_LENGHT 	104
#define RESET_JOINT_SETTINGS_COMMAND_LENGHT 0
#define SET_HOME_COMMAND_LENGTH 			5
#define SET_MAX_VALUE_COMMAND_LENGHT 		5
#define SET_MIN_VALUE_COMMAND_LENGHT 		5

class ParserControllerSetterCommand : public ParserInterface  {
public:
	ParserControllerSetterCommand();
	ParserControllerSetterCommand(ParserInterface parserInterface);
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseSetMotionHeaderCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseSetMotionFrameCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseResetJointSettingsCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseSetHomeCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseSetMaxValueCommand(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseSetMinValueCommand(
			Buffer* buffer, CommandInterface command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_ */
