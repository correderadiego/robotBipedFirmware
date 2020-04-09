/*
 * HeaderController.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/HeaderController.h>

HeaderController::HeaderController() {}

int HeaderController::getHeaderSlotSize(Header* header){
	int sizeHeader = sizeof(Header) / 32;

	if(sizeof(Header) % 32 > 0){
		sizeHeader = sizeHeader + 1;
	}
	return sizeHeader;
}

HeaderController::HeaderControllerErrors HeaderController::write(Header* header){
//	if(slot >= SLOT_END){
//		return SLOT_SIZE_ERROR;
//	}
//
//	if((motionFrameLenght < FRAME_LENGTH_MIN) ||
//	   (motionFrameLenght > FRAME_LENGTH_MAX)){
//		return FRAME_LENGTH_ERROR;
//	}
//
//	const unsigned char* filler = reinterpret_cast<const unsigned char*>(header);

	return NO_ERROR;
}


HeaderController::HeaderControllerErrors HeaderController::read(Header header){
	return NO_ERROR;
}
