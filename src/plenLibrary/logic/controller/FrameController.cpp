/*
 * FrameController.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/controller/FrameController.h>

FrameController::FrameController(ExternalFileSystemController* externalFileSystemController) {
	this->externalFileSystemController = externalFileSystemController;
}

int FrameController::getPosition(int headerPosition, int framePosition){
	int motionPosition = getMotionPosition(headerPosition);
	int headerSize	   = sizeof(*((new Header())->getHeaderMemory()));
	return  motionPosition + headerSize +
					   sizeof(*((new Frame())->getFrameMemory()))*framePosition;
}

ExternalFileSystemController::FileSystemErrors FrameController::read(File* fileMotion, Frame* frame){
	int sizeRead = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(frame->getFrameMemory());
	return this->externalFileSystemController->read(
														getPosition(frame->getHeaderPosition(), frame->getFramePosition()),
														sizeof(*frame->getFrameMemory()),
														filler,
														&sizeRead,
														fileMotion
													);
}

ExternalFileSystemController::FileSystemErrors FrameController::write(File* fileMotion, Frame* frame){
	unsigned int sizeWrite = 0;
	unsigned char* filler = reinterpret_cast<unsigned char*>(frame->getFrameMemory());

	return this->externalFileSystemController->write(
														getPosition(frame->getHeaderPosition(), frame->getFramePosition()),
														sizeof(*frame->getFrameMemory()),
														filler,
														&sizeWrite,
														fileMotion
													);
}

void FrameController::dumpFrame(Frame* frame){
	Logger::getInstance()->log(Logger::INFO, S("\t\t{"));
	Logger::getInstance()->log(Logger::INFO, S("\t\t\"transition_time_ms\": "));
	Logger::getInstance()->log(Logger::INFO, static_cast<int>(frame->getTransitionTime()));
	Logger::getInstance()->logln(Logger::INFO, S(","));
	Logger::getInstance()->logln(Logger::INFO, S("\t\t\t\"outputs\": ["));

	for (int jointIndex = 0; jointIndex < NUMBER_OF_JOINTS; jointIndex++){
		Logger::getInstance()->logln(Logger::INFO, S("\t\t\t\t{"));
		Logger::getInstance()->log(Logger::INFO, S("\t\t\t\t\t\"device\": "));
		Logger::getInstance()->log(Logger::INFO, static_cast<int>(jointIndex));
		Logger::getInstance()->logln(Logger::INFO, S(","));

		Logger::getInstance()->log(Logger::INFO, S("\t\t\t\t\t\"value\": "));
		Logger::getInstance()->logln(Logger::INFO, static_cast<int>(frame->getJointAngle()[jointIndex]));
		Logger::getInstance()->log(Logger::INFO, S("\t\t\t\t}"));

		if ((jointIndex + 1) != NUMBER_OF_JOINTS){
			Logger::getInstance()->logln(Logger::INFO, S(","));
		}
	}

	Logger::getInstance()->logln(Logger::INFO, S("\t\t\t]"));
	Logger::getInstance()->log(Logger::INFO, S("\t\t}"));
}

FrameController::FrameControllerErrors FrameController::get(File* fileMotion, Frame* frame){
	if (frame->getHeaderPosition() >= MOVEMENT_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Header position error"));
		return HEADER_POSITION_ERROR;
	}

	if (frame->getFramePosition() >= FRAME_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Frame position error"));
		return HEADER_FRAME_SIZE_ERROR;
	}

	if (read(fileMotion, frame) != ExternalFileSystemController::NO_ERROR){
		return READ_ERROR;
	}
	return NO_ERROR;
}

FrameController::FrameControllerErrors FrameController::set(File* fileMotion, Frame* frame){
	if (frame->getHeaderPosition() >= MOVEMENT_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Header position error"));
		return HEADER_POSITION_ERROR;
	}

	if (frame->getFramePosition() >= FRAME_NUMBER_MAX){
		Logger::getInstance()->logln(Logger::ERROR, S("Frame position error"));
		return HEADER_FRAME_SIZE_ERROR;
	}

	if (write(fileMotion, frame) != ExternalFileSystemController::NO_ERROR){
		return WRITE_ERROR;
	}
	return NO_ERROR;
}

int FrameController::getMotionPosition(int headerPosition){
	int motionSize = sizeof(*((new Header())->getHeaderMemory())) + FRAME_NUMBER_MAX*sizeof(*((new Frame())->getFrameMemory()));
	return motionSize*(headerPosition);
}
