/*
 * Plen.cpp
 *
 *  Created on: 15 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/PlenController.h>

PlenController::PlenController(
		JointController*  				jointController,
		MotionController*  				motionController,
		Interpreter*       				interpreter,
		EyeController*	   				eyeController,
		ExternalFileSystemController* 	externalFileSystemController,
		ParserController*				parserController,
		ProcessController* 				processController) {
		this->jointController 				= jointController;
		this->motionController				= motionController;
		this->interpreter	  				= interpreter;
		this->eyeController	  				= eyeController;
		this->externalFileSystemController 	= externalFileSystemController;
		this->parserController				= parserController;
		this->processController				= processController;
}

void PlenController::initPlenController(Plen* plen){
	loadFileConfiguration(plen);
}

void PlenController::loadFileConfiguration(Plen* plen){
	if(externalFileSystemController->isFileConfigurationInitiated(plen)){
		externalFileSystemController->loadFileConfiguration(plen);
		return;
	}
	externalFileSystemController->initFileConfiguration(plen);
}

void PlenController::executeThreadTasks(Plen* plen){
	processBuffer(plen, plen->getSerialBuffer());
	processBuffer(plen, plen->getSocketBuffer());
//	this->jointController->executeThreadTasks(plen);
//	this->eyeController->executeThreadTasks(plen);
}

void PlenController::processBuffer(Plen* plen, Buffer* buffer){
	ParseBufferErrors parseBufferError = parseBuffer(buffer, command);
	if(parseBufferError == NO_ERROR){
		//processController->process(plen, *command);
	}
}

PlenController::ParseBufferErrors PlenController::parseBuffer(Buffer* buffer, CommandInterface** command){
	if(!buffer->isCommandComplete()){
		return COMMAND_INCOMPLETE_ERROR;
	}

	ParserInterface::ParseErrors parseError = parserController->parse(buffer, command);
	buffer->clearBuffer();

	if(parseError == ParserInterface::WRONG_LENGHT_COMMAND_ERROR){
		Logger::getInstance()->log(Logger::ERROR, S("Wrong command length"));
		return WRONG_LENGTH_COMMAND_ERROR;
	}

	if(parseError == ParserInterface::UNKNOWN_COMMAND_ERROR){
		Logger::getInstance()->log(Logger::ERROR, S("Unknown command"));
		return UNKNOWN_COMMAND_ERROR;
	}

	return NO_ERROR;
}
