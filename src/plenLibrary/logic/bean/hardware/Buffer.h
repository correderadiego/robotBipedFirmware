/*
 * Buffer.h
 *
 *  Created on: 23 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_BUFFER_H_
#define SRC_BEAN_BUFFER_H_

#define BUFFER_SIZE				128
#define EMPTY_CHAR 				'\0'
#define COMMAND_COMPLETE_CHAR 	'\r'
#define COMMAND_NEW_LINE_CHAR 	'\n'

#include "utils/Logger.h"
#include <ArduinoIncludes.h>

class Buffer {
public:
	enum BufferErrors{
		NO_ERROR,
		BUFFER_FULL_ERROR
	};

	Buffer(int position = 0);
	int getLenght();
	char* getData();
	BufferErrors addChar(char character);
	bool isCommandComplete();
	void setCommandComplete(bool commandComplete);
	void clearBuffer();

private:
	char data[BUFFER_SIZE];
	int	 position;
	bool commandComplete;
};

#endif /* SRC_BEAN_BUFFER_H_ */
