/*
 * ParserControllerCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: Diego
 */

#include <logic/controller/parser/ParserControllerControllerCommand.h>

ParserControllerControllerCommand::ParserControllerControllerCommand() {}

bool ParserControllerControllerCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == CONTROLLER_COMMAND_CHAR){
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parse(
											Buffer* buffer, CommandInterface** command){

	char commandSequence[HEADER_LENGTH+1] = {'\0'};
	strncpy ( commandSequence, &buffer->getData()[HEADER_INDEX_POSITION],  HEADER_LENGTH);

	if( strcmp(commandSequence, APPY_NATIVE_VALUE_CHAR) == 0){
		*command = new ApplyNativeValueCommand();
		return parseApplyNativeValueCommand(buffer, (ApplyNativeValueCommand**)command);
	}

	if( strcmp(commandSequence, APPLY_DIFF_VALUE_CHAR) == 0){
		*command = new ApplyDiffValueCommand();
		return parseApplyDiffValueCommand(buffer, (ApplyDiffValueCommand**)command);
	}

	if( strcmp(commandSequence, PLAY_A_MOTION_CHAR) == 0){
		*command = new PlayAMotionCommand();
		return parsePlayAMotionCommand(buffer, (PlayAMotionCommand**)command);
	}

	if( strcmp(commandSequence, STOP_A_MOTION_CHAR) == 0){
		*command = new StopAMotionCommand();
		return parseStopAMotionCommand(buffer, (StopAMotionCommand**)command);
	}

	if( strcmp(commandSequence, APPLY_HOME_POSITION_CHAR) == 0){
		*command = new ApplyHomePositionCommand();
		return parseApplyHomePositionCommand(buffer, (ApplyHomePositionCommand**)command);
	}

	if( strcmp(commandSequence, SET_JOIN_POSITION_CHAR) == 0){
		*command = new ApplyJointPositionCommand();
		return parseApplyJointPositionCommand(buffer, (ApplyJointPositionCommand**)command);
	}

	delete *command;
	*command = nullptr;
	return ParserControllerControllerCommand::UNKNOWN_COMMAND_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parseApplyNativeValueCommand(
		Buffer* buffer, ApplyNativeValueCommand** command){
	(**command).setSubCommandType(ControllerCommand::APPY_NATIVE_VALUE);
	if(buffer->getLenght() != APPLY_NATIVE_COMMAND_LENGTH){
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

ParserInterface::ParseErrors ParserControllerControllerCommand::parseApplyDiffValueCommand(
		Buffer* buffer, ApplyDiffValueCommand** command){
	(**command).setSubCommandType(ControllerCommand::APPLY_DIFF_VALUE);
	if(buffer->getLenght() != APPLY_DIFF_COMMAND_LENGTH){
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

ParserInterface::ParseErrors ParserControllerControllerCommand::parsePlayAMotionCommand(
		Buffer* buffer, PlayAMotionCommand** command){
	(**command).setSubCommandType(ControllerCommand::PLAY_A_MOTION);
	if(buffer->getLenght() != PLAY_MOTION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	char slot[SLOT_LENGTH+1] = {'\0'};
	strncpy ( slot, &buffer->getData()[SLOT_POSITION],  SLOT_LENGTH);
	(**command).setPosition(ParserUtils::hexbytes2int(slot, SLOT_LENGTH));

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parseStopAMotionCommand(
		Buffer* buffer, StopAMotionCommand** command){
	(**command).setSubCommandType(ControllerCommand::STOP_A_MOTION);
	if(buffer->getLenght() != STOP_MOTION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parseApplyHomePositionCommand(
		Buffer* buffer, ApplyHomePositionCommand** command){
	(**command).setSubCommandType(ControllerCommand::APPLY_HOME_POSITION);
	if(buffer->getLenght() != APPLY_HOME_POSITION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerControllerCommand::parseApplyJointPositionCommand(
		Buffer* buffer, ApplyJointPositionCommand** command){
	(**command).setSubCommandType(ControllerCommand::APPLY_JOINT_POSITION);
	if(buffer->getLenght() != APPLY_JOINT_POSITION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	char deviceId[DEVICE_ID_LENGTH+1] = {'\0'};
	strncpy ( deviceId, &buffer->getData()[DEVICE_ID_POSITION],  DEVICE_ID_LENGTH);
	(**command).setJoint(ParserUtils::hexbytes2int(deviceId, DEVICE_ID_LENGTH));

	char value[VALUE_LENGHT+1] = {'\0'};
	strncpy ( value, &buffer->getData()[VALUE_POSITION],  VALUE_LENGHT);
	(**command).setPosition(ParserUtils::hexbytes2int(value, VALUE_LENGHT));
	return NO_ERROR;
}
