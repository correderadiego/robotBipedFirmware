/*
 * ParserController.cpp
 *
 *  Created on: 24 mar. 2020
 *      Author: ziash
 */

#include "ParserController.h"

ParserController::ParserController() {}

ParserInterface::ParseErrors ParserController::parse(Buffer* buffer,  CommandInterface command){
	if (buffer->getPosition()< MIN_MESSAGE_SIZE){
			return ParserInterface::INCOMPLETE_MESSAGE;
	}

	for (unsigned int i= 0; i < sizeof(parseController)/sizeof(parseController[0]); i++) {
		if (parseController[i]->match(buffer)) {
			return parseController[i]->parse(buffer, command);
		}
	}

	return ParserInterface::UNKNOWN_COMMAND;
}
