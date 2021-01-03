/*
 * NumberParser.cpp
 *
 *  Created on: 22 abr. 2020
 *      Author: Diego
 */

#include <utils/ParserUtils.h>

unsigned int ParserUtils::hexBytesToUint(
		const char* bytes,
		unsigned char size){
	unsigned int result = 0;

	for (int index = 0; index < size; index++)
	{
		unsigned int placeholder = bytes[index];

		if (placeholder >= 'a') placeholder -= ('a' - 10);
		if (placeholder >= 'A') placeholder -= ('A' - 10);
		if (placeholder >= '0') placeholder -= '0';

		unsigned int base = 0x01 << ((size - index - 1) * 4);

		result += placeholder * base;
	}

	return result;
}

int ParserUtils::hexbytes2int(
		const char* bytes,
		unsigned char size){
	unsigned int temp = hexBytesToUint(bytes, size);
	temp <<= (((sizeof(int) * 2) - size) * 4);

	int result = temp;
	result >>= (((sizeof(int) * 2) - size) * 4);
	return result;
}

