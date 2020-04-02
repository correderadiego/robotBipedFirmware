/*
 * ParserControllerCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <controller/parser/ParserControllerControllerCommand.h>

ParserControllerControllerCommand::ParserControllerControllerCommand() {}

ParserControllerControllerCommand::ParserControllerControllerCommand(
		ParserInterface parserInterface){}

bool ParserControllerControllerCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == CONTROLLER_COMMAND_CHAR){
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parse(
											Buffer* buffer, CommandInterface command){
	char commandSequence[2] = {};
	strncpy ( commandSequence, &buffer->getData()[1], 2);

	if( strcmp(commandSequence, APPY_NATIVE_CHAR) == 0){
		return parseApplyNativeValueCommand(buffer, command);
	}

	if( strcmp(commandSequence, APPLY_DIFF_CHAR) == 0){
		return parseApplyDiffCommand(buffer, command);
	}

	if( strcmp(commandSequence, PLAY_A_MOTION_CHAR) == 0){
		return parsePlayAMotionCommand(buffer, command);
	}

	if( strcmp(commandSequence, STOP_A_MOTION_CHAR) == 0){
		return parseStopAMotionCommand(buffer, command);
	}

	if( strcmp(commandSequence, APPLY_HOME_POSITION_CHAR) == 0){
		return parseApplyHomePositionCommand(buffer, command);
	}

	return ParserControllerControllerCommand::UNKNOWN_COMMAND_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parseApplyNativeValueCommand(
		Buffer* buffer, ControllerCommand command){
	if(buffer->getLenght() != APPLY_NATIVE_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new ApplyNativeValueCommand());
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parseApplyDiffCommand(
		Buffer* buffer, ControllerCommand command){
	if(buffer->getLenght() != APPLY_DIFF_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new ApplyDiffValueCommand());
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parsePlayAMotionCommand(
		Buffer* buffer, ControllerCommand command){
	if(buffer->getLenght() != HOME_POSITION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new PlayAMotionCommand());
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parseStopAMotionCommand(
		Buffer* buffer, ControllerCommand command){
	if(buffer->getLenght() != PLAY_MOTION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new StopAMotionCommand());
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parseApplyHomePositionCommand(
		Buffer* buffer, ControllerCommand command){
	if(buffer->getLenght() != STOP_MOTION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new ApplyHomePositionCommand());
	return NO_ERROR;
}
