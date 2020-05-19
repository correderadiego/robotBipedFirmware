/*
 * Frame.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/motion/Frame.h>

Frame::Frame(
		unsigned int headerPosition,
		unsigned int frameIndex,
		unsigned int transitionTime
		) {
	this->frameMemory->headerPosition	 = headerPosition;
	this->frameMemory->frameIndex	 	 = frameIndex;
	this->frameMemory->transitionTime	 = transitionTime;
}

Frame::Frame() {
	this->frameMemory->headerPosition	 = 0;
	this->frameMemory->frameIndex	 	 = 0;
	this->frameMemory->transitionTime	 = 0;
}

Frame::FrameMemory* Frame::getFrameMemory(){
	return this->frameMemory;
}

unsigned int Frame::getHeaderPosition(){
	return this->frameMemory->headerPosition;
}

unsigned int Frame::getFrameIndex(){
	return this->frameMemory->frameIndex;
}

unsigned int Frame::getTransitionTime(){
	return this->frameMemory->transitionTime;
}

int* Frame::getJointAngle(){
	return this->frameMemory->jointAngle;
}

void Frame::setHeaderPosition(unsigned int slot){
	this->frameMemory->headerPosition = slot;
}

void Frame::setFrameIndex(unsigned int frameIndex){
	this->frameMemory->frameIndex = frameIndex;
}

void Frame::setTransitionTime(unsigned int transitionTime){
	this->frameMemory->transitionTime = transitionTime;
}
