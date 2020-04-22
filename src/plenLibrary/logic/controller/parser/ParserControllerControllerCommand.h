/*
 * ParserControllerCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_

#include <ArduinoIncludes.h>
#include <logic/bean/commands/controllerCommands/ApplyDiffValueCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyHomePositionCommand.h>
#include <logic/bean/commands/controllerCommands/ApplyNativeValueCommand.h>
#include <logic/bean/commands/controllerCommands/ControllerCommand.h>
#include <logic/bean/commands/controllerCommands/PlayAMotionCommand.h>
#include <logic/bean/commands/controllerCommands/StopAMotionCommand.h>
#include <logic/bean/hardware/Buffer.h>
#include <logic/controller/parser/ParserInterface.h>


#define CONTROLLER_COMMAND_CHAR  		'$'
#define APPLY_NATIVE_COMMAND_LENGTH 	8
#define APPLY_DIFF_COMMAND_LENGTH 		5
#define APPLY_HOME_POSITION_COMMAND_LENGTH 	3
#define PLAY_MOTION_COMMAND_LENGTH		2
#define STOP_MOTION_COMMAND_LENGTH 		3

class ParserControllerControllerCommand : public ParserInterface{
public:
	ParserControllerControllerCommand();
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseApplyNativeValueCommand(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseApplyDiffCommand(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parsePlayAMotionCommand(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseStopAMotionCommand(
			Buffer* buffer, CommandInterface** command);
	ParserInterface::ParseErrors parseApplyHomePositionCommand(
			Buffer* buffer, CommandInterface** command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_ */
