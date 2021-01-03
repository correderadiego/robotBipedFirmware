/*
 * Header.h
 *
 *  Created on: 5 abr. 2020
 *      Author: Diego
 */

#ifndef SRC_BEAN_MOTION_HEADER_H_
#define SRC_BEAN_MOTION_HEADER_H_

#include "string.h"

#define HEADER_MOTION_NAME_SIZE 20

class Header {
public:
	struct HeaderMemory{
		unsigned int position;
		unsigned int motionFrameLenght;
		unsigned int loopBeginFrame;
		unsigned int loopEndFrame;
		unsigned int loopCount;
		unsigned int jumpPosition;
		bool extra;
		bool jump;
		bool loop;
		char motionName[HEADER_MOTION_NAME_SIZE + 1];
	};

	Header();
	Header(
			char* motionName,
			unsigned int position,
			unsigned int motionFrameLenght,
			unsigned int loopBeginFrame,
			unsigned int loopEndFrame,
			unsigned int loopCount,
			unsigned int jumpPosition,
			bool extra,
			bool jump,
			bool loop
			);
	~Header();

	HeaderMemory* getHeaderMemory();
	char* getMotionName();
	unsigned int getPosition();
	unsigned int getMotionFrameLength();
	unsigned int getLoopBeginFrame();
	unsigned int getLoopEndFrame();
	unsigned int getLoopCount();
	unsigned int getJumpPosition();

	bool useExtra();
	bool useJump();
	bool useLoop();

	void setMotionName(char* motionName);
	void setPosition(unsigned int);
	void setMotionFrameLength(unsigned int);
	void setLoopBeginFrame(unsigned int);
	void setLoopEndFrame(unsigned int);
	void setLoopCount(unsigned int);
	void setJumpSlot(unsigned int);

	void setExtra(bool extra);
	void setJump(bool jump);
	void setLoop(bool loop);

private:
	HeaderMemory* headerMemory;
};

#endif /* SRC_BEAN_MOTION_HEADER_H_ */
