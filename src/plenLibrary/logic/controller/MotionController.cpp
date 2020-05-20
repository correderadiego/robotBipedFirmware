/*
 * MotionController.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#include <logic/controller/MotionController.h>

MotionController::MotionController(ExternalFileSystemController* externalFileSystemController) {
	this->externalFileSystemController = externalFileSystemController;
}

MotionController::MotionControllerErrors MotionController::set(Plen* plen, Header* header){
	if 	((header->getMotionFrameLength() < FRAME_NUMBER_MIN) ||
		 (header->getMotionFrameLength() > FRAME_NUMBER_MAX)){
		Logger::getInstance()->logln(Logger::ERROR, S("Header frame size error"));
		return HEADER_FRAME_SIZE_ERROR;
	}

	if (header->getPosition() >= MOVEMENT_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Header position error"));
		return HEADER_POSITION_ERROR;
	}

	if (writeHeader(plen, header) != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}

	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::get(Plen* plen, Header* header){
	if (header->getPosition() >= MOVEMENT_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Header position error"));
		return HEADER_POSITION_ERROR;
	}

	if (readHeader(plen, header) != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}

	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::set(Plen* plen, Frame* frame){
	if (frame->getHeaderPosition() >= MOVEMENT_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Header position error"));
		return HEADER_POSITION_ERROR;
	}

	if (frame->getFramePosition() >= FRAME_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Frame position error"));
		return HEADER_FRAME_SIZE_ERROR;
	}

	if (writeFrame(plen, frame) != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}
	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::get(Plen* plen, Frame* frame){
	if (frame->getHeaderPosition() >= MOVEMENT_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Header position error"));
		return HEADER_POSITION_ERROR;
	}

	if (frame->getFramePosition() >= FRAME_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Frame position error"));
		return HEADER_FRAME_SIZE_ERROR;
	}

	if (readFrame(plen, frame) != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}
	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::dumpMotion(
		Plen* plen, int headerPosition){

	Header* header = new Header();
	header->setPosition(headerPosition);
	this->get(plen, header);
	dumpHeader(header);

	Frame* frame = new Frame();
	frame->setHeaderPosition(headerPosition);

	Logger::getInstance()->logln(Logger::INFO, S("\t\"frames\": ["));

	for(unsigned int framePosition = 0; framePosition < header->getMotionFrameLength(); framePosition++){
		if (framePosition >= FRAME_NUMBER_MAX){
			delete header;
			delete frame;
			return HEADER_FRAME_SIZE_ERROR;
		}
		frame->setFramePosition(framePosition);
		this->get(plen, frame);
		dumpFrame(frame);

		if((framePosition+1) == header->getMotionFrameLength()){
			Logger::getInstance()->logln(Logger::INFO, "");
		}else{
			Logger::getInstance()->logln(Logger::INFO, S(","));
		}
	}

	Logger::getInstance()->logln(Logger::INFO, S("\t]"));
	Logger::getInstance()->logln(Logger::INFO, S("}"));
	delete header;
	delete frame;
	return NO_ERROR;
}

void MotionController::dumpHeader(Header* header){
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
		Logger::getInstance()->log(Logger::INFO, static_cast<int>(header->getJumpSlot()));
		Logger::getInstance()->logln(Logger::INFO, S("]"));
		Logger::getInstance()->logln(Logger::INFO, S("\t\t}"));
	}

	Logger::getInstance()->logln(Logger::INFO, S("\t],"));
}

void MotionController::dumpFrame(Frame* frame){
	Logger::getInstance()->log(Logger::INFO, S("\t\t{"));
	Logger::getInstance()->log(Logger::INFO, S("\t\t\"transition_time_ms\": "));
	Logger::getInstance()->log(Logger::INFO, static_cast<int>(frame->getTransitionTime()));
	Logger::getInstance()->logln(Logger::INFO, S(","));
	Logger::getInstance()->logln(Logger::INFO, S("\t\t\t\"outputs\": ["));

	for (int jointIndex = 0; jointIndex < NUMBER_OF_JOINTS; jointIndex++){
		Logger::getInstance()->logln(Logger::INFO, S("\t\t\t\t{"));
		Logger::getInstance()->log(Logger::INFO, S("\t\t\t\t\t\"device\": "));
		Logger::getInstance()->log(Logger::INFO, static_cast<int>(jointIndex));
		Logger::getInstance()->logln(Logger::INFO, S(","));

		Logger::getInstance()->log(Logger::INFO, S("\t\t\t\t\t\"value\": "));
		Logger::getInstance()->logln(Logger::INFO, static_cast<int>(frame->getJointAngle()[jointIndex]));
		Logger::getInstance()->log(Logger::INFO, S("\t\t\t\t}"));

		if ((jointIndex + 1) != NUMBER_OF_JOINTS){
			Logger::getInstance()->logln(Logger::INFO, S(","));
		}
	}

	Logger::getInstance()->logln(Logger::INFO, S("\t\t\t]"));
	Logger::getInstance()->log(Logger::INFO, S("\t\t}"));
}

ExternalFileSystemController::FileSystemErrors MotionController::writeHeader(Plen* plen, Header* header){
	unsigned char* filler = reinterpret_cast<unsigned char*>(header->getHeaderMemory());
	unsigned int sizeWrite = 0;

	return	this->externalFileSystemController->write(
													getMotionPosition(header->getPosition()),
													sizeof(*header->getHeaderMemory()),
													filler,
													&sizeWrite,
													plen->getFileMotion()
												);
}

ExternalFileSystemController::FileSystemErrors MotionController::readHeader(Plen* plen, Header* header){
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(header->getHeaderMemory());

	return	this->externalFileSystemController->read(
													getMotionPosition(header->getPosition()),
													sizeof(*header->getHeaderMemory()),
													filler,
													&sizeRead,
													plen->getFileMotion()
												);
}

ExternalFileSystemController::FileSystemErrors MotionController::writeFrame(Plen* plen, Frame* frame){
	unsigned int sizeWrite = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(frame->getFrameMemory());

	return this->externalFileSystemController->write(
														getFramePosition(frame->getHeaderPosition(), frame->getFramePosition()),
														sizeof(*frame->getFrameMemory()),
														filler,
														&sizeWrite,
														plen->getFileMotion()
													);
}

ExternalFileSystemController::FileSystemErrors MotionController::readFrame(Plen* plen, Frame* frame){
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(frame->getFrameMemory());

	return this->externalFileSystemController->read(
														getFramePosition(frame->getHeaderPosition(), frame->getFramePosition()),
														sizeof(*frame->getFrameMemory()),
														filler,
														&sizeRead,
														plen->getFileMotion()
													);
}

int MotionController::getMotionPosition(int headerPosition){
	int motionSize = sizeof(*((new Header())->getHeaderMemory())) + FRAME_NUMBER_MAX*sizeof(*((new Frame())->getFrameMemory()));
	return motionSize*(headerPosition);
}

int MotionController::getFramePosition(int headerPosition, int framePosition){
	int motionPosition = getMotionPosition(headerPosition);
	int headerSize	   = sizeof(*((new Header())->getHeaderMemory()));
	return  motionPosition + headerSize +
					   sizeof(*((new Frame())->getFrameMemory()))*framePosition;
}
