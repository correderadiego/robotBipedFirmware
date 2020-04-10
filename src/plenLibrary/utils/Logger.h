/*
 * Logger.h
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_PLENLIBRARY_UTILS_LOGGER_H_
#define SRC_PLENLIBRARY_UTILS_LOGGER_H_

#include <plenLibrary/utils/SocketLoggerInterface.h>
#include "hardware/SerialCommunication.h"

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
	void initLogger(SocketLoggerInterface* socketLoggerInterface);

private:
	LogLevel logLevel = DEBUG;
	static Logger* logger;
	static SocketLoggerInterface* socketLoggerInterface;
};

#endif /* SRC_PLENLIBRARY_UTILS_LOGGER_H_ */
