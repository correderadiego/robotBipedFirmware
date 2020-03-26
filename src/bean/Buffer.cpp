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

int Buffer::getPosition(){
	return this->position;
}

void Buffer::clearBuffer(){
	for (unsigned char index = 0; index < LENGTH; index++){
		data[index] = EMPTY_CHAR;
	}
}

char* Buffer::getData(){
	return data;
}
