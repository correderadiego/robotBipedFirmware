/*
 * Header.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/motion/Header.h>

Header::Header() {
	this->headerMemory->motionName[0]		= '\0';
	this->headerMemory->motionName[HEADER_MOTION_NAME_SIZE +1]		= '\0';
	this->headerMemory->position 			= 0;
	this->headerMemory->motionFrameLenght 	= 0;
	this->headerMemory->loopBeginFrame 		= 0;
	this->headerMemory->loopEndFrame 		= 0;
	this->headerMemory->loopCount 			= 0;
	this->headerMemory->jumpSlot 			= 0;
	this->headerMemory->extra 				= false;
	this->headerMemory->jump 				= false;
	this->headerMemory->loop 				= false;
}

Header::Header(
		char* motionName,
		unsigned int position,
		unsigned int motionFrameLength,
		unsigned int loopBeginFrame,
		unsigned int loopEndFrame,
		unsigned int loopCount,
		unsigned int jumpSlot,
		bool extra,
		bool jump,
		bool loop) {
	strcpy(this->headerMemory->motionName, motionName);
	this->headerMemory->motionName[HEADER_MOTION_NAME_SIZE +1]		= '\0';
	this->headerMemory->position 			= position;
	this->headerMemory->motionFrameLenght 	= motionFrameLength;
	this->headerMemory->loopBeginFrame 		= loopBeginFrame;
	this->headerMemory->loopEndFrame 		= loopEndFrame;
	this->headerMemory->loopCount 			= loopCount;
	this->headerMemory->jumpSlot 			= jumpSlot;
	this->headerMemory->extra 				= extra;
	this->headerMemory->jump 				= jump;
	this->headerMemory->loop 				= loop;
}

Header::HeaderMemory* Header::getHeaderMemory(){
	return this->headerMemory;
}

char* Header::getMotionName(){
	return this->headerMemory->motionName;
}

unsigned int Header::getPosition(){
	return this->headerMemory->position;
}

unsigned int Header::getMotionFrameLength(){
	return this->headerMemory->motionFrameLenght;
}

unsigned int Header::getLoopBeginFrame(){
	return this->headerMemory->loopBeginFrame;
}

unsigned int Header::getLoopEndFrame(){
	return this->headerMemory->loopEndFrame;
}

unsigned int Header::getLoopCount(){
	return this->headerMemory->loopCount;
}

unsigned int Header::getJumpSlot(){
	return this->headerMemory->jumpSlot;
}

bool Header::useExtra(){
	return this->headerMemory->extra;
}

bool Header::useJump(){
	return this->headerMemory->jump;
}

bool Header::useLoop(){
	return this->headerMemory->loop;
}

void  Header::setMotionName(char* motionName){
	strcpy(this->headerMemory->motionName, motionName);
}
void Header::setPosition(unsigned int position){
	this->headerMemory->position = position;
}

void Header::setMotionFrameLength(unsigned int motionFrameLenght){
	this->headerMemory->motionFrameLenght = motionFrameLenght;
}

void Header::setLoopBeginFrame(unsigned int loopBeginFrame){
	this->headerMemory->loopBeginFrame = loopBeginFrame;
}

void Header::setLoopEndFrame(unsigned int loopEndFrame){
	this->headerMemory->loopEndFrame = loopEndFrame;
}

void Header::setLoopCount(unsigned int loopCount){
	this->headerMemory->loopCount = loopCount;
}

void Header::setJumpSlot(unsigned int jumpSlot){
	this->headerMemory->jumpSlot = jumpSlot;
}

void Header::setExtra(bool extra){
	this->headerMemory->extra = extra;
}

void Header::setJump(bool jump){
	this->headerMemory->jump = jump;
}

void Header::setLoop(bool loop){
	this->headerMemory->loop = loop;
}
