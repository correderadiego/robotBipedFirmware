/*
 * ParserControllerInterpreterCommand.cpp
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/parser/ParserControllerInterpreterCommand.h>

ParserControllerInterpreterCommand::ParserControllerInterpreterCommand() {}

ParserControllerInterpreterCommand::ParserControllerInterpreterCommand(
		ParserInterface parserInterface) {}

bool ParserControllerInterpreterCommand::match(Buffer* buffer){
	if(buffer->getData()[HEADER_CHAR_POSITION] == INTERPRETER_COMMAND_CHAR){
		Logger::getInstance()->log(Logger::DEBUG, S("Interpreter command received"));
		return true;
	}
	return false;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parse(
									Buffer* buffer, CommandInterface command){

	((InterpreterCommand)command);
	char commandSequence[2] = {};
	strncpy ( commandSequence, &buffer->getData()[1], 2);
	if( strcmp(commandSequence, PUSH_FUNCTION_CHAR) == 0){
		return parsePushCodeCommand(buffer, command);
	}

	if( strcmp(commandSequence, POP_FUNCTION_CHAR) == 0){
		return parsePopCodeCommand(buffer, command);
	}

	if( strcmp(commandSequence, RESET_INTERPRETER_CHAR) == 0){
		return parseResetInterpreterCommand(buffer, command);
	}

	return ParserInterface::UNKNOWN_COMMAND_ERROR;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parsePopCodeCommand(
		Buffer* buffer, CommandInterface command){
	Logger::getInstance()->log(Logger::DEBUG, S("Pop code command received"));
	if(buffer->getLenght() != POP_CODE_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new PopAFunctionCommand());

	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parsePushCodeCommand(
		Buffer* buffer, CommandInterface command){
	Logger::getInstance()->log(Logger::DEBUG, S("Push code command received"));
	if(buffer->getLenght() != PUSH_CODE_COMMAND_LENGTH){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new PushAFunctionCommand());
	return NO_ERROR;
}

ParserInterface::ParseErrors ParserControllerInterpreterCommand::parseResetInterpreterCommand(
		Buffer* buffer, CommandInterface command){
	if(buffer->getLenght() != RESET_INTERPRETER_COMMAND_LENGHT){
		return WRONG_LENGHT_COMMAND_ERROR;
	}
	command = *(new ResetInterpreterCommand());
	return NO_ERROR;
}
