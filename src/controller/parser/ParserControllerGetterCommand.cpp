/*
 * ParserControllerGetterCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <controller/parser/ParserControllerGetterCommand.h>

ParserControllerGetterCommand::ParserControllerGetterCommand() {}

ParserControllerGetterCommand::ParserControllerGetterCommand(
		ParserInterface parserInterface){}

bool ParserControllerGetterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == GETTER_COMMAND_CHAR){
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parse(
									Buffer* buffer, CommandInterface command){

//	char commandSequence[2] = {};
//	strncpy ( commandSequence, &buffer->getData()[1], 2);
//
//	if( strcmp(commandSequence, DUMP_JOINT_SETTINGS_CHAR) == 0){
//		((GetterCommand)command).setSubCommandType(GetterCommand::DUMP_JOINT_SETTINGS);
//		return ParserInterface::NO_ERROR;
//	}
//
//	if( strcmp(commandSequence, DUMP_A_MOTION_CHAR) == 0){
//		((GetterCommand)command).setSubCommandType(GetterCommand::DUMP_A_MOTION);
//		return ParserInterface::NO_ERROR;
//	}
//
//	if( strcmp(commandSequence, DUMP_VERSION_INFORMATION_CHAR) == 0){
//		((GetterCommand)command).setSubCommandType(GetterCommand::DUMP_VERSION_INFORMATION);
//		return ParserInterface::NO_ERROR;
//	}
//
//	((GetterCommand)command).setSubCommandType(GetterCommand::UNKNOWN_SUB_COMMAND_TYPE);
	return ParserInterface::UNKNOWN_COMMAND_ERROR;
}
