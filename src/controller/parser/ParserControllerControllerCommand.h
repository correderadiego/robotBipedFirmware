/*
 * ParserControllerCommand.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_
#define SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_

#include "ParserInterface.h"
#include "bean/Buffer.h"
#include "bean/commands/controllerCommands/ControllerCommand.h"
#include "bean/commands/controllerCommands/ApplyNativeValueCommand.h"
#include "bean/commands/controllerCommands/ApplyDiffValueCommand.h"
#include "bean/commands/controllerCommands/PlayAMotionCommand.h"
#include "bean/commands/controllerCommands/StopAMotionCommand.h"
#include "bean/commands/controllerCommands/ApplyHomePositionCommand.h"
#include "string.h"

#define CONTROLLER_COMMAND_CHAR  		'$'
#define APPLY_NATIVE_COMMAND_LENGTH 	5
#define APPLY_DIFF_COMMAND_LENGTH 		5
#define HOME_POSITION_COMMAND_LENGTH 	0
#define PLAY_MOTION_COMMAND_LENGTH		2
#define STOP_MOTION_COMMAND_LENGTH 		0

class ParserControllerControllerCommand : public ParserInterface{
public:
	ParserControllerControllerCommand();
	ParserControllerControllerCommand(ParserInterface parserInterface);
	bool match(Buffer* buffer);
	ParserInterface::ParseErrors parse(
			Buffer* buffer, CommandInterface command);
	ParserInterface::ParseErrors parseApplyNativeValueCommand(
			Buffer* buffer, ControllerCommand command);
	ParserInterface::ParseErrors parseApplyDiffCommand(
			Buffer* buffer, ControllerCommand command);
	ParserInterface::ParseErrors parsePlayAMotionCommand(
			Buffer* buffer, ControllerCommand command);
	ParserInterface::ParseErrors parseStopAMotionCommand(
			Buffer* buffer, ControllerCommand command);
	ParserInterface::ParseErrors parseApplyHomePositionCommand(
			Buffer* buffer, ControllerCommand command);
};

#endif /* SRC_CONTROLLER_PARSER_PARSERCONTROLLERCONTROLLERCOMMAND_H_ */
