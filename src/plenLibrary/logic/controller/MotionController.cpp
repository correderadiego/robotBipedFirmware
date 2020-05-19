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
		return HEADER_FRAME_SIZE_ERROR;
	}

	if (header->getPosition() >= MOVEMENT_NUMBER_MAX){
		 return HEADER_POSITION_ERROR;
	}

	unsigned char* filler = reinterpret_cast<unsigned char*>(header->getHeaderMemory());

	unsigned int sizeWrite = 0;
	int motionSize = sizeof(*((new Header())->getHeaderMemory())) + FRAME_NUMBER_MAX*sizeof(*((new Frame())->getFrameMemory()));
	int position = motionSize*(header->getPosition());

	ExternalFileSystemController:: FileSystemErrors fileSystemError =
			this->externalFileSystemController->write(
														position,
														sizeof(*header->getHeaderMemory()),
														filler,
														&sizeWrite,
														plen->getFileMotion()
													);
	if( fileSystemError != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}

	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::get(Plen* plen, Header* header){
	if (header->getPosition() >= MOVEMENT_NUMBER_MAX){
		 return HEADER_POSITION_ERROR;
	}

	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(header->getHeaderMemory());

	int motionSize = sizeof(*((new Header())->getHeaderMemory())) + FRAME_NUMBER_MAX*sizeof(*((new Frame())->getFrameMemory()));
	unsigned int position = motionSize*(header->getPosition());

	ExternalFileSystemController:: FileSystemErrors fileSystemError =
		this->externalFileSystemController->read(
													position,
													sizeof(*header->getHeaderMemory()),
													filler,
													&sizeRead,
													plen->getFileMotion()
												);
	if( fileSystemError != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}

	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::set(Plen* plen, Frame* frame){
	if (frame->getHeaderPosition() >= FILE_SLOT_NUMBERS){
		 return HEADER_POSITION_ERROR;
	}

	if (frame->getFrameIndex() >= FRAME_NUMBER_MAX)
	{
		return HEADER_FRAME_SIZE_ERROR;
	}

	//const unsigned char* filler = reinterpret_cast<const unsigned char*>(frame->getFrameMemory());

//	for (int i = 0; i < SIZE_FRAME_IN_SLOTS; i++){
//		ExternalFileSystemController:: FileSystemErrors fileSystemError =
//				this->externalFileSystemController->writeSlot(
//				getReadWriteFrameSlotPosition(frame, i),
//				(unsigned char*)(filler + i * SLOT_SIZE_BYTES),
//				getBytesToWriteRead(i, SIZE_FRAME_IN_SLOTS, sizeof(Frame)),
//				plen->getFileMotion()
//				);
//		if( fileSystemError != ExternalFileSystemController::NO_ERROR){
//				return READ_ERROR;
//		}
//	}

	unsigned int sizeWrite = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(frame->getFrameMemory());

	int position = sizeof(*((new Header())->getHeaderMemory()))*frame->getHeaderPosition() +
				   sizeof(*((new Frame())->getFrameMemory()))*frame->getFrameIndex();
	ExternalFileSystemController:: FileSystemErrors fileSystemError =
			this->externalFileSystemController->write(
														position,
														sizeof(*frame->getFrameMemory()),
														filler,
														&sizeWrite,
														plen->getFileMotion()
													);
	if( fileSystemError != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}
	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::get(Plen* plen, Frame* frame){
	if (frame->getHeaderPosition() >= FILE_SLOT_NUMBERS){
		 return HEADER_POSITION_ERROR;
	}

	if (frame->getFrameIndex() >= FRAME_NUMBER_MAX)
	{
		return HEADER_FRAME_SIZE_ERROR;
	}
//
//	const unsigned char* filler = reinterpret_cast<const unsigned char*>(frame);
//
//	for (int i = 0; i < SIZE_FRAME_IN_SLOTS; i++){
//		ExternalFileSystemController:: FileSystemErrors fileSystemError =
//				this->externalFileSystemController->readSlot(
//				getReadWriteFrameSlotPosition(frame, i),
//				(unsigned char*)(filler + i * SLOT_SIZE_BYTES),
//				getBytesToWriteRead(i, SIZE_FRAME_IN_SLOTS, sizeof(Frame)),
//				plen->getFileMotion()
//				);
//		if( fileSystemError != ExternalFileSystemController::NO_ERROR){
//				return READ_ERROR;
//		}
//	}
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(frame->getFrameMemory());

	int position = sizeof(*((new Header())->getHeaderMemory()))*frame->getHeaderPosition() +
				   sizeof(*((new Frame())->getFrameMemory()))*frame->getFrameIndex();
	ExternalFileSystemController:: FileSystemErrors fileSystemError =
			this->externalFileSystemController->read(
														position,
														sizeof(*frame->getFrameMemory()),
														filler,
														&sizeRead,
														plen->getFileMotion()
													);
	if( fileSystemError != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}
	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::dumpHeader(Plen* plen, int position){
	if(position>MOVEMENT_NUMBER_MAX){
		return HEADER_POSITION_ERROR;
	}

	Header* header = new Header();
	header->setPosition(position);
	this->get(plen, header);

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
	delete header;
	return NO_ERROR;
}

int MotionController::getReadWriteHeaderPositionInSlots(Header* header, int readWriteFragment){
	return
			static_cast<int>(header->getPosition()) * SIZE_MOTION_IN_SLOTS + readWriteFragment;
}

int MotionController::getReadWriteFrameSlotPosition(Frame* frame, int readWriteFragment){
	return
			static_cast<int>(frame->getHeaderPosition()) * SIZE_MOTION_IN_SLOTS +
				SIZE_HEADER_IN_SLOTS +
				frame->getFrameIndex() * SIZE_FRAME_IN_SLOTS +
				readWriteFragment;
}

int MotionController::getBytesToWriteRead(int index, int maxIndex, int objectSize){
	if(index == maxIndex - 1){
		return objectSize % SLOT_SIZE_BYTES;
	}
	return SLOT_SIZE_BYTES;
}
