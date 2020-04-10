/*
 * Buffer.h
 *
 *  Created on: 23 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_BUFFER_H_
#define SRC_BEAN_BUFFER_H_

#define SIZE  					128
#define EMPTY_CHAR 				'\0'
#define COMMAND_COMPLETE_CHAR 	'\r'

#include <plenLibrary/utils/Logger.h>
#include "ArduinoIncludes.h"

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
	bool getCommandComplete();
	void setCommandComplete(bool commandComplete);
	void clearBuffer();

private:
	char data[SIZE];
	int	 position;
	bool commandComplete;
};

#endif /* SRC_BEAN_BUFFER_H_ */
