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

bool ParserControllerSetterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == SETTER_COMMAND_CHAR){
		Logger::getInstance()->log(Logger::DEBUG, F("Setter command received"));
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parse(
		Buffer* buffer, CommandInterface command){

	char commandSequence[2] = {};
	strncpy ( commandSequence, &buffer->getData()[1], 2);

	if( strcmp(commandSequence, SET_MOTION_HEADER_CHAR) == 0){
		return parseSetMotionHeaderCommand(buffer, command);
	}

	if( strcmp(commandSequence, SET_MOTION_FRAME_CHAR) == 0){
		return parseSetMotionFrameCommand(buffer, command);
	}

	if( strcmp(commandSequence, RESET_JOINT_SETTINGS_CHAR) == 0){
		return parseResetJointSettingsCommand(buffer, command);
	}

	if( strcmp(commandSequence, SET_HOME_VALUE_CHAR) == 0){
		return parseSetHomeCommand(buffer, command);
	}

	if( strcmp(commandSequence, SET_MAX_VALUE_CHAR) == 0){
		return parseSetMaxValueCommand(buffer, command);
	}

	if( strcmp(commandSequence, SET_MIN_VALUE_CHAR) == 0){
		return parseSetMinValueCommand(buffer, command);
	}

	return ParserInterface::UNKNOWN_COMMAND_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMotionHeaderCommand(
		Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != SET_MOTION_HEADER_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	//command = *(new Set());
	Logger::getInstance()->log(Logger::DEBUG, F("Set motion header command received"));
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMotionFrameCommand(
		Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != SET_MOTION_FRAME_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	//command = *(new PopAFunctionCommand());
	Logger::getInstance()->log(Logger::DEBUG, F("Set motion frame command received"));
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseResetJointSettingsCommand(
		Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != RESET_JOINT_SETTINGS_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new ResetJointSettingsCommand());
	Logger::getInstance()->log(Logger::DEBUG, F("Reset joint setting command received"));
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetHomeCommand(
		Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != SET_HOME_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new SetHomeValueCommand());
	Logger::getInstance()->log(Logger::DEBUG, F("Set home command received"));
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMaxValueCommand(
		Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != SET_MAX_VALUE_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new SetMaxValueCommand());
	Logger::getInstance()->log(Logger::DEBUG, F("Set max value command received"));
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMinValueCommand(
		Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != SET_MIN_VALUE_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new SetMinValueCommand());
	Logger::getInstance()->log(Logger::DEBUG, F("Set min value command received"));
	return NO_ERROR;
}
