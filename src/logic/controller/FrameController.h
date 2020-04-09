/*
 * FrameController.h
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#ifndef SRC_CONTROLLER_FRAMECONTROLLER_H_
#define SRC_CONTROLLER_FRAMECONTROLLER_H_

#include "logic/bean/motion/Frame.h"

class FrameController {
public:
	enum FrameControllerErrors{
		NO_ERROR,
		SLOT_SIZE_ERROR,
		FRAME_LENGTH_ERROR
	};
	FrameController();
	FrameControllerErrors write(Frame* frame);
	FrameControllerErrors read (Frame frame);
};

#endif /* SRC_CONTROLLER_FRAMECONTROLLER_H_ */
