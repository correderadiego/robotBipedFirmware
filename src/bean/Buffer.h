/*
 * Buffer.h
 *
 *  Created on: 23 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_BEAN_BUFFER_H_
#define SRC_BEAN_BUFFER_H_

#define LENGTH  	128
#define EMPTY_CHAR '\0'

class Buffer {
public:
	enum BufferErrors{
	  BUFFER_FULL_ERROR,
	  COMMAND_COMPLETE,
	  NO_ERROR = 0
	};

	Buffer(int position = 0);
	int getPosition();
	char* getData();
	BufferErrors addChar(char character);

private:
	char data[LENGTH];
	int	 position;

	void clearBuffer();
};

#endif /* SRC_BEAN_BUFFER_H_ */
