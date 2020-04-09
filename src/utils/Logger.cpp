/*
 * Logger.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#include "Logger.h"

Logger* Logger::logger = NULL;

Logger::Logger() {}

Logger* Logger::getInstance(){
	if(logger == NULL){
		logger = new Logger();
	}

	return logger;
}

void Logger::setLogLevel(LogLevel logLevel){
	this->logLevel = logLevel;
}

void Logger::log(LogLevel logLevel, String message){
	if(this->logLevel < logLevel){
		return;
	}
	SerialCommunication::getInstance()->println(message);
}

Logger::~Logger() {}

