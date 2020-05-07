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

MotionController::MotionControllerErrors MotionController::set(Header* header, File* file){
	if 	((header->getMotionFrameLength() < FRAME_NUMBER_MIN) ||
		 (header->getMotionFrameLength() > FRAME_NUMBER_MAX)){
		return FRAME_SIZE_ERROR;
	}

	if (header->getPosition() >= FILE_SLOT_NUMBERS){
		 return SLOT_SIZE_ERROR;
	}

	const unsigned char* filler = reinterpret_cast<const unsigned char*>(header);

	for (int i = 0; i < SIZE_HEADER_IN_SLOTS; i++){
		ExternalFileSystemController:: FileSystemErrors fileSystemError =
				this->externalFileSystemController->writeSlot(
				static_cast<int>(header->getPosition()) * SIZE_MOTION_IN_SLOTS + i,
				filler + i * SLOT_SIZE_BYTES,
				getBytesToWriteRead(i, SIZE_HEADER_IN_SLOTS, sizeof(Header)),
				file
				);
		if( fileSystemError != ExternalFileSystemController::NO_ERROR){
			return WRITE_ERROR;
		}
	}

	return NO_ERROR;
}

int MotionController::getBytesToWriteRead(int index, int maxIndex, int objectSize){
	if(index == maxIndex - 1){
		return objectSize % SLOT_SIZE_BYTES;
	}
	return SLOT_SIZE_BYTES;
}

int MotionController::getReadWriteHeaderPositionInSlots(Header* header, int readWriteFragment){
	return
			static_cast<int>(header->getPosition()) * SIZE_MOTION_IN_SLOTS + readWriteFragment;
}

int MotionController::getReadWriteFrameSlotPosition(Frame* frame, int readWriteFragment){
	return
			static_cast<int>(frame->getSlot()) * SIZE_MOTION_IN_SLOTS +
				SIZE_HEADER_IN_SLOTS +
				frame->getFrameIndex() * SIZE_FRAME_IN_SLOTS +
				readWriteFragment;
}

MotionController::MotionControllerErrors MotionController::get(Header* header, File* file){

	if (header->getPosition() >= FILE_SLOT_NUMBERS){
		 return SLOT_SIZE_ERROR;
	}

	unsigned char* filler = reinterpret_cast<unsigned char*>(header);

	for (int i = 0; i < SIZE_HEADER_IN_SLOTS; i++){
		ExternalFileSystemController:: FileSystemErrors fileSystemError =
				this->externalFileSystemController->readSlot(
					getReadWriteHeaderPositionInSlots(header, i),
					filler + i * SLOT_SIZE_BYTES,
					getBytesToWriteRead(i, SIZE_HEADER_IN_SLOTS, sizeof(Header)),
					file
				);
		if( fileSystemError != ExternalFileSystemController::NO_ERROR){
				return READ_ERROR;
		}
	}
	return NO_ERROR;
}


MotionController::MotionControllerErrors MotionController::set(Frame* frame, File* file){
	if (frame->getSlot() >= FILE_SLOT_NUMBERS){
		 return SLOT_SIZE_ERROR;
	}

	if (frame->getFrameIndex() >= FRAME_NUMBER_MAX)
	{
		return FRAME_SIZE_ERROR;
	}

	const unsigned char* filler = reinterpret_cast<const unsigned char*>(frame);

	for (int i = 0; i < SIZE_FRAME_IN_SLOTS; i++){
		ExternalFileSystemController:: FileSystemErrors fileSystemError =
				this->externalFileSystemController->readSlot(
				getReadWriteFrameSlotPosition(frame, i),
				(unsigned char*)(filler + i * SLOT_SIZE_BYTES),
				getBytesToWriteRead(i, SIZE_FRAME_IN_SLOTS, sizeof(Frame)),
				file
				);
		if( fileSystemError != ExternalFileSystemController::NO_ERROR){
				return READ_ERROR;
		}
	}
	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::get(Frame* frame, File* file){
	if (frame->getSlot() >= FILE_SLOT_NUMBERS){
		 return SLOT_SIZE_ERROR;
	}

	if (frame->getFrameIndex() >= FRAME_NUMBER_MAX)
	{
		return FRAME_SIZE_ERROR;
	}

	const unsigned char* filler = reinterpret_cast<const unsigned char*>(frame);

	for (int i = 0; i < SIZE_FRAME_IN_SLOTS; i++){
		ExternalFileSystemController:: FileSystemErrors fileSystemError =
				this->externalFileSystemController->readSlot(
				getReadWriteFrameSlotPosition(frame, i),
				(unsigned char*)(filler + i * SLOT_SIZE_BYTES),
				getBytesToWriteRead(i, SIZE_FRAME_IN_SLOTS, sizeof(Frame)),
				file
				);
		if( fileSystemError != ExternalFileSystemController::NO_ERROR){
				return READ_ERROR;
		}
	}
	return NO_ERROR;
}
