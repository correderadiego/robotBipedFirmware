/*
 * SerialCommunication.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#include <hardware/SerialCommunication.h>

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

void SerialCommunication::println(String string){
	Serial.println(string);
}

bool SerialCommunication::available(){
	return Serial.available();
}

char SerialCommunication::read(){
	return Serial.read();
}

SerialCommunication::~SerialCommunication() {}

