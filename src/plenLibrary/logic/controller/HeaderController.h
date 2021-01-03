/*
 * HeaderController.h
 *
 *  Created on: 5 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_CONTROLLER_HEADERCONTROLLER_H_
#define SRC_CONTROLLER_HEADERCONTROLLER_H_

#include <logic/bean/motion/Header.h>
#include "utils/Logger.h"
#include <hardware/controller/ExternalFileSystemController.h>

class HeaderController {
public:
	enum HeaderControllerErrors{
		NO_ERROR,
		HEADER_FRAME_SIZE_ERROR,
		HEADER_POSITION_ERROR,
		WRITE_ERROR,
		READ_ERROR
	};

	HeaderController(ExternalFileSystemController* externalFileSystemController);
	virtual HeaderControllerErrors set(File* fileMotion, Header* header);
	virtual HeaderControllerErrors get(File* fileMotion, Header* header);
	virtual void dumpHeader(Header* header);
	virtual ~HeaderController() {};

private:
	ExternalFileSystemController::FileSystemErrors read(File* fileMotion, Header* header);
	ExternalFileSystemController::FileSystemErrors write(File* fileMotion, Header* header);
	int getMotionPosition(int headerPosition);

	ExternalFileSystemController* externalFileSystemController;
};

#endif /* SRC_CONTROLLER_HEADERCONTROLLER_H_ */
