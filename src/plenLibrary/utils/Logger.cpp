/*
 * Logger.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#include "Logger.h"

Logger* Logger::logger = nullptr;

Logger::Logger() {}

Logger* Logger::getInstance(){
	if(logger == nullptr){
		logger = new Logger();
	}

	return logger;
}

void Logger::setLogLevel(LogLevel logLevel){
	this->logLevel = logLevel;
}

void Logger::log(LogLevel logLevel, const char * message){
	if(this->logLevel < logLevel){
		return;
	}
	SerialCommunication::getInstance()->print(message);
}

void Logger::log(LogLevel logLevel, int message){
	if(this->logLevel < logLevel){
		return;
	}
	SerialCommunication::getInstance()->print(message);
}

void Logger::logln(LogLevel logLevel, const char * message){
	if(this->logLevel < logLevel){
		return;
	}
	SerialCommunication::getInstance()->println(message);
}

Logger::~Logger() {}

