/*
 * SerialController.cpp
 *
 *  Created on: 12 abr. 2020
 *      Author: ziash
 */

#include <hardware/controller/SerialController.h>

void SerialController::readByte(Plen* plen, SerialCommunication* serialCommunication){
	if (!serialCommunication->available()){
		return;
	}

	Buffer::BufferErrors bufferError = plen->getSerialBuffer()->addChar(serialCommunication->read());

	if(bufferError == Buffer::BUFFER_FULL_ERROR){
		Logger::getInstance()->log(Logger::ERROR, S("Full buffer error"));
		plen->getSerialBuffer()->clearBuffer();
	}
}

void SerialController::executeThreadTasks(Plen* plen, SerialCommunication* serialCommunication){
	this->readByte(plen, serialCommunication);
	temporizedWait();
}

void SerialController::temporizedWait(){
	if(millis() - previousTemporizedWait > DEFAULT_WAIT_PERIOD){
		Logger::getInstance()->log(Logger::INFO,S("wait"));
		previousTemporizedWait = millis();
	}
}
