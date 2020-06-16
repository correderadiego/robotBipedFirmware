/*
 * Motion.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/motion/Motion.h>

Motion::Motion(Header* header, Frame** frameVector){
	this->frameVector 				= frameVector;
	this->header 					= header;
	this->frameExecutingPosition 	= header->getLoopBeginFrame();
	this->loopExecutingPosition 	= 0;
}

void Motion::setHeader(Header* header){
	this->header = header;
}

Header* Motion::getHeader(){
	return header;
}

Frame** Motion::getFrameVector(){
	return this->frameVector;
}

void Motion::setFrameVector(Frame** frameVector){
	this->frameVector = frameVector;
}

void Motion::setFrameExecutingPosition(unsigned int frameExecutingPosition){
	this->frameExecutingPosition = frameExecutingPosition;
}
unsigned int Motion::getFrameExecutingPosition(){
	return this->frameExecutingPosition;
}
void Motion::setLoopExecutingPosition(unsigned int loopExecutingPosition){
	this->loopExecutingPosition = loopExecutingPosition;
}
unsigned int Motion::getLoopExecutingPosition(){
	return this->loopExecutingPosition;
}

Motion::~Motion(){
	delete header;
	delete frameVector;
}
