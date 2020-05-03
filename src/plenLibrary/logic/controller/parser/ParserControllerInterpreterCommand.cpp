/*
 * ParserControllerInterpreterCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/parser/ParserControllerInterpreterCommand.h>

ParserControllerInterpreterCommand::ParserControllerInterpreterCommand() {}

bool ParserControllerInterpreterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == INTERPRETER_COMMAND_CHAR){
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parse(
									Buffer* buffer, CommandInterface** command){
	char commandSequence[3] = {'\0'};
	strncpy ( commandSequence, &buffer->getData()[1],  2);
	*command = new InterpreterCommand();

	if( strcmp(commandSequence, PUSH_A_FUNCTION_CHAR) == 0){
		return parsePushAFunctionCommand(buffer, (PushAFunctionCommand**)command);
	}

	if( strcmp(commandSequence, POP_A_FUNCTION_CHAR) == 0){
		return parsePopAFunctionCommand(buffer, (PopAFunctionCommand**)command);
	}

	if( strcmp(commandSequence, RESET_INTERPRETER_CHAR) == 0){
		return parseResetInterpreterCommand(buffer, (ResetInterpreterCommand**)command);
	}

	delete *command;
	return ParserInterface::UNKNOWN_COMMAND_ERROR;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parsePopAFunctionCommand(
		Buffer* buffer, PopAFunctionCommand** command){
	(**command).setSubCommandType(InterpreterCommand::POP_A_FUNCTION);
	if(buffer->getLenght() != POP_A_FUNCTION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parsePushAFunctionCommand(
		Buffer* buffer, PushAFunctionCommand** command){
	(**command).setSubCommandType(InterpreterCommand::PUSH_A_FUNCTION);
	if(buffer->getLenght() != PUSH_A_FUNCTION_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	char slot[SLOT_LENGTH+1] = {'\0'};
	strncpy ( slot, &buffer->getData()[SLOT_POSITION],  SLOT_LENGTH);
	(**command).setSlot(ParserUtils::hexbytes2int(slot, SLOT_LENGTH));

	char loopCount[LOOP_COUNT_LENGTH+1] = {'\0'};
	strncpy ( loopCount, &buffer->getData()[LOOP_COUNT_POSITION],  LOOP_COUNT_LENGTH);
	(**command).setLoopCount(ParserUtils::hexbytes2int(loopCount, LOOP_COUNT_LENGTH));

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parseResetInterpreterCommand(
		Buffer* buffer, ResetInterpreterCommand** command){
	(**command).setSubCommandType(InterpreterCommand::RESET_INTERPRETER);
	if(buffer->getLenght() != RESET_INTERPRETER_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	return NO_ERROR;
}
