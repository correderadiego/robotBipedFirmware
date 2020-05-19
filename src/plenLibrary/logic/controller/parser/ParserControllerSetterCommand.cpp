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
		return parseSetMotionHeaderCommand(buffer, (SetMotionHeaderCommand**)command);
	}

	if( strcmp(commandSequence, SET_MOTION_FRAME_CHAR) == 0){
		return parseSetMotionFrameCommand(buffer, (SetMotionFrameCommand**)command);
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

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMotionFrameCommand(
		Buffer* buffer, SetMotionFrameCommand** command){
	(**command).setSubCommandType(SetterCommand::SET_MOTION_FRAME);
	if(buffer->getLenght() != SET_MOTION_FRAME_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	(**command).setMotionFrame(new Frame());

	char slot[SLOT_LENGTH+1] = {'\0'};
	strncpy ( slot, &buffer->getData()[SLOT_POSITION],  SLOT_LENGTH);
	(**command).getMotionFrame()->setHeaderPosition(ParserUtils::hexbytes2int(slot, SLOT_LENGTH));

	char frameIndexPosition[FRAME_INDEX_LENGTH+1] = {'\0'};
	strncpy ( frameIndexPosition, &buffer->getData()[FRAME_INDEX_POSITION],  FRAME_INDEX_LENGTH);
	(**command).getMotionFrame()->setFrameIndex(ParserUtils::hexbytes2int(frameIndexPosition, FRAME_INDEX_LENGTH));

	char transitionTime[TRANSITION_TIME_LENGTH+1] = {'\0'};
	strncpy ( transitionTime, &buffer->getData()[TRANSITION_TIME_POSITION],  TRANSITION_TIME_LENGTH);
	(**command).getMotionFrame()->setTransitionTime(ParserUtils::hexbytes2int(transitionTime, TRANSITION_TIME_LENGTH));

	int value[NUMBER_OF_JOINTS] = {};
	char valueChar[JOINT_VALUE_LENGTH+1] = {'\0'};
	for(int i = 0; i < NUMBER_OF_JOINTS; i++){
		strncpy ( valueChar, &buffer->getData()[JOINT_VALUE_POSITION+JOINT_VALUE_LENGTH*i], JOINT_VALUE_LENGTH);
		(**command).getMotionFrame()->getJointAngle()[i] =  ParserUtils::hexbytes2int(valueChar, JOINT_VALUE_LENGTH);
	}

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerSetterCommand::parseSetMotionHeaderCommand(
		Buffer* buffer, SetMotionHeaderCommand** command){
	(**command).setSubCommandType(SetterCommand::SET_MOTION_HEADER);
	if(buffer->getLenght() != SET_MOTION_HEADER_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	(**command).setMotionHeader(new Header());

	char slot[SLOT_LENGTH+1] = {'\0'};
	strncpy ( slot, &buffer->getData()[SLOT_POSITION],  SLOT_LENGTH);
	(**command).getMotionHeader()->setPosition(ParserUtils::hexbytes2int(slot, SLOT_LENGTH));

	char name[NAME_LENGTH+1] = {'\0'};
	strncpy ( name, &buffer->getData()[NAME_POSITION],  NAME_LENGTH);
	(**command).getMotionHeader()->setMotionName(name);

	char useLoop[USE_LOOP_LENGTH+1] = {'\0'};
	strncpy ( useLoop, &buffer->getData()[USE_LOOP_POSITION],  USE_LOOP_LENGTH);
	(**command).getMotionHeader()->setLoop((bool)ParserUtils::hexbytes2int(useLoop, USE_LOOP_LENGTH));

	char loopBegin[LOOP_BEGIN_LENGTH+1] = {'\0'};
	strncpy ( loopBegin, &buffer->getData()[LOOP_BEGIN_POSITION],  LOOP_BEGIN_LENGTH);
	(**command).getMotionHeader()->setLoopBeginFrame(ParserUtils::hexbytes2int(loopBegin, LOOP_BEGIN_LENGTH));

	char loopEnd[LOOP_END_LENGTH+1] = {'\0'};
	strncpy ( loopEnd, &buffer->getData()[LOOP_END_POSITION],  LOOP_END_LENGTH);
	(**command).getMotionHeader()->setLoopEndFrame(ParserUtils::hexbytes2int(loopEnd, LOOP_END_LENGTH));

	char loopCount[LOOP_COUNT_LENGTH+1] = {'\0'};
	strncpy ( loopCount, &buffer->getData()[LOOP_COUNT_POSITION],  LOOP_COUNT_LENGTH);
	(**command).getMotionHeader()->setLoopCount(ParserUtils::hexbytes2int(loopCount, LOOP_COUNT_LENGTH));

	char useJump[USE_JUMP_LENGTH+1] = {'\0'};
	strncpy ( useJump, &buffer->getData()[USE_JUMP_POSITION],  USE_JUMP_LENGTH);
	(**command).getMotionHeader()->setJump((bool)ParserUtils::hexbytes2int(useJump, USE_JUMP_LENGTH));

	char jumpSlot[JUMP_SLOT_LENGTH+1] = {'\0'};
	strncpy ( jumpSlot, &buffer->getData()[JUMP_SLOT_POSITION],  JUMP_SLOT_LENGTH);
	(**command).getMotionHeader()->setJumpSlot(ParserUtils::hexbytes2int(jumpSlot, JUMP_SLOT_LENGTH));

	char useExtra[USE_EXTRA_LENGTH+1] = {'\0'};
	strncpy ( useExtra, &buffer->getData()[USE_EXTRA_POSITION],  USE_EXTRA_LENGTH);
	(**command).getMotionHeader()->setExtra((bool)ParserUtils::hexbytes2int(useExtra, USE_EXTRA_LENGTH));

	char frameLength[FRAME_LENGTH_LENGTH+1] = {'\0'};
	strncpy ( frameLength, &buffer->getData()[FRAME_LENGTH_POSITION],  FRAME_LENGTH_LENGTH);
	(**command).getMotionHeader()->setMotionFrameLength(ParserUtils::hexbytes2int(frameLength, FRAME_LENGTH_LENGTH));

	return NO_ERROR;
}
