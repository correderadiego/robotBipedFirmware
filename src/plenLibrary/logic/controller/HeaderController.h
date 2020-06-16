/*
 * HeaderController.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
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
	HeaderControllerErrors set(File* fileMotion, Header* header);
	HeaderControllerErrors get(File* fileMotion, Header* header);
	void dumpHeader(Header* header);

private:
	ExternalFileSystemController::FileSystemErrors read(File* fileMotion, Header* header);
	ExternalFileSystemController::FileSystemErrors write(File* fileMotion, Header* header);
	int getMotionPosition(int headerPosition);

	ExternalFileSystemController* externalFileSystemController;
};

#endif /* SRC_CONTROLLER_HEADERCONTROLLER_H_ */
