/*
 * ParserControllerInterpreterCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <controller/parser/ParserControllerInterpreterCommand.h>

ParserControllerInterpreterCommand::ParserControllerInterpreterCommand() {}
ParserControllerInterpreterCommand::ParserControllerInterpreterCommand(
		ParserInterface parserInterface) {}


ParserControllerInterpreterCommand::~ParserControllerInterpreterCommand() {}

bool ParserControllerInterpreterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == INTERPRETER_COMMAND_CHAR){
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parse(
									Buffer* buffer, InterpreterCommand command){

	char commandSequence[2] = {};
	strncpy ( commandSequence, &buffer->getData()[1], 2);
	if( strcmp(commandSequence, PUSH_FUNCTION_CHAR) == 0){
		command.setSubCommandType(InterpreterCommand::PUSH_FUNCTION_VALUE);
		return ParserInterface::NO_ERROR;
	}

	if( strcmp(commandSequence, POP_FUNCTION_CHAR) == 0){
		command.setSubCommandType(InterpreterCommand::POP_FUNCTION_VALUE);
		return ParserInterface::NO_ERROR;
	}

	if( strcmp(commandSequence, RESET_INTERPRETER_CHAR) == 0){
		command.setSubCommandType(InterpreterCommand::RESET_INTERPRETER);
		return ParserInterface::NO_ERROR;
	}

	command.setSubCommandType(InterpreterCommand::UNKNOWN_SUB_COMMAND_TYPE);
	return ParserInterface::UNKNOWN_COMMAND;
}
