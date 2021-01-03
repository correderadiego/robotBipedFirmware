/*
 * MotionController.cpp
 *
 *  Created on: 26 mar. 2020
 *      Author: Diego
 */

#include <logic/controller/MotionController.h>

MotionController::MotionController(
		HeaderController* headerController,
		FrameController* frameController,
		ExternalFileSystemController* externalFileSystemController,
		JointController* jointController) {
	this->headerController				= headerController;
	this->frameController				= frameController;
	this->externalFileSystemController	= externalFileSystemController;
	this->jointController 				= jointController;
	this->setExecutionDelayMilliSeconds(MOTION_CONTROLLER_DEFAULT_EXECUTION_DELAY);
}

HeaderController::HeaderControllerErrors MotionController::setHeader(File* fileMotion, Header* header){
	return this->headerController->set(fileMotion, header);
}

FrameController::FrameControllerErrors MotionController::setFrame(File* fileMotion, Frame* frame){
	return this->frameController->set(fileMotion, frame);
}

void MotionController::executeThreadTasks(Plen* plen){
	if(executeTask()){
		this->executeMotion(plen->getMotion(), plen->getJointVector(), plen->getJointSize(), plen->getFileMotion());
	}
}

void MotionController::executeMotion(Motion* motion, Joint** jointVector, int jointSize, File* fileMotion){
	if(motion == nullptr){
		return;
	}

	if(framesToExecute(motion)){
		updateFrameExecutingPosition(motion);
		updatePlenJoint(motion, jointVector, jointSize);
		jointController->updateJointPosition(jointVector, jointSize);
		this->setExecutionDelayMilliSeconds(
				motion->getFrameVector()[motion->getFrameExecutingPosition()]->getTransitionTime()
			);
		return;
	}

	if(motion->getHeader()->useJump()){
		this->getMotion(fileMotion, motion->getHeader()->getJumpPosition(), motion);
	}
}

bool MotionController::framesToExecute(Motion* motion){
	if(motion->getFrameExecutingPosition() < motion->getHeader()->getMotionFrameLength()){
		return true;
	}

	if(motion->getLoopExecutingPosition() < motion->getHeader()->getLoopCount()){
		return true;
	}

	return false;
}

void MotionController::updateFrameExecutingPosition(Motion* motion){
	if(motion->getHeader()->useLoop()){
		updateLoopFrameExecutingPosition(motion);
	}

	if(motion->getFrameExecutingPosition() < motion->getHeader()->getMotionFrameLength()){
		motion->setFrameExecutingPosition(motion->getFrameExecutingPosition() + 1);
		return;
	}
}

void MotionController::updatePlenJoint(Motion* motion, Joint** jointVector, int jointSize){
	for (int i = 0; i < jointSize; i++){
		(jointVector[i])->setAngle(
				motion->getFrameVector()[motion->getFrameExecutingPosition()]->getJointAngle()[i]
				);
	};
}

void MotionController::updateLoopFrameExecutingPosition(Motion* motion){
	if(motion->getFrameExecutingPosition() < motion->getHeader()->getLoopEndFrame()){
		motion->setFrameExecutingPosition(motion->getFrameExecutingPosition() + 1);
		return;
	}

	if(motion->getLoopExecutingPosition() < motion->getHeader()->getLoopCount()){
		motion->setFrameExecutingPosition(motion->getHeader()->getLoopBeginFrame());
		motion->setLoopExecutingPosition(motion->getLoopExecutingPosition() + 1);
		return;
	}
	return;
}

MotionController::MotionControllerErrors MotionController::getMotion(File* fileMotion, unsigned int motionPosition, Motion* motion){
	Header* header = new Header();
	header->setPosition(motionPosition);
	if (headerController->get(fileMotion, header) != HeaderController::HeaderControllerErrors::NO_ERROR){
		delete header;
		return LOAD_MOTION_ERROR;
	}
	Frame* frameVector[FRAME_NUMBER_MAX] = {};

	for(unsigned int framePosition = 0; framePosition < header->getMotionFrameLength(); framePosition++){
		Frame* frame = new Frame();
		frame->setHeaderPosition(motionPosition);
		frame->setFramePosition(framePosition);

		if (frameController->get(fileMotion, frame) != FrameController::FrameControllerErrors::NO_ERROR){
			delete header;
			delete frame;
			return LOAD_MOTION_ERROR;
		}

		frameController->get(fileMotion, frame);
		frameVector[framePosition] = frame;
	}

	motion->setHeader(header);
	motion->setFrameVector(frameVector);
	return NO_ERROR;
}

MotionController::MotionControllerErrors MotionController::dumpMotion(
		File* fileMotion, int headerPosition){
	Header* header = new Header();
	header->setPosition(headerPosition);
	headerController->get(fileMotion, header);
	headerController->dumpHeader(header);

	Logger::getInstance()->logln(Logger::INFO, S("\t\"frames\": ["));

	for(unsigned int framePosition = 0; framePosition < header->getMotionFrameLength(); framePosition++){
		Frame* frame = new Frame();
		frame->setHeaderPosition(headerPosition);
		if (framePosition >= FRAME_NUMBER_MAX){
			delete header;
			delete frame;
			return HEADER_FRAME_SIZE_ERROR;
		}
		frame->setFramePosition(framePosition);
		frameController->get(fileMotion, frame);
		frameController->dumpFrame(frame);

		if((framePosition+1) == header->getMotionFrameLength()){
			Logger::getInstance()->logln(Logger::INFO, "");
		}else{
			Logger::getInstance()->logln(Logger::INFO, S(","));
		}
		delete frame;
	}

	Logger::getInstance()->logln(Logger::INFO, S("\t]"));
	Logger::getInstance()->logln(Logger::INFO, S("}"));
	delete header;
	return NO_ERROR;
}
