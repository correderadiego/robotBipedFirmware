/*
 * Plen.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#include "PlenController.h"

PlenController::PlenController(
		JointController*  				jointController,
		MotionController*  				motionController,
		Interpreter*       				interpreter,
		EyeController*	   				eyeController,
		WifiController*	   				wifiController,
		HttpServerController* 			httpServerController,
		ExternalFileSystemController* 	externalFileSystemController,
		ParserController*				parserController,
		ProcessController* 				processController) {
		this->jointController 				= jointController;
		this->motionController				= motionController;
		this->interpreter	  				= interpreter;
		this->eyeController	  				= eyeController;
		this->wifiController  				= wifiController;
		this->httpServerController			= httpServerController;
		this->externalFileSystemController 	= externalFileSystemController;
		this->parserController				= parserController;
		this->processController				= processController;
}

void PlenController::initPlenController(Plen* plen){
	loadFileConfiguration(plen);
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
	processInputChar(plen, SerialCommunication::getInstance()->read());
}

void PlenController::tcpSocketController(Plen* plen){
	if (!wifiController->isSocketClientAvailable(plen)){
		return;
	}
	processInputChar(plen, wifiController->read(plen));
}

void PlenController::processInputChar(Plen* plen, char character){
	CommandInterface* command = new CommandInterface();
	ParseInputCharError parseInputCharError = parseInputChar(plen, character, *command);
	if( parseInputCharError == NO_ERROR){
		processController->process(plen, *command);
	}
}

PlenController::ParseInputCharError PlenController::parseInputChar(Plen* plen, char character, CommandInterface command){
	Buffer::BufferErrors bufferError = plen->getBuffer()->addChar(character);

	if(bufferError == Buffer::BUFFER_FULL_ERROR){
		Logger::getInstance()->log(Logger::ERROR, F("Full buffer error"));
		return BUFFER_FULL_ERROR;
	}

	if(!plen->getBuffer()->getCommandComplete()){
		return COMMAND_INCOMPLETE_ERROR;
	}

	ParserInterface::ParseErrors parseError = parserController->parse(plen->getBuffer(), command);

	if(parseError == ParserInterface::WRONG_LENGHT_COMMAND_ERROR){
		Logger::getInstance()->log(Logger::ERROR, F("Incomplete command"));
		return WRONG_LENGHT_COMMAND_ERROR;
	}

	if(parseError == ParserInterface::UNKNOWN_COMMAND_ERROR){
		Logger::getInstance()->log(Logger::ERROR, F("Unknown command"));
		return UNKNOWN_COMMAND_ERROR;
	}

	return NO_ERROR;
}
