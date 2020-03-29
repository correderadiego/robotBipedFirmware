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
		ExternalFileSystemController* externalFileSystemController,
		ParserController*	parserController) {
		this->jointController 				= jointController;
		this->motionController				= motionController;
		this->interpreter	  			= interpreter;
		this->eyeController	  			= eyeController;
		this->wifiController  				= wifiController;
		this->httpServerController			= httpServerController;
		this->externalFileSystemController 		= externalFileSystemController;
		this->parserController				= parserController;
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
	serialSocketController(plen);
	tcpSocketController(plen);
}

void PlenController::serialSocketController(Plen* plen){
	if (!SerialCommunication::getInstance()->available()){
		return;
	}
	CommandInterface* command = new CommandInterface();
	proccessInputChar(plen, SerialCommunication::getInstance()->read(), *command);
}

void PlenController::tcpSocketController(Plen* plen){
	if (!wifiController->isSocketClientAvailable(plen)){
		return;
	}
	CommandInterface* command = new CommandInterface();
	proccessInputChar(plen, wifiController->read(plen), *command);
}
	

void PlenController::proccessInputChar(Plen* plen, char character, CommandInterface command){
	Buffer::BufferErrors bufferError = plen->getBuffer()->addChar(character);

	if(bufferError == Buffer::BUFFER_FULL_ERROR){
		Logger::getInstance()->log(Logger::ERROR, F("Full buffer error"));
		return;
	}

	if(!plen->getBuffer()->getCommandComplete()){
		return;
	}

	ParserInterface::ParseErrors parseError = parserController->parse(plen->getBuffer(), command);

	if(parseError == ParserInterface::INCOMPLETE_COMMAND){
		Logger::getInstance()->log(Logger::ERROR, F("Incomplete command"));
		return;
	}

	if(parseError == ParserInterface::UNKNOWN_COMMAND){
		Logger::getInstance()->log(Logger::ERROR, F("Unknown command"));
		return;
	}
}
