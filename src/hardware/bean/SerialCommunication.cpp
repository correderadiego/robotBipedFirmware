/*
 * SerialCommunication.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#include <hardware/bean/SerialCommunication.h>

SerialCommunication* SerialCommunication::serialCommunication = NULL;

SerialCommunication::SerialCommunication() {
	Serial.begin(SERIAL_BAUDRATE);
}

SerialCommunication* SerialCommunication::getInstance(){
	if(serialCommunication == NULL){
		serialCommunication = new SerialCommunication();
	}
	return serialCommunication;
}

void SerialCommunication::println(const char * string){
	Serial.println(FPSTR(string));
}

void SerialCommunication::print(const char * string){
	Serial.print(FPSTR(string));
}

void SerialCommunication::print(int number){
	Serial.print(number);
}

bool SerialCommunication::available(){
	return Serial.available();
}

char SerialCommunication::read(){
	return Serial.read();
}

void SerialCommunication::flush(){
	Serial.flush();
}

SerialCommunication::~SerialCommunication() {}

