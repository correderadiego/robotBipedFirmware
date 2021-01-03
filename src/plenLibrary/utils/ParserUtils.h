/*
 * NumberParser.h
 *
 *  Created on: 22 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_PLENLIBRARY_UTILS_PARSERUTILS_H_
#define SRC_PLENLIBRARY_UTILS_PARSERUTILS_H_

#include <stdlib.h>
#include <string.h>

class ParserUtils {
public:
	static unsigned int hexBytesToUint(const char* bytes, unsigned char size);
	static int hexbytes2int(const char* bytes, unsigned char size);
	static char* tostr(int x);
};

#endif /* SRC_PLENLIBRARY_UTILS_NUMBERPARSER_H_ */
