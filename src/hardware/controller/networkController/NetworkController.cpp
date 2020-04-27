/*
 * NetworkController.cpp
 *
 *  Created on: 12 abr. 2020
 *      Author: ziash
 */

#include <hardware/controller/networkController/NetworkController.h>

NetworkController::NetworkController(
		WifiController* wifiController,
		HttpServerController* httpServerController) {
	this->wifiController 		= wifiController;
	this->httpServerController 	= httpServerController;
}

void NetworkController::configureNetworkController(Plen* plen, Network* network){
	wifiController->connect(plen, network);
	wifiController->createSocketServer(network);
	httpServerController->configureHttpServer(network);
	httpServerController->initHttpServer();
}

void NetworkController::readByte(Plen* plen, Network* network){
	if (!wifiController->isSocketClientAvailable(network)){
		return;
	}

	Buffer::BufferErrors bufferError = plen->getSerialBuffer()->addChar(wifiController->read(network));

	if(bufferError == Buffer::BUFFER_FULL_ERROR){
		Logger::getInstance()->logln(Logger::ERROR, S("Full buffer error"));
		plen->getSerialBuffer()->clearBuffer();
	}
}

void NetworkController::executeThreadTasks(Plen* plen, Network* network){
	this->readByte(plen, network);
	this->wifiController->executeThreadTasks(network);
	this->httpServerController->executeThreadTasks();
}
