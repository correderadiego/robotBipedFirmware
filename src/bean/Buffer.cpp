/*
 * Buffer.cpp
 *
 *  Created on: 23 mar. 2020
 *      Author: ziash
 */

#include <bean/Buffer.h>

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
}

char* Buffer::getData(){
	return data;
}

Buffer::BufferErrors Buffer::addChar(char character){
	if(position >= SIZE){
		clearBuffer();
		return BUFFER_FULL_ERROR;
	}

	if(character == COMMAND_COMPLETE_CHAR){
		commandComplete = true;
		return NO_ERROR;
	}

	data[position] = character;
	position ++;
	data[position] = '\0';
	return NO_ERROR;
}

bool Buffer::getCommandComplete(){
	return commandComplete;
}
