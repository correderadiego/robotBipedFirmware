/*
 * HeaderController.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/HeaderController.h>

HeaderController::HeaderController(ExternalFileSystemController* externalFileSystemController) {
	this->externalFileSystemController = externalFileSystemController;
}

HeaderController::HeaderControllerErrors HeaderController::set(File* fileMotion, Header* header){
	if 	((header->getMotionFrameLength() < FRAME_NUMBER_MIN) ||
		 (header->getMotionFrameLength() > FRAME_NUMBER_MAX)){
		Logger::getInstance()->logln(Logger::ERROR, S("Header frame size error"));
		return HEADER_FRAME_SIZE_ERROR;
	}

	if (header->getPosition() >= MOVEMENT_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Header position error"));
		return HEADER_POSITION_ERROR;
	}

	if (write(fileMotion, header) != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}
	return NO_ERROR;
}

HeaderController::HeaderControllerErrors HeaderController::get(File* fileMotion, Header* header){
	if (header->getPosition() >= MOVEMENT_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Header position error"));
		return HEADER_POSITION_ERROR;
	}

	if (read(fileMotion, header) != ExternalFileSystemController::NO_ERROR){
		Logger::getInstance()->logln(Logger::ERROR, S("Read header error"));
		return READ_ERROR;
	}
	return NO_ERROR;
}

ExternalFileSystemController::FileSystemErrors HeaderController::read(File* fileMotion, Header* header){
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(header->getHeaderMemory());

	return	this->externalFileSystemController->read(
													getMotionPosition(header->getPosition()),
													sizeof(*header->getHeaderMemory()),
													filler,
													&sizeRead,
													fileMotion
												);
}

ExternalFileSystemController::FileSystemErrors HeaderController::write(File* fileMotion, Header* header){
	unsigned char* filler = reinterpret_cast<unsigned char*>(header->getHeaderMemory());
	unsigned int sizeWrite = 0;

	return	this->externalFileSystemController->write(
													getMotionPosition(header->getPosition()),
													sizeof(*header->getHeaderMemory()),
													filler,
													&sizeWrite,
													fileMotion
												);
}

void HeaderController::dumpHeader(Header* header){
	Logger::getInstance()->logln(Logger::INFO, S("{"));
	Logger::getInstance()->log(Logger::INFO, S("\t\"slot\": "));
	Logger::getInstance()->log(Logger::INFO, static_cast<int>(header->getPosition()));
	Logger::getInstance()->logln(Logger::INFO, S(","));

	Logger::getInstance()->log(Logger::INFO, S("\t\"name\": \""));
	Logger::getInstance()->log(Logger::INFO, header->getMotionName());
	Logger::getInstance()->logln(Logger::INFO, S("\","));

	Logger::getInstance()->log(Logger::INFO, S("\t\"frame_length\": \""));
	Logger::getInstance()->log(Logger::INFO,  static_cast<int>(header->getMotionFrameLength()));
	Logger::getInstance()->logln(Logger::INFO, S("\","));

	Logger::getInstance()->logln(Logger::INFO, S("\t\"codes\": ["));

	if (header->useLoop()){
		Logger::getInstance()->logln(Logger::INFO, S("\t\t{"));
		Logger::getInstance()->logln(Logger::INFO, S("\t\t\t\"func\": \"loop\","));
		Logger::getInstance()->log(Logger::INFO, S("\t\t\t\"args\": ["));
		Logger::getInstance()->log(Logger::INFO, static_cast<int>(header->getLoopBeginFrame()));
		Logger::getInstance()->log(Logger::INFO, S(","));
		Logger::getInstance()->log(Logger::INFO, static_cast<int>(header->getLoopEndFrame()));
		Logger::getInstance()->log(Logger::INFO, S(","));
		Logger::getInstance()->log(Logger::INFO, static_cast<int>(header->getLoopCount()));
		Logger::getInstance()->logln(Logger::INFO, S("]"));

		Logger::getInstance()->log(Logger::INFO, S("\t\t}"));

		if (header->useJump()){
			Logger::getInstance()->log(Logger::INFO, S(","));

		}
		Logger::getInstance()->logln(Logger::INFO, S(""));
	}

	if (header->useJump()){
		Logger::getInstance()->logln(Logger::INFO, S("\t\t{"));
		Logger::getInstance()->logln(Logger::INFO, S("\t\t\t\"func\": \"jump\","));
		Logger::getInstance()->log(Logger::INFO, S("\t\t\t\"args\": ["));
		Logger::getInstance()->log(Logger::INFO, static_cast<int>(header->getJumpPosition()));
		Logger::getInstance()->logln(Logger::INFO, S("]"));
		Logger::getInstance()->logln(Logger::INFO, S("\t\t}"));
	}

	Logger::getInstance()->logln(Logger::INFO, S("\t],"));
}

int HeaderController::getMotionPosition(int headerPosition){
	int motionSize = sizeof(*((new Header())->getHeaderMemory())) + FRAME_NUMBER_MAX*sizeof(*((new Frame())->getFrameMemory()));
	return motionSize*(headerPosition);
}
