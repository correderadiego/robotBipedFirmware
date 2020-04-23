/*
 * NumberParser.h
 *
 *  Created on: 22 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENLIBRARY_UTILS_PARSERUTILS_H_
#define SRC_PLENLIBRARY_UTILS_PARSERUTILS_H_

#include "string.h"

class ParserUtils {
public:
	static unsigned int hexBytesToUint(const char* bytes, unsigned char size);
	static int hexbytes2int(const char* bytes, unsigned char size);
};

#endif /* SRC_PLENLIBRARY_UTILS_NUMBERPARSER_H_ */
