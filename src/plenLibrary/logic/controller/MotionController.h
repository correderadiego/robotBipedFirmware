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
#include "logic/controller/JointController.h"
#include "utils/Logger.h"
#include "hardware/controller/RunnableController.h"
#include "HeaderController.h"
#include "FrameController.h"

#define MOTION_CONTROLLER_DEFAULT_EXECUTION_DELAY	1

class MotionController  : public RunnableController {
public:
	enum MotionControllerErrors{
	  NO_ERROR,
	  HEADER_POSITION_ERROR,
	  HEADER_FRAME_SIZE_ERROR,
	  WRITE_ERROR,
	  READ_HEADER_ERROR,
	  READ_ERROR,
	  LOAD_MOTION_ERROR
	};
	MotionController(
			HeaderController* headerController,
			FrameController* frameController,
			ExternalFileSystemController* externalFileSystemController,
			JointController* jointController);
	void executeThreadTasks(Plen* plen);

	MotionControllerErrors dumpMotion(File* fileMotion, int headerPosition);
	MotionControllerErrors getMotion(File* fileMotion, unsigned int motionPosition, Motion* motion);
	HeaderController::HeaderControllerErrors setHeader(File* fileMotion, Header* header);
	FrameController::FrameControllerErrors setFrame(File* fileMotion, Frame* frame);

private:
	ExternalFileSystemController* externalFileSystemController;
	JointController* jointController;
	HeaderController* headerController;
	FrameController* frameController;

	void executeMotion(Motion* motion, Joint** jointVector, int jointSize, File* fileMotion);
	bool framesToExecute(Motion* motion);
	void updateFrameExecutingPosition(Motion* motion);
	void updateLoopFrameExecutingPosition(Motion* motion);
	void updatePlenJoint(Motion* motion, Joint** jointVector, int jointSize);
};

#endif /* SRC_CONTROLLER_MOTIONCONTROLLER_H_ */
