/*
 * ParserControllerCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: Diego
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_

#include <ArduinoIncludes.h>
#include <logic/bean/commands/controllerCommands/ApplyDiffValueCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyHomePositionCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyJointPositionCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>
#include <logic/bean/commands/controllerCommands/ControllerCommand.h>
#include <logic/bean/commands/controllerCommands/PlayAMotionCommand.h>
#include <logic/bean/commands/controllerCommands/StopAMotionCommand.h>
#include <logic/bean/hardware/Buffer.h>
#include "utils/ParserUtils.h"
#include <logic/controller/parser/ParserInterface.h>

#define CONTROLLER_COMMAND_CHAR  	   			'$'
#define APPLY_NATIVE_COMMAND_LENGTH 			8
#define APPLY_DIFF_COMMAND_LENGTH 				8
#define PLAY_MOTION_COMMAND_LENGTH				5
#define APPLY_HOME_POSITION_COMMAND_LENGTH 		3
#define STOP_MOTION_COMMAND_LENGTH 				3
#define APPLY_JOINT_POSITION_COMMAND_LENGTH 	3

#define HEADER_LENGTH			2
#define HEADER_INDEX_POSITION	1

#define DEVICE_ID_LENGTH		2
#define DEVICE_ID_POSITION      HEADER_INDEX_POSITION + HEADER_LENGTH

#define VALUE_LENGHT			3
#define VALUE_POSITION			DEVICE_ID_POSITION + DEVICE_ID_LENGTH

#define SLOT_LENGTH				2
#define SLOT_POSITION     		HEADER_INDEX_POSITION + HEADER_LENGTH

class ParserControllerControllerCommand : public ParserInterface{
public:
	ParserControllerControllerCommand();
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseApplyNativeValueCommand(
			Buffer* buffer, ApplyNativeValueCommand** command);
	ParserInterface::ParseErrors parseApplyDiffValueCommand(
			Buffer* buffer, ApplyDiffValueCommand** command);
	ParserInterface::ParseErrors parsePlayAMotionCommand(
			Buffer* buffer, PlayAMotionCommand** command);
	ParserInterface::ParseErrors parseStopAMotionCommand(
			Buffer* buffer, StopAMotionCommand** command);
	ParserInterface::ParseErrors parseApplyHomePositionCommand(
			Buffer* buffer, ApplyHomePositionCommand** command);
	ParserInterface::ParseErrors parseApplyJointPositionCommand(
			Buffer* buffer, ApplyJointPositionCommand** command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_ */
