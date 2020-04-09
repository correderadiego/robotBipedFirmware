/*
 * HeaderController.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_HEADERCONTROLLER_H_
#define SRC_CONTROLLER_HEADERCONTROLLER_H_

#include "logic/bean/motion/Header.h"

class HeaderController {
public:
	enum HeaderControllerErrors{
		NO_ERROR,
		SLOT_SIZE_ERROR,
		FRAME_LENGTH_ERROR
	};

	HeaderController();
	HeaderControllerErrors write(Header* header);
	HeaderControllerErrors read (Header header);

private:
	int getHeaderSlotSize(Header* header);
};

#endif /* SRC_CONTROLLER_HEADERCONTROLLER_H_ */
