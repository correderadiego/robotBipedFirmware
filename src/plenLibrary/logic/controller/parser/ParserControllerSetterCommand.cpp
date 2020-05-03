/*
 * ParserControllerSetterCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/parser/ParserControllerSetterCommand.h>

ParserControllerSetterCommand::ParserControllerSetterCommand() {}

bool ParserControllerSetterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == SETTER_COMMAND_CHAR){
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parse(
		Buffer* buffer, CommandInterface** command){

	char commandSequence[HEADER_LENGTH+1] = {'\0'};
	strncpy ( commandSequence, &buffer->getData()[HEADER_INDEX_POSITION], HEADER_LENGTH);
	*command = new SetterCommand();

	if( strcmp(commandSequence, SET_MOTION_HEADER_CHAR) == 0){
		return parseSetMotionHeaderCommand(buffer, command);
	}

	if( strcmp(commandSequence, SET_MOTION_FRAME_CHAR) == 0){
		return parseSetMotionFrameCommand(buffer, command);
	}

	if( strcmp(commandSequence, RESET_JOINT_SETTINGS_CHAR) == 0){
		return parseResetJointSettingsCommand(buffer, (ResetJointSettingsCommand**)command);
	}

	if( strcmp(commandSequence, SET_HOME_VALUE_CHAR) == 0){
		return parseSetHomeValueCommand(buffer, (SetAngleHomeValueCommand**)command);
	}

	if( strcmp(commandSequence, SET_MAX_VALUE_CHAR) == 0){
		return parseSetMaxValueCommand(buffer, (SetAngleMaxValueCommand**)command);
	}

	if( strcmp(commandSequence, SET_MIN_VALUE_CHAR) == 0){
		return parseSetMinValueCommand(buffer, (SetMinValueCommand**)command);
	}

	delete *command;
	return ParserInterface::UNKNOWN_COMMAND_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMotionHeaderCommand(
		Buffer* buffer, CommandInterface** command){
	if(buffer->getLenght() != SET_MOTION_HEADER_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMotionFrameCommand(
		Buffer* buffer, CommandInterface** command){
	if(buffer->getLenght() != SET_MOTION_FRAME_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseResetJointSettingsCommand(
		Buffer* buffer, ResetJointSettingsCommand** command){
	(**command).setSubCommandType(SetterCommand::RESET_JOINT_SETTINGS);
	if(buffer->getLenght() != RESET_JOINT_SETTINGS_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetHomeValueCommand(
		Buffer* buffer, SetAngleHomeValueCommand** command){
	(**command).setSubCommandType(SetterCommand::SET_ANGLE_HOME_VALUE);
	if(buffer->getLenght() != SET_HOME_VALUE_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	char deviceId[DEVICE_ID_LENGTH+1] = {'\0'};
	strncpy ( deviceId, &buffer->getData()[DEVICE_ID_POSITION],  DEVICE_ID_LENGTH);
	(**command).setDeviceId(ParserUtils::hexbytes2int(deviceId, DEVICE_ID_LENGTH));

	char value[VALUE_LENGHT+1] = {'\0'};
	strncpy ( value, &buffer->getData()[VALUE_POSITION],  VALUE_LENGHT);
	(**command).setValue(ParserUtils::hexbytes2int(value, VALUE_LENGHT));

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMaxValueCommand(
		Buffer* buffer, SetAngleMaxValueCommand** command){
	(**command).setSubCommandType(SetterCommand::SET_ANGLE_MAX_VALUE);
	if(buffer->getLenght() != SET_MAX_VALUE_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	char deviceId[DEVICE_ID_LENGTH+1] = {'\0'};
	strncpy ( deviceId, &buffer->getData()[DEVICE_ID_POSITION],  DEVICE_ID_LENGTH);
	(**command).setDeviceId(ParserUtils::hexbytes2int(deviceId, DEVICE_ID_LENGTH));

	char value[VALUE_LENGHT+1] = {'\0'};
	strncpy ( value, &buffer->getData()[VALUE_POSITION],  VALUE_LENGHT);
	(**command).setValue(ParserUtils::hexbytes2int(value, VALUE_LENGHT));

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMinValueCommand(
		Buffer* buffer, SetMinValueCommand** command){
	(**command).setSubCommandType(SetterCommand::SET_ANGLE_MIN_VALUE);
	if(buffer->getLenght() != SET_MIN_VALUE_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	char deviceId[DEVICE_ID_LENGTH+1] = {'\0'};
	strncpy ( deviceId, &buffer->getData()[DEVICE_ID_POSITION],  DEVICE_ID_LENGTH);
	(**command).setDeviceId(ParserUtils::hexbytes2int(deviceId, DEVICE_ID_LENGTH));

	char value[VALUE_LENGHT+1] = {'\0'};
	strncpy ( value, &buffer->getData()[VALUE_POSITION],  VALUE_LENGHT);
	(**command).setValue(ParserUtils::hexbytes2int(value, VALUE_LENGHT));

	return NO_ERROR;
}
