/*
 * ParserController.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: Diego
 */

#include <logic/controller/parser/ParserController.h>

ParserController::ParserController() {}

ParserController::~ParserController() {
	for(int i = 0; i < PARSER_CONTROLLER_VECTOR_SIZE; i++) {
		delete parseController[i];
	}
}

ParserInterface::ParseErrors ParserController::parse(Buffer* buffer,  CommandInterface** command){
	if (buffer->getLenght() < MIN_MESSAGE_SIZE){
			return ParserInterface::WRONG_LENGHT_COMMAND_ERROR;
	}

	for (unsigned int i= 0; i < sizeof(parseController)/sizeof(parseController[0]); i++) {
		if (parseController[i]->match(buffer)) {
			return parseController[i]->parse(buffer, command);
		}
	}

	return ParserInterface::UNKNOWN_COMMAND_ERROR;
}
