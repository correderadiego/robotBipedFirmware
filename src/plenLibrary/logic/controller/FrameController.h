/*
 * FrameController.h
 *
 *  Created on: 5 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_CONTROLLER_FRAMECONTROLLER_H_
#define SRC_CONTROLLER_FRAMECONTROLLER_H_

#include <logic/bean/motion/Frame.h>
#include "logic/bean/motion/Header.h"
#include "utils/Logger.h"
#include <hardware/controller/ExternalFileSystemController.h>

class FrameController {
public:
	enum FrameControllerErrors{
		NO_ERROR,
		HEADER_POSITION_ERROR,
		HEADER_FRAME_SIZE_ERROR,
		READ_ERROR,
		WRITE_ERROR
	};
	FrameController(ExternalFileSystemController* externalFileSystemController);
	virtual int getPosition(int header, int framePosition);
	virtual FrameControllerErrors get(File* fileMotion, Frame* frame);
	virtual FrameControllerErrors set(File* fileMotion, Frame* frame);
	virtual void dumpFrame(Frame* frame);
	virtual ~FrameController() {};
private:
	ExternalFileSystemController* externalFileSystemController;
	ExternalFileSystemController::FileSystemErrors write(File* fileMotion, Frame* frame);
	ExternalFileSystemController::FileSystemErrors read (File* fileMotion, Frame* frame);
	int getMotionPosition(int headerPosition);
};

#endif /* SRC_CONTROLLER_FRAMECONTROLLER_H_ */
