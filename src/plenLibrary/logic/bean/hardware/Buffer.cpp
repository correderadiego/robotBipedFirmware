/*
 * Buffer.cpp
 *
 *  Created on: 23 mar. 2020
 *      Author: ziash
 */

#include <logic/bean/hardware/Buffer.h>

Buffer::Buffer(int position) {
	this->position = position;
	clearBuffer();
}

int Buffer::getLenght(){
	return this->position;
}

void Buffer::clearBuffer(){
	for (unsigned char index = 0; index < SIZE; index++){
		data[index] = EMPTY_CHAR;
	}
	commandComplete = false;
	this->position = 0;
}

char* Buffer::getData(){
	return data;
}

Buffer::BufferErrors Buffer::addChar(char character){
	if(position >= SIZE){
		clearBuffer();
		Logger::getInstance()->log(Logger::ERROR, S("Buffer size : "));
		Logger::getInstance()->log(Logger::ERROR, (char *)position);
		return BUFFER_FULL_ERROR;
	}

	if(character == COMMAND_COMPLETE_CHAR){
		commandComplete = true;
		Logger::getInstance()->log(Logger::DEBUG, S("Command complete "));
		Logger::getInstance()->log(Logger::DEBUG, (char *)data);
		return NO_ERROR;
	}

	if(character == COMMAND_NEW_LINE_CHAR){
			return NO_ERROR;
	}

	data[position] = character;
	position ++;
	data[position] = EMPTY_CHAR;
	return NO_ERROR;
}

bool Buffer::getCommandComplete(){
	return commandComplete;
}
