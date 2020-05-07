/*
 * MotionController.h
 *
 *  Created on: 26 mar. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_MOTIONCONTROLLER_H_
#define SRC_CONTROLLER_MOTIONCONTROLLER_H_

#include "logic/bean/motion/Header.h"
#include "logic/bean/motion/Frame.h"
#include "Configuration.h"
#include <hardware/controller/ExternalFileSystemController.h>

#define sizeInSlots(object) sizeof(object)/EEPROM_SLOT_SIZE_BYTES + sizeof(object)%EEPROM_SLOT_SIZE_BYTES
#define SIZE_HEADER_IN_SLOTS sizeInSlots(Header)
#define	SIZE_FRAME_IN_SLOTS  sizeInSlots(Frame)
#define SIZE_MOTION_IN_SLOTS SIZE_HEADER_IN_SLOTS + SIZE_FRAME_IN_SLOTS*FRAME_NUMBER_MAX

class MotionController {
public:
	enum MotionControllerErrors{
	  NO_ERROR,
	  FRAME_SIZE_ERROR,
	  SLOT_SIZE_ERROR,
	  WRITE_ERROR,
	  READ_ERROR
	};
	MotionController(ExternalFileSystemController* externalFileSystemController);
	MotionControllerErrors set(Header* header, File* file);
	MotionControllerErrors get(Header* header, File* file);
	MotionControllerErrors set(Frame* frame, File* file);
	MotionControllerErrors get(Frame* frame, File* file);

private:
	ExternalFileSystemController* externalFileSystemController;
	int getBytesToWriteRead(int index, int maxIndex, int objectSize);
	int getReadWriteFrameSlotPosition(Frame* frame, int readWriteFragment);
	int getReadWriteHeaderPositionInSlots(Header* header, int readWriteFragment);
};

#endif /* SRC_CONTROLLER_MOTIONCONTROLLER_H_ */
