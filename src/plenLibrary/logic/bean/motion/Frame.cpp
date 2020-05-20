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
	this->frameMemory->framePosition	 	 = frameIndex;
	this->frameMemory->transitionTime	 = transitionTime;
}

Frame::Frame() {
	this->frameMemory->headerPosition	 = 0;
	this->frameMemory->framePosition	 	 = 0;
	this->frameMemory->transitionTime	 = 0;
}

Frame::FrameMemory* Frame::getFrameMemory(){
	return this->frameMemory;
}

unsigned int Frame::getHeaderPosition(){
	return this->frameMemory->headerPosition;
}

unsigned int Frame::getFramePosition(){
	return this->frameMemory->framePosition;
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

void Frame::setFramePosition(unsigned int framePosition){
	this->frameMemory->framePosition = framePosition;
}

void Frame::setTransitionTime(unsigned int transitionTime){
	this->frameMemory->transitionTime = transitionTime;
}
