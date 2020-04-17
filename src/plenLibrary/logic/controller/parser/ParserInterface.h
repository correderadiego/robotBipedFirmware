/*
 * ParserInterface.h
 *
 *  Created on: 25 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_PARSER_PARSERINTERFACE_H_
#define SRC_CONTROLLER_PARSER_PARSERINTERFACE_H_


#include <logic/bean/commands/CommandInterface.h>
#include <logic/bean/hardware/Buffer.h>
#include <utils/Logger.h>

class ParserInterface{
	#define HEADER_CHAR_POSITION			 0
    public:

	enum ParseErrors{
	  NO_ERROR,
	  UNKNOWN_COMMAND_ERROR,
	  WRONG_LENGHT_COMMAND_ERROR
	};

    virtual bool match(Buffer* buffer);
    virtual ParserInterface::ParseErrors parse(Buffer* buffer, CommandInterface command);
};



#endif /* SRC_CONTROLLER_PARSER_PARSERINTERFACE_H_ */
