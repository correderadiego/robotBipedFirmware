/*
 * ParserControllerSetterCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <controller/parser/ParserControllerSetterCommand.h>

ParserControllerSetterCommand::ParserControllerSetterCommand() {}

ParserControllerSetterCommand::ParserControllerSetterCommand(
		ParserInterface parserInterface) {}

ParserControllerSetterCommand::~ParserControllerSetterCommand() {}

bool ParserControllerSetterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == SETTER_COMMAND_CHAR){
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parse(
		Buffer* buffer, SetterCommand command){

	char commandSequence[2] = {};
	strncpy ( commandSequence, &buffer->getData()[1], 2);

	if( strcmp(commandSequence, SET_MOTION_HEADER_CHAR) == 0){
		((SetterCommand)command).setSubCommandType(SetterCommand::SET_MOTION_HEADER);
		return ParserInterface::NO_ERROR;
	}

	if( strcmp(commandSequence, SET_MOTION_FRAME_CHAR) == 0){
		((SetterCommand)command).setSubCommandType(SetterCommand::SET_MOTION_FRAME);
		return ParserInterface::NO_ERROR;
	}

	if( strcmp(commandSequence, RESET_JOINT_SETTINGS_CHAR) == 0){
		((SetterCommand)command).setSubCommandType(SetterCommand::RESET_JOINT_SETTINGS);
		return ParserInterface::NO_ERROR;
	}

	if( strcmp(commandSequence, SET_HOME_VALUE_CHAR) == 0){
		((SetterCommand)command).setSubCommandType(SetterCommand::SET_HOME_VALUE);
		return ParserInterface::NO_ERROR;
	}

	if( strcmp(commandSequence, SET_MAX_VALUE_CHAR) == 0){
		((SetterCommand)command).setSubCommandType(SetterCommand::SET_MAX_VALUE);
		return ParserInterface::NO_ERROR;
	}

	if( strcmp(commandSequence, SET_MIN_VALUE_CHAR) == 0){
		((SetterCommand)command).setSubCommandType(SetterCommand::SET_MIN_VALUE);
		return ParserInterface::NO_ERROR;
	}

	((SetterCommand)command).setSubCommandType(SetterCommand::UNKNOWN_SUB_COMMAND_TYPE);
	return ParserInterface::UNKNOWN_COMMAND;
}
