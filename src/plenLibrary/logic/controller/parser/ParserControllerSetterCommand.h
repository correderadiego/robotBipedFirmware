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
#include <logic/bean/commands/setterCommands/SetAngleHomeValueCommand.h>
#include <logic/bean/commands/setterCommands/SetAngleMaxValueCommand.h>
#include <logic/bean/commands/setterCommands/SetMinValueCommand.h>
#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include <logic/bean/hardware/Buffer.h>
#include <logic/controller/parser/ParserInterface.h>
#include "string.h"
#include "utils/ParserUtils.h"

#define SETTER_COMMAND_CHAR 	 '>'
#define SET_MOTION_HEADER_COMMAND_LENGHT 	30
#define SET_MOTION_FRAME_COMMAND_LENGHT 	104
#define RESET_JOINT_SETTINGS_COMMAND_LENGHT 3
#define SET_HOME_VALUE_COMMAND_LENGTH 		8
#define SET_MAX_VALUE_COMMAND_LENGHT 		8
#define SET_MIN_VALUE_COMMAND_LENGHT 		8

#define HEADER_LENGTH			2
#define HEADER_INDEX_POSITION	1

#define DEVICE_ID_LENGTH		2
#define DEVICE_ID_POSITION      HEADER_INDEX_POSITION + HEADER_LENGTH

#define VALUE_LENGHT			3
#define VALUE_POSITION			DEVICE_ID_POSITION + DEVICE_ID_LENGTH


class ParserControllerSetterCommand : public ParserInterface  {
public:
	ParserControllerSetterCommand();
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseSetMotionHeaderCommand(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseSetMotionFrameCommand(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseResetJointSettingsCommand(
			Buffer* buffer, ResetJointSettingsCommand** command);
	ParserInterface::ParseErrors parseSetHomeValueCommand(
			Buffer* buffer, SetAngleHomeValueCommand** command);
	ParserInterface::ParseErrors parseSetMaxValueCommand(
			Buffer* buffer, SetAngleMaxValueCommand** command);
	ParserInterface::ParseErrors parseSetMinValueCommand(
			Buffer* buffer, SetMinValueCommand** command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_ */
