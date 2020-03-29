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

	//((ControllerCommand)command);
//	char commandSequence[2] = {};
//	strncpy ( commandSequence, &buffer->getData()[1], 2);
//
//	if( strcmp(commandSequence, APPY_NATIVE_CHAR) == 0){
//		((ControllerCommand)command).setSubCommandType(ControllerCommand::APPY_NATIVE_VALUE);
//		return ParserControllerControllerCommand::NO_ERROR;
//	}
//
//	if( strcmp(commandSequence, APPLY_DIFF_CHAR) == 0){
//		((ControllerCommand)command).setSubCommandType(ControllerCommand::APPLY_DIFF_VALUE);
//		return ParserControllerControllerCommand::NO_ERROR;
//	}
//
//	if( strcmp(commandSequence, PLAY_A_MOTION_CHAR) == 0){
//		((ControllerCommand)command).setSubCommandType(ControllerCommand::PLAY_A_MOTION);
//		return ParserControllerControllerCommand::NO_ERROR;
//	}
//
//	if( strcmp(commandSequence, STOP_A_MOTION_CHAR) == 0){
//		((ControllerCommand)command).setSubCommandType(ControllerCommand::STOP_A_MOTION);
//		return ParserControllerControllerCommand::NO_ERROR;
//	}
//
//	if( strcmp(commandSequence, APPLY_HOME_POSITION_CHAR) == 0){
//		((ControllerCommand)command).setSubCommandType(ControllerCommand::APPLY_HOME_POSITION);
//		return ParserControllerControllerCommand::NO_ERROR;
//	}
//
//	((ControllerCommand)command).setSubCommandType(ControllerCommand::UNKNOWN_SUB_COMMAND_TYPE);
	return ParserControllerControllerCommand::UNKNOWN_COMMAND;
}

