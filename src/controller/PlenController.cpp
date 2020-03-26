/*
 * Plen.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#include "PlenController.h"

PlenController::PlenController(
		JointController*  jointController,
		MotionController*  motionController,
		Interpreter*       interpreter,
		EyeController*	   eyeController,
		WifiController*	   wifiController,
		HttpServerController* httpServerController,
		ExternalFileSystemController* externalFileSystemController) {
		this->jointController 				= jointController;
		this->motionController				= motionController;
		this->interpreter	  				= interpreter;
		this->eyeController	  				= eyeController;
		this->wifiController  				= wifiController;
		this->httpServerController			= httpServerController;
		this->externalFileSystemController 	= externalFileSystemController;
}

void PlenController::initPlenController(Plen* plen){
	loadFileConfiguration(plen);
	jointController->loadInitialValues();
	wifiController->connect(plen);
	httpServerController->configureHttpServer(plen);
	httpServerController->initHttpServer();
}

void PlenController::loadFileConfiguration(Plen* plen){
	if(externalFileSystemController->isFileConfigurationInitiated(plen)){
		externalFileSystemController->loadFileConfiguration(plen);
		return;
	}
	externalFileSystemController->initFileConfiguration(plen);
}

void PlenController::executeThreadTasks(Plen* plen){
	socketController(plen);
	this->jointController->executeThreadTasks(plen);
	this->eyeController->executeThreadTasks(plen);
	this->wifiController->executeThreadTasks(plen);
	this->httpServerController->executeThreadTasks();
}

void PlenController::socketController(Plen* plen){
	serialSocketController();
	tcpSocketController(plen);
}

void PlenController::serialSocketController(){
	if (!SerialCommunication::getInstance()->available()){
		return;
	}

	//readByte(SerialCommunication::getInstance()->read());
}

void PlenController::tcpSocketController(Plen* plen){
	if (!wifiController->isSocketClientAvailable(plen)){
		return;
	}

	//Buffer::BufferErrors bufferError = plen->getBuffer()->addChar(wifiController->read(plen));

}
