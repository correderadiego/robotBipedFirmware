/*
 * Logger.h
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_UTILS_LOGGER_H_
#define SRC_UTILS_LOGGER_H_

#include "Arduino.h"
#include "hardware/SerialCommunication.h"

class Logger {
public:
	enum LogLevel{
	  ERROR,
	  WARNING,
	  DEBUG = 0
	};
	Logger();
	static Logger* getInstance();
	void log(LogLevel logLevel, String message);
	virtual ~Logger();
	void setLogLevel(LogLevel loglevel);

private:
	LogLevel logLevel = DEBUG;
	static Logger* logger;
};

#endif /* SRC_UTILS_LOGGER_H_ */
