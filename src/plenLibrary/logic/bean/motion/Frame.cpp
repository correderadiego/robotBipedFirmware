/*
 * Frame.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/motion/Frame.h>

Frame::Frame(
		unsigned int slot,
		unsigned int frameIndex,
		unsigned int transitionTime,
		int*         jointAngle,
		int 		 numberOfJoints) {
	this->slot				 = slot;
	this->frameIndex	 	 = frameIndex;
	this->transitionTime	 = transitionTime;
	this->jointAngle	     = jointAngle;
	this->numberOfJoints	 = numberOfJoints;
}

Frame::Frame() {
	this->slot				 = 0;
	this->frameIndex	 	 = 0;
	this->transitionTime	 = 0;
	this->jointAngle	     = nullptr;
	this->numberOfJoints	 = NUMBER_OF_JOINTS;
}

unsigned int Frame::getSlot(){
	return this->slot;
}

unsigned int Frame::getFrameIndex(){
	return this->frameIndex;
}

unsigned int Frame::getTransitionTime(){
	return this->transitionTime;
}

int* Frame::getJointAngle(){
	return this->jointAngle;
}

void Frame::setSlot(unsigned int slot){
	this->slot = slot;
}

void Frame::setFrameIndex(unsigned int frameIndex){
	this->frameIndex = frameIndex;
}

void Frame::setTransitionTime(unsigned int transitionTime){
	this->transitionTime = transitionTime;
}

void Frame::setJointAngle(int* jointAngle){
	this->jointAngle = jointAngle;
}
