/*
 * ParserControllerGetterCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/parser/ParserControllerGetterCommand.h>

ParserControllerGetterCommand::ParserControllerGetterCommand() {}

ParserControllerGetterCommand::ParserControllerGetterCommand(
		ParserInterface parserInterface){}

bool ParserControllerGetterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == GETTER_COMMAND_CHAR){
		Logger::getInstance()->log(Logger::DEBUG, "Getter command received");
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parse(
									Buffer* buffer, CommandInterface command){

	char commandSequence[3] = {'\0'};
	strncpy ( commandSequence, &buffer->getData()[1],  2);

	if( strcmp(commandSequence, DUMP_JOINT_SETTINGS_CHAR) == 0){
		return parseDumpJointSettingsCommand(buffer, command);
	}

	if( strcmp(commandSequence, DUMP_A_MOTION_CHAR) == 0){
		return parseDumpMotionCommand(buffer, command);
	}

	if( strcmp(commandSequence, DUMP_VERSION_INFORMATION_CHAR) == 0){
		return parseVersionInformationCommand(buffer, command);
	}

	if( strcmp(commandSequence, DUMP_NETWORK_INFORMATION_CHAR) == 0){
		return parseNetworkInformationCommand(buffer, command);
	}
	return ParserInterface::UNKNOWN_COMMAND_ERROR;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parseDumpJointSettingsCommand(
			Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != DUMP_JOINT_SETTING_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new DumpJointSettingsCommand());
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parseDumpMotionCommand(
	Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != DUMP_MOTION_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new DumpMotionCommand());
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parseVersionInformationCommand(
	Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != DUMP_VERSION_INFORMATION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new DumpVersionInformationCommand());
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parseNetworkInformationCommand(
	Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != DUMP_NETWORK_INFORMATION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new DumpNetworkInformationCommand());
	return NO_ERROR;
}
