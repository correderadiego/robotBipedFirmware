/*
 * Header.cpp
 *
 *  Created on: 5 abr. 2020
 *      Author: ziash
 */

#include <logic/bean/motion/Header.h>

Header::Header() {
	this->motionName 		= "";
	this->position 			= 0;
	this->motionFrameLenght = 0;
	this->loopBeginFrame 	= 0;
	this->loopEndFrame 		= 0;
	this->loopCount 		= 0;
	this->jumpSlot 			= 0;
	this->extra 			= false;
	this->jump 				= false;
	this->loop 				= false;
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
	this->motionName 		= motionName;
	this->position 			= position;
	this->motionFrameLenght = motionFrameLength;
	this->loopBeginFrame 	= loopBeginFrame;
	this->loopEndFrame 		= loopEndFrame;
	this->loopCount 		= loopCount;
	this->jumpSlot 			= jumpSlot;
	this->extra 			= extra;
	this->jump 				= jump;
	this->loop 				= loop;
}

char* Header::getMotionName(){
	return this->motionName;
}

unsigned int Header::getPosition(){
	return this->position;
}

unsigned int Header::getMotionFrameLength(){
	return this->motionFrameLenght;
}

unsigned int Header::getLoopBeginFrame(){
	return this->loopBeginFrame;
}

unsigned int Header::getLoopEndFrame(){
	return this->loopEndFrame;
}

unsigned int Header::getLoopCount(){
	return this->loopCount;
}

unsigned int Header::getJumpSlot(){
	return this->jumpSlot;
}

bool Header::useExtra(){
	return this->extra;
}

bool Header::useJump(){
	return this->jump;
}

bool Header::useLoop(){
	return this->loop;
}

void  Header::setMotionName(char* motionName){
	this->motionName = motionName;
}
void Header::setPosition(unsigned int position){
	this->position = position;
}

void Header::setMotionFrameLength(unsigned int motionFrameLenght){
	this->motionFrameLenght = motionFrameLenght;
}

void Header::setLoopBeginFrame(unsigned int loopBeginFrame){
	this->loopBeginFrame = loopBeginFrame;
}

void Header::setLoopEndFrame(unsigned int loopEndFrame){
	this->loopEndFrame = loopEndFrame;
}

void Header::setLoopCount(unsigned int loopCount){
	this->loopCount = loopCount;
}

void Header::setJumpSlot(unsigned int jumpSlot){
	this->jumpSlot = jumpSlot;
}

void Header::setExtra(bool extra){
	this->extra = extra;
}

void Header::setJump(bool jump){
	this->jump = jump;
}

void Header::setLoop(bool loop){
	this->loop = loop;
}
