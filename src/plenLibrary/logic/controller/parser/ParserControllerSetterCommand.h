/*
 * ParserControllerSetterCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_

#include <ArduinoIncludes.h>
#include <logic/bean/commands/setterCommands/SetterCommand.h>
#include <logic/bean/commands/setterCommands/ResetJointSettingsCommand.h>
#include <logic/bean/commands/setterCommands/SetAngleHomeValueCommand.h>
#include <logic/bean/commands/setterCommands/SetAngleMaxValueCommand.h>
#include <logic/bean/commands/setterCommands/SetMinValueCommand.h>
#include "logic/bean/commands/setterCommands/SetMotionFrameCommand.h"
#include "logic/bean/commands/setterCommands/SetMotionHeaderCommand.h"
#include <logic/bean/hardware/Buffer.h>
#include <logic/controller/parser/ParserInterface.h>
#include "string.h"
#include "utils/ParserUtils.h"

#define SETTER_COMMAND_CHAR 	 '>'
#define SET_MOTION_HEADER_COMMAND_LENGHT 	38
#define SET_MOTION_FRAME_COMMAND_LENGHT 	107
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

#define SLOT_LENGTH					2
#define SLOT_POSITION				HEADER_INDEX_POSITION + HEADER_LENGTH
#define FRAME_INDEX_LENGTH			2
#define FRAME_INDEX_POSITION		SLOT_POSITION + SLOT_LENGTH
#define TRANSITION_TIME_LENGTH		4
#define TRANSITION_TIME_POSITION	FRAME_INDEX_POSITION + FRAME_INDEX_LENGTH
#define JOINT_VALUE_LENGTH			4
#define JOINT_VALUE_POSITION		TRANSITION_TIME_POSITION + TRANSITION_TIME_LENGTH

#define NAME_LENGTH					20
#define NAME_POSITION				SLOT_POSITION + SLOT_LENGTH
#define USE_LOOP_LENGTH				1
#define USE_LOOP_POSITION			NAME_POSITION + NAME_LENGTH
#define LOOP_BEGIN_LENGTH			2
#define LOOP_BEGIN_POSITION			USE_LOOP_POSITION + USE_LOOP_LENGTH
#define LOOP_END_LENGTH				2
#define LOOP_END_POSITION			LOOP_BEGIN_POSITION + LOOP_BEGIN_LENGTH
#define LOOP_COUNT_LENGTH			2
#define LOOP_COUNT_POSITION_SETTER_COMMAND			LOOP_END_POSITION + LOOP_END_LENGTH
#define USE_JUMP_LENGTH				1
#define USE_JUMP_POSITION			LOOP_COUNT_LENGTH + LOOP_COUNT_POSITION_SETTER_COMMAND
#define JUMP_SLOT_LENGTH			2
#define JUMP_SLOT_POSITION			USE_JUMP_LENGTH + USE_JUMP_POSITION
#define USE_EXTRA_LENGTH			1
#define USE_EXTRA_POSITION			JUMP_SLOT_LENGTH + JUMP_SLOT_POSITION
#define FRAME_LENGTH_LENGTH			2
#define FRAME_LENGTH_POSITION		USE_EXTRA_LENGTH + USE_EXTRA_POSITION

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
	ParserInterface::ParseErrors parseSetMotionFrameCommand(
			Buffer* buffer, SetMotionFrameCommand** command);
	ParserInterface::ParseErrors parseSetMotionHeaderCommand(
			Buffer* buffer, SetMotionHeaderCommand** command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERSETTERCOMMAND_H_ */
