/*
 * ParserControllerGetterCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/parser/ParserControllerGetterCommand.h>

ParserControllerGetterCommand::ParserControllerGetterCommand() {}

bool ParserControllerGetterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == GETTER_COMMAND_CHAR){
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parse(
									Buffer* buffer, CommandInterface** command){

	char commandSequence[HEADER_LENGTH+1] = {'\0'};
	strncpy ( commandSequence, &buffer->getData()[HEADER_INDEX_POSITION], HEADER_LENGTH);
	*command = new GetterCommand();

	if( strcmp(commandSequence, DUMP_JOINT_SETTINGS_CHAR) == 0){
		return parseDumpJointSettingsCommand(buffer, (DumpJointSettingsCommand**)command);
	}

	if( strcmp(commandSequence, DUMP_A_MOTION_CHAR) == 0){
		return parseDumpMotionCommand(buffer, (DumpMotionCommand**)command);
	}

	if( strcmp(commandSequence, DUMP_VERSION_INFORMATION_CHAR) == 0){
		return parseDumpVersionInformationCommand(buffer, (DumpVersionInformationCommand**)command);
	}

	if( strcmp(commandSequence, DUMP_NETWORK_INFORMATION_CHAR) == 0){
		return parseDumpNetworkInformationCommand(buffer, (DumpNetworkInformationCommand**)command);
	}

	delete *command;
	return ParserInterface::UNKNOWN_COMMAND_ERROR;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parseDumpJointSettingsCommand(
			Buffer* buffer, DumpJointSettingsCommand** command){
	(**command).setSubCommandType(GetterCommand::DUMP_JOINT_SETTINGS);
	if(buffer->getLenght() != DUMP_JOINT_SETTING_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parseDumpMotionCommand(
	Buffer* buffer, DumpMotionCommand** command){
	(**command).setSubCommandType(GetterCommand::DUMP_A_MOTION);
	if(buffer->getLenght() != DUMP_MOTION_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	char slot[SLOT_LENGTH+1] = {'\0'};
	strncpy ( slot, &buffer->getData()[SLOT_POSITION],  SLOT_LENGTH);
	(**command).setSlot(ParserUtils::hexbytes2int(slot, SLOT_LENGTH));

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parseDumpVersionInformationCommand(
	Buffer* buffer, DumpVersionInformationCommand** command){
	(**command).setSubCommandType(GetterCommand::DUMP_VERSION_INFORMATION);
	if(buffer->getLenght() != DUMP_VERSION_INFORMATION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerGetterCommand::parseDumpNetworkInformationCommand(
	Buffer* buffer, DumpNetworkInformationCommand** command){
	(**command).setSubCommandType(GetterCommand::DUMP_NETWORK_INFORMATION);
	if(buffer->getLenght() != DUMP_NETWORK_INFORMATION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	return NO_ERROR;
}
