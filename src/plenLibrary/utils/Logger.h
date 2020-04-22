/*
 * Logger.h
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENLIBRARY_UTILS_LOGGER_H_
#define SRC_PLENLIBRARY_UTILS_LOGGER_H_

#include "hardware/bean/SerialCommunication.h"

class Logger {
public:
	enum LogLevel{
	  ERROR,
	  WARNING,
	  DEBUG,
	  INFO = 0
	};
	Logger();
	static Logger* getInstance();
	void log(LogLevel logLevel, const char * message);
	virtual ~Logger();
	void setLogLevel(LogLevel loglevel);

private:
	LogLevel logLevel = DEBUG;
	static Logger* logger;
};

#endif /* SRC_PLENLIBRARY_UTILS_LOGGER_H_ */
